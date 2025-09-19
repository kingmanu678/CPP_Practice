#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm> 
#include <utility>   

// ====================================================================================
// 1. ServiceRecord Class
// ====================================================================================
class ServiceRecord {
private:
    std::string date_;
    int mileage_;
    std::string description_;

public:
    // Default constructor
    ServiceRecord() : date_(""), mileage_(0), description_("") {}

    // Parameterized constructor
    ServiceRecord(const std::string& date, int mileage, const std::string& description)
        : date_(date), mileage_(mileage), description_(description) {
        if (mileage_ < 0) throw std::invalid_argument("mileage must be >= 0");
    }

   
    ServiceRecord(const ServiceRecord& other) = default;
    ServiceRecord& operator=(const ServiceRecord& other) = default;

    // Getters
    const std::string& getDate() const { return date_; }
    int getMileage() const { return mileage_; }
    const std::string& getDescription() const { return description_; }

    // to print details
    void print() const {
        std::cout << "    - Date: " << date_ << ", Mileage: " << mileage_ << ", Desc: " << description_ << '\n';
    }
};

// ====================================================================================
// 2. Car Class
// ====================================================================================
class Car {
private:
    std::string vin_;
    std::string make_;
    std::string model_;
    double price_;

    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;

    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;

    static size_t totalCars_;

   
    void reserveService(size_t newCap) {
        if (newCap <= serviceCap_) return;
        ServiceRecord* newArr = new ServiceRecord[newCap];
        
        if(serviceHistory_) {
            std::copy(serviceHistory_, serviceHistory_ + serviceCount_, newArr);
            delete[] serviceHistory_;
        }
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }

    
    void reserveDamage(size_t newCap) {
        if (newCap <= damageCap_) return;
        int* newArr = new int[newCap];
       
        if(damageCodes_) {
            std::copy(damageCodes_, damageCodes_ + damageCount_, newArr);
            delete[] damageCodes_;
        }
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }

public:
    // Default constructor
    Car()
        : vin_(""), make_(""), model_(""), price_(0.0),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        ++totalCars_;
    }

    // Parameterized constructor
    Car(const std::string& vin, const std::string& make, const std::string& model, double price)
        : vin_(vin), make_(make), model_(model), price_(price),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        if (price_ < 0.0) throw std::invalid_argument("price must be >= 0");
        ++totalCars_;
    }

    // Copy constructor
    Car(const Car& other)
        : vin_(other.vin_), make_(other.make_), model_(other.model_), price_(other.price_),
          serviceHistory_(nullptr), serviceCount_(other.serviceCount_), serviceCap_(other.serviceCap_),
          damageCodes_(nullptr), damageCount_(other.damageCount_), damageCap_(other.damageCap_) {
        if (serviceCap_ > 0) {
            serviceHistory_ = new ServiceRecord[serviceCap_];
            std::copy(other.serviceHistory_, other.serviceHistory_ + serviceCount_, serviceHistory_);
        }
        if (damageCap_ > 0) {
            damageCodes_ = new int[damageCap_];
            std::copy(other.damageCodes_, other.damageCodes_ + damageCount_, damageCodes_);
        }
        ++totalCars_;
    }

    // Destructor
    ~Car() {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        --totalCars_;
    }

    // Assignment operator
    Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }

    // Friend swap function 
    friend void swap(Car& lhs, Car& rhs) noexcept {
        using std::swap;
        swap(lhs.vin_, rhs.vin_);
        swap(lhs.make_, rhs.make_);
        swap(lhs.model_, rhs.model_);
        swap(lhs.price_, rhs.price_);
        swap(lhs.serviceHistory_, rhs.serviceHistory_);
        swap(lhs.serviceCount_, rhs.serviceCount_);
        swap(lhs.serviceCap_, rhs.serviceCap_);
        swap(lhs.damageCodes_, rhs.damageCodes_);
        swap(lhs.damageCount_, rhs.damageCount_);
        swap(lhs.damageCap_, rhs.damageCap_);
    }

    // Static getter for the total car count
    static size_t getTotalCars() { return totalCars_; }

    // Setters
    void setVIN(const std::string& vin) { vin_ = vin; }
    void setMake(const std::string& make) { make_ = make; }
    void setModel(const std::string& model) { model_ = model; }
    void setPrice(double price) { if (price < 0.0) throw std::invalid_argument("price must be >= 0"); price_ = price; }

    // Getters
    const std::string& getVIN() const { return vin_; }
    const std::string& getMake() const { return make_; }
    const std::string& getModel() const { return model_; }
    double getPrice() const { return price_; }
    size_t getServiceCount() const { return serviceCount_; }
    size_t getDamageCount() const { return damageCount_; }
    const ServiceRecord* getServiceHistory() const { return serviceHistory_; }
    const int* getDamageCodes() const { return damageCodes_; }

    // Business logic to add records
    void addService(const ServiceRecord& rec) {
        if (serviceCount_ == serviceCap_) {
            reserveService((serviceCap_ == 0) ? 2 : serviceCap_ * 2);
        }
        serviceHistory_[serviceCount_++] = rec;
    }

    void addDamageCode(int code) {
        if (damageCount_ == damageCap_) {
            reserveDamage((damageCap_ == 0) ? 4 : damageCap_ * 2);
        }
        damageCodes_[damageCount_++] = code;
    }

    // Prints car's data
    void printInfo() const {
        std::cout << "VIN: " << vin_ << " | Make: " << make_ << " | Model: " << model_
                  << " | Price: $" << std::fixed << std::setprecision(2) << price_ << '\n';
        std::cout << "  Services (" << serviceCount_ << "):\n";
        if (serviceCount_ == 0) std::cout << "    None.\n";
        for (size_t i = 0; i < serviceCount_; ++i) serviceHistory_[i].print();

        std::cout << "  Damage Codes (" << damageCount_ << "):";
        if (damageCount_ == 0) std::cout << " None.";
        for (size_t i = 0; i < damageCount_; ++i) std::cout << ' ' << damageCodes_[i];
        std::cout << "\n\n";
    }
};

