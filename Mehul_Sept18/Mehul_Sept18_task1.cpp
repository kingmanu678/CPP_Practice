#include <iostream>

class VehicleStatus {
    int num_wheels;
    float* wheel_speed;   // dynamic array for wheel speeds
    int num_temps;
    float* engine_temp;   // dynamic array for engine temperatures

public:
    // constructor: allocate memory and copy values
    VehicleStatus(int wheels, const float* speeds, int temps, const float* readings) {
        num_wheels = wheels;
        num_temps = temps;

        wheel_speed = new float[num_wheels];
        for (int i = 0; i < num_wheels; i++) {
            wheel_speed[i] = speeds[i];
        }

        engine_temp = new float[num_temps];
        for (int i = 0; i < num_temps; i++) {
            engine_temp[i] = readings[i];
        }
    }

    // destructor: free memory
    ~VehicleStatus() {
        delete[] wheel_speed;
        delete[] engine_temp;
    }

    // average wheel speed
    float averageWheelSpeed() const {
        float sum = 0;
        for (int i = 0; i < num_wheels; i++) sum += wheel_speed[i];
        return sum / num_wheels;
    }

    // maximum engine temp
    float maxEngineTemp() const {
        float maxT = engine_temp[0];
        for (int i = 1; i < num_temps; i++) {
            if (engine_temp[i] > maxT) maxT = engine_temp[i];
        }
        return maxT;
    }

    // compare max wheel speed with another vehicle
    bool isWheelSpeedHigher(const VehicleStatus& other) const {
        float myMax = wheel_speed[0];
        for (int i = 1; i < num_wheels; i++) if (wheel_speed[i] > myMax) myMax = wheel_speed[i];

        float otherMax = other.wheel_speed[0];
        for (int i = 1; i < other.num_wheels; i++) if (other.wheel_speed[i] > otherMax) otherMax = other.wheel_speed[i];

        return myMax > otherMax;
    }

    // print details
    void print() const {
        std::cout << "Wheel Speeds: ";
        for (int i = 0; i < num_wheels; i++) std::cout << wheel_speed[i] << " ";
        std::cout << "| Engine Temps: ";
        for (int i = 0; i < num_temps; i++) std::cout << engine_temp[i] << " ";
        std::cout << std::endl;
    }
};

// global helpers
void printVehicleStatus(const VehicleStatus& vs) {
    vs.print();
}

bool compareWheelSpeedGlobal(const VehicleStatus& v1, const VehicleStatus& v2) {
    return v1.isWheelSpeedHigher(v2);
}

int main() {
    float ws1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    float et1[] = {90.5f, 88.9f};
    VehicleStatus v1(4, ws1, 2, et1);

    float ws2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float et2[] = {92.0f, 89.5f};
    VehicleStatus v2(4, ws2, 2, et2);

    printVehicleStatus(v1);
    printVehicleStatus(v2);

    std::cout << "Compare using member: " << (v1.isWheelSpeedHigher(v2) ? "V1 faster" : "V2 faster") << std::endl;
    std::cout << "Compare using global: " << (compareWheelSpeedGlobal(v1, v2) ? "V1 faster" : "V2 faster") << std::endl;

    return 0;
}
