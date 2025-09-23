#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <iomanip>

// Roll
int rollDice() {
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    return die1 + die2;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed

    const int num_games = 1000;
    std::array<int, 21> wins{}; // WinStats
    std::array<int, 21> losses{}; // LossStats
    int total_wins = 0;
    int total_losses = 0;
    long long total_rolls = 0;

    // Simulate
    for (int i = 0; i < num_games; ++i) {
        int roll_count = 1;
        int sum = rollDice();
        int my_point = 0;

        enum class Status { CONTINUE, WON, LOST };
        Status game_status;

        // FirstRoll
        switch (sum) {
            case 7:
            case 11:
                game_status = Status::WON;
                break;
            case 2:
            case 3:
            case 12:
                game_status = Status::LOST;
                break;
            default:
                game_status = Status::CONTINUE;
                my_point = sum;
                break;
        }

        // Continue
        while (game_status == Status::CONTINUE) {
            roll_count++;
            sum = rollDice();
            if (sum == my_point) {
                game_status = Status::WON;
            } else if (sum == 7) {
                game_status = Status::LOST;
            }
        }

        total_rolls += roll_count;

        // Record
        if (game_status == Status::WON) {
            total_wins++;
            if (roll_count <= 20) {
                wins[roll_count - 1]++;
            } else {
                wins[20]++;
            }
        } else {
            total_losses++;
            if (roll_count <= 20) {
                losses[roll_count - 1]++;
            } else {
                losses[20]++;
            }
        }
    }

    // Results
    std::cout << "a) Games won on each roll:" << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cout << "   Won on roll " << std::setw(2) << i + 1 << ": " << wins[i] << std::endl;
    }
    std::cout << "   Won after roll 20: " << wins[20] << std::endl;

    std::cout << "\nb) Games lost on each roll:" << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cout << "   Lost on roll " << std::setw(2) << i + 1 << ": " << losses[i] << std::endl;
    }
    std::cout << "   Lost after roll 20: " << losses[20] << std::endl;

    std::cout << "\nc) Chances of winning at craps:" << std::endl;
    double win_percentage = (static_cast<double>(total_wins) / num_games) * 100.0;
    std::cout << "   Total wins: " << total_wins << " / " << num_games << " (" << std::fixed << std::setprecision(2) << win_percentage << "%)" << std::endl;
    std::cout << "   [Note: This means that for every 100 games, you are likely to win about " << static_cast<int>(win_percentage) << " games. It's close to a 50/50 chance, making it one of the fairer casino games.]" << std::endl;


    std::cout << "\nd) Average length of a game of craps:" << std::endl;
    double avg_length = static_cast<double>(total_rolls) / num_games;
    std::cout << "   Average game length: " << std::fixed << std::setprecision(2) << avg_length << " rolls" << std::endl;

    std::cout << "\ne) Do the chances of winning improve with the length of the game?" << std::endl;
    std::cout << "   Analysis of win/loss ratio for games of different lengths:" << std::endl;
    for (int i = 0; i < 20; ++i) {
        int total_games_for_roll = wins[i] + losses[i];
        if (total_games_for_roll > 0) {
            double win_chance = (static_cast<double>(wins[i]) / total_games_for_roll) * 100.0;
            std::cout << "   Roll " << std::setw(2) << i + 1 << ": " << std::fixed << std::setprecision(2) << win_chance << "% chance of winning for games ending on this roll." << std::endl;
        }
    }
    int total_games_after_20 = wins[20] + losses[20];
    if (total_games_after_20 > 0) {
        double win_chance_after_20 = (static_cast<double>(wins[20]) / total_games_after_20) * 100.0;
        std::cout << "   After roll 20: " << std::fixed << std::setprecision(2) << win_chance_after_20 << "% chance of winning for games ending after the 20th roll." << std::endl;
    }
    std::cout << "   [Note: The probability of winning changes depending on the 'point' established. The overall chance of winning in craps is approximately 49.29%. The chances don't necessarily 'improve' with the length of the game in a way that gives the player an advantage over time; the odds are fixed based on the dice probabilities.]" << std::endl;


    return 0;
}