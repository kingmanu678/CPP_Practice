#include "Mehul_Oct1_task1_HybridVehicle.h"

// Init
HybridVehicle::HybridVehicle(const std::string& name, float eKm, float gKm, float gUsed)
    : modelName(name), electricKm(eKm), gasolineKm(gKm), gasolineUsed(gUsed), tripCount(0) {
    for (int i = 0; i < 10; ++i) {
        trips[i] = 0;
    }
}

// Deep copy
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& other) {
    if (this != &other) {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;
        for (int i = 0; i < 10; ++i) {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}

// Combine vehicles
HybridVehicle HybridVehicle::operator+(const HybridVehicle& other) const {
    HybridVehicle result("Combined",
                         electricKm + other.electricKm,
                         gasolineKm + other.gasolineKm,
                         gasolineUsed + other.gasolineUsed);
    // combine trips up to 10
    int limit = (tripCount < 10) ? tripCount : 10;
    for (int i = 0; i < limit; ++i) {
        result.trips[i] = trips[i];
    }
    result.tripCount = tripCount;
    return result;
}

// Compare efficiency
bool HybridVehicle::operator==(const HybridVehicle& other) const {
    float eff1 = gasolineUsed > 0.0F ? (gasolineKm / gasolineUsed) : 0.0F;
    float eff2 = other.gasolineUsed > 0.0F ? (other.gasolineKm / other.gasolineUsed) : 0.0F;
    return eff1 == eff2;
}

// New trip
HybridVehicle& HybridVehicle::operator++() {
    if (tripCount < 10) {
        trips[tripCount++] = 10; // dummy trip of 10 km
    }
    return *this;
}

// Trip access
int& HybridVehicle::operator[](int index) {
    if (index >= 0 && index < 10) {
        if (index >= tripCount) {
            tripCount = index + 1;
        }
        return trips[index];
    }
    static int dummy = -1;
    return dummy;
}

// Total distance
float HybridVehicle::operator()() const {
    return electricKm + gasolineKm;
}

// Efficiency
HybridVehicle::operator float() const {
    return (gasolineUsed > 0.0F) ? (gasolineKm / gasolineUsed) : 0.0F;
}

// Print details
std::ostream& operator<<(std::ostream& os, const HybridVehicle& hv) {
    os << "Model: " << hv.modelName
       << ", ElectricKm: " << hv.electricKm
       << ", GasolineKm: " << hv.gasolineKm
       << ", GasolineUsed: " << hv.gasolineUsed
       << ", Trips: " << hv.tripCount;
    return os;
}
