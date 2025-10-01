#include "Mehul_Oct1_task2_BatteryMonitor.h"

// Init
BatteryMonitor::BatteryMonitor(const std::string& id, int cycles,
                               float currentCap, float originalCap,
                               bool active, int trips)
    : scooterID(id), chargeCycles(cycles), batteryCapacity(currentCap),
      originalCapacity(originalCap), isActive(active), tripCount(trips) {
    tripDistances = new int[tripCount]; // allocate memory
    for (int i = 0; i < tripCount; ++i) {
        tripDistances[i] = 0; // initialize trips
    }
}

// Deep copy
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other)
    : scooterID(other.scooterID), chargeCycles(other.chargeCycles),
      batteryCapacity(other.batteryCapacity),
      originalCapacity(other.originalCapacity),
      isActive(other.isActive), tripCount(other.tripCount) {
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; ++i) {
        tripDistances[i] = other.tripDistances[i];
    }
}

// Assignment
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& other) {
    if (this != &other) { // self check
        delete[] tripDistances; // cleanup old memory

        scooterID = other.scooterID;
        chargeCycles = other.chargeCycles;
        batteryCapacity = other.batteryCapacity;
        originalCapacity = other.originalCapacity;
        isActive = other.isActive;
        tripCount = other.tripCount;

        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; ++i) {
            tripDistances[i] = other.tripDistances[i];
        }
    }
    return *this;
}

// Cleanup
BatteryMonitor::~BatteryMonitor() {
    delete[] tripDistances;
}

// Compare health
bool BatteryMonitor::operator>(const BatteryMonitor& other) const {
    return (batteryCapacity / originalCapacity) >
           (other.batteryCapacity / other.originalCapacity);
}

bool BatteryMonitor::operator<(const BatteryMonitor& other) const {
    return (batteryCapacity / originalCapacity) <
           (other.batteryCapacity / other.originalCapacity);
}

// Degrade battery
BatteryMonitor& BatteryMonitor::operator+=(int extraCycles) {
    chargeCycles += extraCycles;
    batteryCapacity -= (extraCycles * 0.01f); // degrade 0.01 kWh per cycle
    if (batteryCapacity < 0) batteryCapacity = 0;
    return *this;
}

// Trip access
int& BatteryMonitor::operator[](int index) {
    if (index < 0 || index >= tripCount) {
        throw std::out_of_range("Invalid trip index");
    }
    return tripDistances[index];
}

// Check status
bool BatteryMonitor::operator!() const {
    return !isActive;
}

// Print info
std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm) {
    float health = (bm.originalCapacity > 0)
                   ? (bm.batteryCapacity / bm.originalCapacity) * 100.0f
                   : 0.0f;
    os << "Scooter ID: " << bm.scooterID
       << " | Cycles: " << bm.chargeCycles
       << " | Capacity: " << bm.batteryCapacity << " kWh"
       << " | Health: " << health << "%"
       << " | Status: " << (bm.isActive ? "Active" : "Inactive")
       << " | Trips: [";
    for (int i = 0; i < bm.tripCount; ++i) {
        os << bm.tripDistances[i];
        if (i != bm.tripCount - 1) os << ", ";
    }
    os << "]";
    return os;
}
