#include <iostream>


enum SatelliteStatus { OPERATIONAL, MAINTENANCE, DECOMMISSIONED }; //enum

const char* statusToString(SatelliteStatus s) {
    if (s == OPERATIONAL) return "Operational";
    if (s == MAINTENANCE) return "Maintenance";
    return "Decommissioned";
} //enum defined

//class
class SatelliteData {
    
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;

    static int active_satellites;

public:
    //constructor
    SatelliteData(int id, int n, const float* signals, float alt, SatelliteStatus st) {
        satellite_id = id;
        num_antennas = n;
        orbital_altitude = alt;
        status = st;

        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) signal_strength[i] = signals[i];

        active_satellites++;
    }

    // copy constructor
    SatelliteData(const SatelliteData& other) {
        satellite_id = other.satellite_id;
        num_antennas = other.num_antennas;
        orbital_altitude = other.orbital_altitude;
        status = other.status;

        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) signal_strength[i] = other.signal_strength[i];

        active_satellites++;
    }
    //destructor
    ~SatelliteData() {
        delete[] signal_strength;
        active_satellites--;
    }

    float getAverageSignalStrength() const {
        float sum = 0;
        for (int i = 0; i < num_antennas; i++) sum += signal_strength[i];
        return sum / num_antennas;
    }

    void boostSignal(float factor) {
        for (int i = 0; i < num_antennas; i++) signal_strength[i] *= factor;
    }

    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < num_antennas; i++) {
            if (signal_strength[i] < threshold) signal_strength[i] *= factor;
        }
    }

    static int getActiveSatelliteCount() {
        return active_satellites;
    }
    //set
    void setStatus(SatelliteStatus new_status) {
        status = new_status;
    }
    //get 
    const char* getStatusString() const {
        return statusToString(status);
    }

    void print() const {
        std::cout << "Satellite " << satellite_id
             << " Altitude: " << orbital_altitude
             << " Status: " << getStatusString()
             << " Signals: ";
        for (int i = 0; i < num_antennas; i++) std::cout << signal_strength[i] << " ";
        std::cout << std::endl;
    }
};

int SatelliteData::active_satellites = 0;
//global functions
void printSatelliteData(const SatelliteData& sd) {
    sd.print();
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.getAverageSignalStrength() > s2.getAverageSignalStrength();
}

void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source);
}

void printActiveSatelliteCount() {
    std::cout << "Active satellites: " << SatelliteData::getActiveSatelliteCount() << std::endl;
}

void updateStatusIfWeak(SatelliteData& sd, float threshold) {
    if (sd.getAverageSignalStrength() < threshold) {
        sd.setStatus(MAINTENANCE);
    }
}

int main() {
    float s1Signals[] = {78.5f, 80.2f, 79.0f};
    SatelliteData sat1(101, 3, s1Signals, 550.0f, OPERATIONAL);

    float s2Signals[] = {75.0f, 76.5f};
    SatelliteData sat2(102, 2, s2Signals, 600.0f, MAINTENANCE);

    sat1.boostSignal(1.1f);
    sat2.boostSignal(1.2f, 76.0f);

    printSatelliteData(sat1);
    printSatelliteData(sat2);

    SatelliteData* clone = nullptr;
    cloneSatellite(sat1, clone);
    printSatelliteData(*clone);

    updateStatusIfWeak(sat2, 77.0f);
    printSatelliteData(sat2);

    printActiveSatelliteCount();

    delete clone;   //clearing memory

    return 0;
}
