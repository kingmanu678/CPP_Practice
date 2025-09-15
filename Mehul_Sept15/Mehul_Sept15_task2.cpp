#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Enum for book genres
enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };

// Helper to convert enum to string
string genreToString(Genre g) {
    switch (g) {
        case FICTION: return "Fiction";
        case NONFICTION: return "Non-Fiction";
        case SCIENCE: return "Science";
        case HISTORY: return "History";
        case TECHNOLOGY: return "Technology";
        default: return "Unknown";
    }
}

class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;  // 'A' or 'B'
    bool isReferenceOnly;
    string title;
    Genre genre;

public:
    // Default Constructor
    Book()
        : bookID(0), rating(0.0), price(0.0), availabilityStatus('A'),
          isReferenceOnly(false), title("Untitled"), genre(FICTION) {}

    // Parameterized Constructor
    Book(int id, float r, double p, char status, bool ref, string t, Genre g)
        : bookID(id), rating(r), price(p), availabilityStatus(status),
          isReferenceOnly(ref), title(t), genre(g) {}

    // Destructor
    ~Book() {
        cout << "Book object with ID " << bookID << " destroyed." << endl;
    }

    // Getters
    int getBookID() const { return bookID; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getAvailabilityStatus() const { return availabilityStatus; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    string getTitle() const { return title; }
    Genre getGenre() const { return genre; }

    // Setters
    void setBookID(int id) { bookID = id; }
    void setRating(float r) { rating = r; }
    void setPrice(double p) { price = p; }
    void setAvailabilityStatus(char status) { availabilityStatus = status; }
    void setIsReferenceOnly(bool ref) { isReferenceOnly = ref; }
    void setTitle(const string& t) { title = t; }
    void setGenre(Genre g) { genre = g; }

    // Update availability
    void updateAvailability(bool isBorrowed) {
        availabilityStatus = (isBorrowed ? 'B' : 'A');
    }

    // Display book details
    void displayDetails() const {
        cout << "\n Book Details" << endl;
        cout << "ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Rating: " << rating << endl;
        cout << "Availability: " << (availabilityStatus == 'A' ? "Available" : "Borrowed") << endl;
        cout << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << endl;
        cout << "Genre: " << genreToString(genre) << endl;
    }
};

//Global Functions 
void markAsReference(Book &book) {
    book.setIsReferenceOnly(true);   // mark it as reference
    if (book.getIsReferenceOnly())   // check back using getter
        cout << "Book \"" << book.getTitle() << "\" is now marked as Reference Only.\n";
}


bool isAffordable(const Book &book, const double budget) {
    return book.getPrice() <= budget;
}

void printFormattedBookList(const Book books[], const int size) {
    cout << left << setw(6) << "ID"
         << setw(20) << "Title"
         << setw(10) << "Price"
         << setw(8) << "Rating"
         << setw(10) << "Status"
         << setw(12) << "Reference"
         << setw(15) << "Genre" << endl;

    cout << string(70, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(6) << books[i].getBookID()
             << setw(20) << books[i].getTitle()
             << setw(10) << books[i].getPrice()
             << setw(8) << books[i].getRating()
             << setw(10) << (books[i].getAvailabilityStatus() == 'A' ? "Available" : "Borrowed")
             << setw(12) << (books[i].getIsReferenceOnly() ? "Yes" : "No")
             << setw(15) << genreToString(books[i].getGenre())
             << endl;
    }
}

// Main Function 
int main() {
    Book books[3]; // Array of 3 books
    int choice, index;

    do {
        cout << "\n Library Menu" << endl;
        cout << "1. Add book details\n";
        cout << "2. Mark book as reference-only\n";
        cout << "3. Check if a book is affordable\n";
        cout << "4. Update availability\n";
        cout << "5. Display book details\n";
        cout << "6. Display all books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter index (0-2): ";
            cin >> index;
            if (index < 0 || index >= 3) {
                cout << "Invalid index!\n";
                continue;
            }

            int id; float r; double p; char status; bool ref; string title; int g;
            cout << "Enter Book ID: "; cin >> id;
            cout << "Enter Rating (0.0 - 5.0): "; cin >> r;
            while (r < 0.0 || r > 5.0) {
                cout << "Invalid rating! Enter again: ";
                cin >> r;
            }
            cout << "Enter Price: "; cin >> p;
            while (p <= 0) {
                cout << "Price must be positive! Enter again: ";
                cin >> p;
            }
            cout << "Enter Status (A = Available, B = Borrowed): "; cin >> status;
            cout << "Is Reference Only? (1 = Yes, 0 = No): "; cin >> ref;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            while (title.empty()) {
                cout << "Title cannot be empty! Enter again: ";
                getline(cin, title);
            }
            cout << "Enter Genre (0=FICTION, 1=NONFICTION, 2=SCIENCE, 3=HISTORY, 4=TECHNOLOGY): ";
            cin >> g;
            while (g < 0 || g > 4) {
                cout << "Invalid genre! Enter again: ";
                cin >> g;
            }

            books[index] = Book(id, r, p, status, ref, title, static_cast<Genre>(g));
            cout << "Book added successfully!\n";
        }
        else if (choice == 2) {
            cout << "Enter index (0-2): ";
            cin >> index;
            markAsReference(books[index]);
        }
        else if (choice == 3) {
            cout << "Enter index (0-2): ";
            cin >> index;
            double budget;
            cout << "Enter your budget: ";
            cin >> budget;
            if (isAffordable(books[index], budget))
                cout << "The book is affordable!\n";
            else
                cout << "The book is NOT affordable!\n";
        }
        else if (choice == 4) {
            cout << "Enter index (0-2): ";
            cin >> index;
            bool borrow;
            cout << "Enter 1 for Borrow, 0 for Return: ";
            cin >> borrow;
            books[index].updateAvailability(borrow);
            cout << "Availability updated!\n";
        }
        else if (choice == 5) {
            cout << "Enter index (0-2): ";
            cin >> index;
            books[index].displayDetails();
        }
        else if (choice == 6) {
            printFormattedBookList(books, 3);
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

