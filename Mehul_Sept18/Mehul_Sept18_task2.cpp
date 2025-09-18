#include <iostream>
#include <cstdint>

// Holds all sensor data for a vehicle.
class EgoVehicleData {
private:
    int num_lanes;
    float* lane_positions;
    float* sensor_confidence;

public:
    // Constructor
    EgoVehicleData(int n, const float* lanes, const float* conf) {
        num_lanes = n;
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; i++) {
            lane_positions[i] = lanes[i];
            sensor_confidence[i] = conf[i];
        }
    }

    // Destructor (frees memory)
    ~EgoVehicleData() {
        delete[] lane_positions;
        delete[] sensor_confidence;
    }

    // Copy Constructor (for safe copying)
    EgoVehicleData(const EgoVehicleData& other) {
        num_lanes = other.num_lanes;
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; i++) {
            lane_positions[i] = other.lane_positions[i];
            sensor_confidence[i] = other.sensor_confidence[i];
        }
    }

    // Calculates sum of confidence scores.
    float sumConfidence() const {
        float sum = 0;
        for (int i = 0; i < num_lanes; i++) sum += sensor_confidence[i];
        return sum;
    }

    // Prints all data.
    void print() const {
        std::cout << "Lane Positions: ";
        for (int i = 0; i < num_lanes; i++) std::cout << lane_positions[i] << " ";
        std::cout << "| Conf: ";
        for (int i = 0; i < num_lanes; i++) std::cout << sensor_confidence[i] << " ";
        std::cout << std::endl;
    }
};

// Finds the vehicle with the highest confidence.
void findHighestConfidenceVehicle(EgoVehicleData* arr, int size, const EgoVehicleData*& highest) {
    highest = nullptr;
    float maxSum = -1.0f;
    for (int i = 0; i < size; i++) {
        float sum = arr[i].sumConfidence();
        if (sum > maxSum) {
            maxSum = sum;
            highest = &arr[i];
        }
    }
}

// Main Function
int main() {
    // Create three vehicle objects.
    float lp1[] = {3.2f, 3.0f, 3.4f};
    float sc1[] = {0.95f, 0.97f, 0.93f};
    EgoVehicleData v1(3, lp1, sc1);

    float lp2[] = {2.9f, 2.8f, 3.1f};
    float sc2[] = {0.92f, 0.90f, 0.88f};
    EgoVehicleData v2(3, lp2, sc2);

    float lp3[] = {3.4f, 3.5f, 3.6f};
    float sc3[] = {0.99f, 0.98f, 0.97f};
    EgoVehicleData v3(3, lp3, sc3);

    // Create an array from the objects.
    EgoVehicleData vehicles[] = {v1, v2, v3};

    // Find and print the best vehicle.
    const EgoVehicleData* best = nullptr;
    findHighestConfidenceVehicle(vehicles, 3, best);
    std::cout << "Highest confidence vehicle:" << std::endl;
    if (best) best->print();

    return 0;
}