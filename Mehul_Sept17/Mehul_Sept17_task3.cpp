#include <iostream>
#include<cstdint>


class DetectedObject {
private:
    uint32_t object_id;   // unique id
    float rel_speed;      // relative speed w.r.t ego vehicle
    float distance;       // distance from ego vehicle

public:
    // constructor
    DetectedObject(uint32_t id, float speed, float dist) {
        object_id = id;
        rel_speed = speed;
        distance = dist;
    }

    // show object details
    void display() const {
        std::cout << "Object ID: " << object_id
             << ", RelSpeed: " << rel_speed
             << ", Distance: " << distance << std::endl;
    }

    // check if this object is higher risk than another
    bool isHigherRisk(const DetectedObject& other) const {
        return (this->distance < other.distance) &&
               (this->rel_speed > other.rel_speed);
    }

    // update by value (works on copy only)
    void updateValuesByValue(DetectedObject obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
        std::cout << "Inside updateValuesByValue (copy modified): ";
        obj.display();
    }

    // update by reference (changes the real object)
    void updateValuesByReference(DetectedObject& obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    // getters
    uint32_t getID() const { return object_id; }
    float getRelSpeed() const { return rel_speed; }
    float getDistance() const { return distance; }
};

// find the highest risk object
void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj) {
    if (arr == nullptr || size == 0) {
        riskObj = nullptr;
        return;
    }

    riskObj = &arr[0];
    for (uint32_t i = 1; i < size; i++) {
        if (arr[i].isHigherRisk(*riskObj)) {
            riskObj = &arr[i];
        }
    }
}

// global helpers
void printDetectedObject(const DetectedObject& obj) {
    obj.display();
}

void printHighestRiskObject(const DetectedObject* obj) {
    if (obj == nullptr) {
        std::cout << "No high-risk object found" << std::endl;
    } else {
        std::cout << "Highest Risk Object -> "
             << "ID: " << obj->getID()
             << ", RelSpeed: " << obj->getRelSpeed()
             << ", Distance: " << obj->getDistance() << std::endl;
    }
}

void updateObjectValuesByValueGlobal(DetectedObject obj) {
    obj.updateValuesByValue(obj);
}

void updateObjectValuesByReferenceGlobal(DetectedObject& obj) {
    obj.updateValuesByReference(obj);
}

// main
int main() {
    uint32_t size = 3;

    // allocate objects on heap
    DetectedObject* arr = new DetectedObject[size] {
        DetectedObject(701, 15, 55),
        DetectedObject(702, 20, 35),
        DetectedObject(703, 10, 30)
    };

    // print initial state
    std::cout << "Initial Objects:" << std::endl;
    for (uint32_t i = 0; i < size; i++) {
        printDetectedObject(arr[i]);
    }
    std::cout << std::endl;

    // try updating by value (no effect outside)
    std::cout << "Updating Object 1 by Value:" << std::endl;
    updateObjectValuesByValueGlobal(arr[0]);
    std::cout << "After call (original unchanged): ";
    printDetectedObject(arr[0]);
    std::cout << std::endl;

    // try updating by reference (real change)
    std::cout << "Updating Object 2 by Reference:" << std::endl;
    updateObjectValuesByReferenceGlobal(arr[1]);
    std::cout << "After call (original changed): ";
    printDetectedObject(arr[1]);
    std::cout << std::endl;

    // find highest risk object
    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(arr, size, riskObj);
    printHighestRiskObject(riskObj);

    // free memory
    delete[] arr;

    return 0;
}