// Define and initialize the static member
size_t Car::totalCars_ = 0;

// ====================================================================================
// 3. Global Functions
// ====================================================================================

// Calculate average price of cars in an array
double averagePrice(const Car* arr, size_t n) {
    if (n == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i) sum += arr[i].getPrice();
    return sum / static_cast<double>(n);
}

// Find the car with the highest price
const Car* maxPriceCar(const Car* arr, size_t n) {
    if (n == 0) return nullptr;
    const Car* maxCar = &arr[0];
    for (size_t i = 1; i < n; ++i) {
        if (arr[i].getPrice() > maxCar->getPrice()) maxCar = &arr[i];
    }
    return maxCar;
}

// Find a car by its VIN
const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin) {
    for (size_t i = 0; i < n; ++i) {
        if (arr[i].getVIN() == vin) return &arr[i];
    }
    return nullptr;
}

// Count cars that have a specific damage code
size_t countCarsWithDamage(const Car* arr, size_t n, int code) {
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        const int* dmg = arr[i].getDamageCodes();
        size_t dcount = arr[i].getDamageCount();
        for (size_t j = 0; j < dcount; ++j) {
            if (dmg[j] == code) {
                ++count;
                break; // Found it, move to the next car
            }
        }
    }
    return count;
}


// ====================================================================================
// 4. Main Function (Demonstration)
// ====================================================================================
int main() {
    std::cout << "--- Smart Garage Management System ---\n\n";
    
    // 1. Initial counter
    std::cout << "1. Initial Car count: " << Car::getTotalCars() << "\n\n";

    // 2. Default-construct a Car
    std::cout << "2. Default-constructing a Car...\n";
    Car cDefault;
    std::cout << "   Car count: " << Car::getTotalCars() << "\n";
    cDefault.printInfo();

    // 3. Parameter-construct a Car
    std::cout << "3. Parameter-constructing a Car...\n";
    Car cParam("1HGCM", "Honda", "Accord", 19999.99);
    std::cout << "   Car count: " << Car::getTotalCars() << "\n";
    cParam.printInfo();

    // 4. Add damage codes
    std::cout << "4. Adding damage codes to Honda...\n";
    cParam.addDamageCode(101);
    cParam.addDamageCode(205);
    cParam.addDamageCode(307);
    cParam.printInfo();

    // 5. Add service records
    std::cout << "5. Adding service records to Honda...\n";
    cParam.addService(ServiceRecord("2022-03-15", 15000, "Oil change"));
    cParam.addService(ServiceRecord("2023-01-10", 25000, "Brake pads replacement"));
    cParam.printInfo();

    // 6. Copy-construct and verify deep copy
    std::cout << "6. Copy-constructing a new Car and verifying deep copy...\n";
    Car cCopy(cParam);
    std::cout << "   Car count: " << Car::getTotalCars() << "\n";
    // To test deep copy, we modify the copy's data.
    
    if (cCopy.getDamageCount() > 0) {
        const_cast<int*>(cCopy.getDamageCodes())[0] = 999;
    }
    std::cout << "   Original car's first damage code: " << cParam.getDamageCodes()[0] << "\n";
    std::cout << "   Copied car's first damage code (modified): " << cCopy.getDamageCodes()[0] << "\n";
    std::cout << "   -> Original is unchanged. Deep copy confirmed.\n\n";

    // 7. Assign and verify deep copy
    std::cout << "7. Assigning to a new Car and verifying deep copy...\n";
    Car cAssign; // Car count is now 4
    cAssign = cParam;
    if (cAssign.getDamageCount() > 1) {
        const_cast<int*>(cAssign.getDamageCodes())[1] = 888;
    }
    std::cout << "   Original car's second damage code: " << cParam.getDamageCodes()[1] << "\n";
    std::cout << "   Assigned car's second damage code (modified): " << cAssign.getDamageCodes()[1] << "\n";
    std::cout << "   -> Original is unchanged. Deep copy on assignment confirmed.\n\n";

    // 8. Allocate and populate a dynamic array of cars
    std::cout << "8. Allocating and populating a dynamic array of 3 cars...\n";
    const size_t N = 3;
    Car* garage = new Car[N];
    std::cout << "   Car count: " << Car::getTotalCars() << "\n";
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);
    for(size_t i=0; i<N; ++i) garage[i].printInfo();

    // 9. Call global averagePrice
    std::cout << "9. Calculating average price of cars in garage...\n";
    double avg = averagePrice(garage, N);
    std::cout << "   Average price: $" << std::fixed << std::setprecision(2) << avg << "\n\n";

    // 10. Use other global utilities
    std::cout << "10. Using other global utilities...\n";
    const Car* maxC = maxPriceCar(garage, N);
    if (maxC) std::cout << "   Max price car VIN: " << maxC->getVIN() << "\n";
    
    const Car* found = findCarByVIN(garage, N, "5YJ3E");
    if (found) std::cout << "   Found car with VIN 5YJ3E. Price: $" << found->getPrice() << "\n";

    size_t countDmg = countCarsWithDamage(garage, N, 101); // 101 is only in cParam, not garage
    std::cout << "   Cars in garage with damage code 101: " << countDmg << "\n\n";

    // 11. Delete the heap array
    std::cout << "11. Deleting the heap array...\n";
    delete[] garage;
    std::cout << "   Car count: " << Car::getTotalCars() << "\n\n";

    // 12. Final counter value
    std::cout << "12. Final car count before main exits: " << Car::getTotalCars() << "\n";
   

    return 0;
}




