//Fleet Vehicle Monitoring System

#include<iostream>
#include<string>

using namespace std;

class FleetVehicle{
    private:
        //Private Data Members
        int vehicleID;
        float fuelLevel;
        double distanceTravelled;
        char status;
        bool isAvailable;
        string driverName;

    public:
    //Default Constructer
    FleetVehicle()
     :vehicleID(0),fuelLevel(50.0),distanceTravelled(0.0),status('A'),isAvailable(true),driverName("Unassigned"){};
    
    //Parameterized Constructer
     FleetVehicle(int v,float f,double d,char s,bool avail,string driver)
     :vehicleID(v),fuelLevel(f),distanceTravelled(d),status(s),isAvailable(avail),driverName(driver){};
    
     //Destructers
     ~FleetVehicle(){
        cout<<"Destructor called for vehicle ID: "<< vehicleID<<";"<<endl;
     }
        
     // Getters
     int getVehicleID() const { return vehicleID; }
     float getFuelLevel() const { return fuelLevel; }
     double getDistanceTravelled() const { return distanceTravelled; }
     char getStatus() const { return status; }
     bool getAvailability() const { return isAvailable; }
     string getDriverName() const { return driverName; }
     
     //Setters
     void setVehicleID(int v) { vehicleID = v; }
     void setFuelLevel(float f) { fuelLevel = f; }
     void setDistanceTravelled(double d) { distanceTravelled = d; }
     void setStatus(char s) { status = s; }
     void setAvailability(bool avail) { isAvailable = avail; }
     void setDriverName(const string& driver) { driverName = driver; }

     //Status Update based on condition
     void updateStatus(){
         if(fuelLevel<10.0 || !isAvailable) 
            status='I';
         else 
            status='A';
     }

     void displayInfo() const{
        cout << "Vehicle ID        : " << vehicleID << endl;
        cout << "Fuel Level        : " << fuelLevel << endl;
        cout << "Distance Travelled: " << distanceTravelled << endl;
        cout << "Status            : " << (status == 'A' ? "Active" : "Inactive") << endl;
        cout << "Availability      : " << (isAvailable ? "Available" : "Not Available") << endl;
        cout << "Driver Name       : " << driverName << endl;

     }
};

//Global Functions 

// Assign Driver
void assignDriver(FleetVehicle &vehicle, const string& name) {
    vehicle.setDriverName(name);
    cout << "Driver " << vehicle.getDriverName()
         << " successfully assigned." << endl;
}

// Refuel Vehicle
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw invalid_argument("Fuel amount must be greater than 0!");
    }

    else{
    float newFuelLevel = vehicle.getFuelLevel() + fuelAmount;
    vehicle.setFuelLevel(newFuelLevel);

    cout << "Vehicle ID " << vehicle.getVehicleID()
         << " successfully refueled. Current Fuel Level: "
         << vehicle.getFuelLevel() << " liters" << endl;
    }
}


// Main Function
int main() {
    FleetVehicle fleet[3] = {
        FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya"),
        FleetVehicle() // default constructor
    };

    int choice;
    do {
       
        cout << "\n Menu" << endl;
        cout << "1. Add Vehicle (Parameterized Constructor)" << endl;
        cout << "2. Assign Driver" << endl;
        cout << "3. Refuel Vehicle" << endl;
        cout << "4. Update Status" << endl;
        cout << "5. Display Vehicle Info" << endl;
        cout << "6. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int id; float fuel; double dist; char status; bool avail; string driver;
                cout << "Enter Vehicle ID: "; cin >> id;
                cout << "Enter Fuel Level: "; cin >> fuel;
                cout << "Enter Distance Travelled: "; cin >> dist;
                cout << "Enter Status (A/I): "; cin >> status;
                cout << "Enter Availability (1 for Yes, 0 for No): "; cin >> avail;
                cout << "Enter Driver Name: "; cin.ignore(); getline(cin, driver);

                // Replace 3rd vehicle with new details
                fleet[2] = FleetVehicle(id, fuel, dist, status, avail, driver);
                cout << "Vehicle details added successfully!" << endl;
                break;
            }
            case 2: {
                int index; string driver;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if(index >= 0 && index < 3) {
                    cout << "Enter Driver Name: "; cin.ignore(); getline(cin, driver);
                    assignDriver(fleet[index], driver);
                } else {
                    cout << "Invalid vehicle index!" << endl;
                }
                break;
            }
            case 3: {
                int index; float fuelAmt;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if(index >= 0 && index < 3) {
                    cout << "Enter Fuel Amount: "; cin >> fuelAmt;
                    refuelVehicle(fleet[index], fuelAmt);
                } else {
                    cout << "Invalid vehicle index!" << endl;
                }
                break;
            }
            case 4: {
                int index;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if(index >= 0 && index < 3) {
                    fleet[index].updateStatus();
                    cout << "Status updated successfully!" << endl;
                } else {
                    cout << "Invalid vehicle index!" << endl;
                }
                break;
            }
            case 5: {
                int index;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if(index >= 0 && index < 3) {
                    fleet[index].displayInfo();
                } else {
                    cout << "Invalid vehicle index!" << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting Fleet Management System..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while(choice != 6);

    return 0;
}
