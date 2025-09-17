#include <iostream>
using namespace std;

// Three types of sensors in the car
enum SensorType { LIDAR, RADAR, CAMERA };

// A helper to print sensor type as words
const char* sensorTypeToString(SensorType t) {
    if (t == LIDAR) return "LIDAR";
    if (t == RADAR) return "RADAR";
    if (t == CAMERA) return "CAMERA";
    return "UNKNOWN";
}

class SensorArray {
    int sensor_id;            // unique number for each sensor
    SensorType type;          // what kind of sensor it is
    double* readings;         // temperature readings (dynamic array)
    int count;                // how many readings we have

    // one shared value for the hottest temperature seen so far
    static double global_max_temp;

public:
    // constructor: give sensor its ID, type, and readings
    SensorArray(int id, SensorType t, const double* arr, int n) {
        sensor_id = id;
        type = t;
        count = n;

        // make space for the readings
        readings = new double[count];
        for (int i = 0; i < count; i++) {
            readings[i] = arr[i];
            // if this reading is hotter than the global record, update it
            if (readings[i] > global_max_temp) {
                global_max_temp = readings[i];
            }
        }
    }

    // destructor: free the space we took
    ~SensorArray() {
        delete[] readings;
    }

    // get the hottest temperature for THIS sensor only
    double getMaxTemperature() const {
        double local_max = readings[0];
        for (int i = 1; i < count; i++) {
            if (readings[i] > local_max) local_max = readings[i];
        }
        return local_max;
    }

    // show info about this sensor
    void printSensorInfo() const {
        cout << "Sensor " << sensor_id
             << " (" << sensorTypeToString(type) << ")"
             << " Max Temp = " << getMaxTemperature() << endl;
    }

    // ask: what is the hottest temp across ALL sensors?
    static double getGlobalMaxTemperature() {
        return global_max_temp;
    }
};

// start with a very low value so any real temp will be bigger
double SensorArray::global_max_temp = -1e9;

// function to print one sensor
void printSensor(const SensorArray& s) {
    s.printSensorInfo();
}

// function to print all sensors
void printAllSensors(const SensorArray* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].printSensorInfo();
    }
}

int main() {
    // temperatures from the problem
    double lidarTemps[]  = {35.5, 36.1, 34.9};
    double radarTemps[]  = {39.0, 38.7, 39.3};
    double cameraTemps[] = {30.2, 31.0, 30.5};

    int size = 3;

    // create sensors on the heap
    SensorArray* sensors = new SensorArray[size] {
        SensorArray(801, LIDAR,  lidarTemps, 3),
        SensorArray(802, RADAR,  radarTemps, 3),
        SensorArray(803, CAMERA, cameraTemps, 3)
    };

    cout << "Sensor Info" << endl;
    printAllSensors(sensors, size);

    cout << endl << "Global Max Temp = "
         << SensorArray::getGlobalMaxTemperature() << endl;

    // clean up
    delete[] sensors;
    return 0;
}
