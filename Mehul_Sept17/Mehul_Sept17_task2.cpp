
#include <iostream>
#include <limits>
#include<cstdint>


class TrackedVehicle {
private:
    uint32_t vehicle_id;   // id of the vehicle
    float speed;           // current speed
    float distance;        // distance from ego vehicle

    static float min_recorded_distance; // smallest distance seen so far
    static int vehicle_count;           // how many vehicles created

public:
    // constructor
    TrackedVehicle(uint32_t id, float spd, float dist) {
        vehicle_id = id;
        speed = spd;
        distance = dist;

        vehicle_count++; // every time we make a vehicle, count it

        // check if this distance is the smallest one so far
        if (dist < min_recorded_distance) {
            min_recorded_distance = dist;
        }
    }

    // show vehicle info
    void display() const {
        std::cout << "Vehicle ID: " << vehicle_id
             << ", Speed: " << speed << " km/h"
             << ", Distance: " << distance << " m" << std::endl;
    }

    // decide which vehicle is closer
    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const {
        if (distance < other.distance) {
            return this;
        } else if (other.distance < distance) {
            return &other;
        } else {
            return this; // equal -> just return this one
        }
    }

    // static helpers
    static float getMinRecordedDistance() {
        return min_recorded_distance;
    }

    static int getVehicleCount() {
        return vehicle_count;
    }

    // getters
    float getDistance() const { return distance; }
    uint32_t getID() const { return vehicle_id; }
    float getSpeed() const { return speed; }
};

// set static variables
float TrackedVehicle::min_recorded_distance = std::numeric_limits<float>::max();
int TrackedVehicle::vehicle_count = 0;

// pick the lead vehicle (closest one)
void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead) {
    if (arr == nullptr || size == 0) {
        lead = nullptr;
        return;
    }

    lead = &arr[0]; // start with first one
    for (uint32_t i = 1; i < size; i++) {
        lead = lead->compareDistance(arr[i]);
    }
}

// print one vehicle
void printTrackedVehicle(const TrackedVehicle& vehicle) {
    vehicle.display();
}

// print the lead vehicle
void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead == nullptr) {
        std::cout << "Lead Vehicle: None found" << std::endl;
    } else {
        std::cout << "Lead Vehicle -> "
             << "ID: " << lead->getID()
             << ", Speed: " << lead->getSpeed() << " km/h"
             << ", Distance: " << lead->getDistance() << " m" << std::endl;
    }
}

int main() {
    // make 4 vehicles on heap
    int size = 4;
    TrackedVehicle* vehicles = new TrackedVehicle[size] {
        TrackedVehicle(501, 80.0f, 60.0f),
        TrackedVehicle(502, 78.0f, 45.0f),
        TrackedVehicle(503, 85.0f, 100.0f),
        TrackedVehicle(504, 76.0f, 40.0f)
    };

    // find the closest one
    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, size, lead);

    // print all vehicles
    std::cout << "All Vehicles:" << std::endl;
    for (uint32_t i = 0; i < size; i++) {
        printTrackedVehicle(vehicles[i]);
    }
    std::cout << std::endl;

    // print the lead one
    printLeadVehicle(lead);
    std::cout << std::endl;

    // show stats
    std::cout << "Minimum Recorded Distance: "
         << TrackedVehicle::getMinRecordedDistance() << " m" << std::endl;

    std::cout << "Total Tracked Vehicles Created: "
         << TrackedVehicle::getVehicleCount() << std::endl;

    // free memory
    delete[] vehicles;

    return 0;
}
