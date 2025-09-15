#include <iostream>
#include <string>
using namespace std;

//Base Class
class Sensor {
    int id;
    float value;
    int priority;
    string status;
public:
//Constructor
    Sensor(int i, float v, int p) : id(i), value(v), priority(p), status("OK") {}
    void updateValue(float v) { value = v; }
    int getId() { return id; }
    float getValue() { return value; }
    int getPriority() { return priority; }
    string getStatus() { return status; }
    void setStatus(string s) { status = s; }
};

//sensor diagnostics class
class SensorDiagnostics {
public:
    string checkHealth(Sensor& s) {
        return (s.getValue() > 100) ? "Unhealthy" : "Healthy";
    }
};
//global functions
void rebindCriticalSensor(Sensor*& ref, Sensor* list[], int size) {
    Sensor* highest = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i]->getPriority() > highest->getPriority()) {
            highest = list[i];
        }
    }
    ref = highest;
}

void printSensorMap(Sensor* list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Sensor ID: " << list[i]->getId()
             << " Value: " << list[i]->getValue()
             << " Priority: " << list[i]->getPriority()
             << " Status: " << list[i]->getStatus() << "\n";
    }
}

//controller class
class Controller {
    Sensor* sensorList[10];
    Sensor* criticalPtr;
    int size;
public:
    Controller() : criticalPtr(nullptr), size(0) {}
    void addSensor(Sensor* s) {
        if (size < 10) sensorList[size++] = s;
    }
    void bindCriticalSensor() {
        rebindCriticalSensor(criticalPtr, sensorList, size);
    }
    void updateCriticalSensor() {
        rebindCriticalSensor(criticalPtr, sensorList, size);
    }
    void printStatus() {
        if (criticalPtr) {
            cout << "Critical Sensor -> ID: " << criticalPtr->getId()
                 << " Value: " << criticalPtr->getValue()
                 << " Priority: " << criticalPtr->getPriority() << "\n";
        }
    }
    Sensor** getSensorList() { return sensorList; }
    int getSize() { return size; }
    Sensor* getCriticalPtr() { return criticalPtr; }
};

int main() {
    Controller ctrl;
    for (int i = 0; i < 10; i++) {
        Sensor* s = new Sensor(i + 1, 50 + i * 5, (i % 5) + 1);
        ctrl.addSensor(s);
    }

    ctrl.bindCriticalSensor();
    ctrl.printStatus();

    SensorDiagnostics diag;
    cout << "Health of critical: " << diag.checkHealth(*ctrl.getCriticalPtr()) << "\n";

    ctrl.getSensorList()[3]->updateValue(120);
    ctrl.updateCriticalSensor();
    ctrl.printStatus();

    printSensorMap(ctrl.getSensorList(), ctrl.getSize());

    for (int i = 0; i < ctrl.getSize(); i++) {
        delete ctrl.getSensorList()[i];
    }
    return 0;
}
