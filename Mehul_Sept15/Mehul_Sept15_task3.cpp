#include <iostream>
#include <string>
#include <iomanip> // For formatted output

using namespace std;

// Enum for component types
enum ComponentType
{
    COMPONENT_TYPE_ENGINE = 1,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

// Enum for component status
enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL = 1,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

class AerospaceComponent
{
private:
    int componentIdentifier;
    double componentEfficiency;
    string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    // Default constructor
    AerospaceComponent()
        : componentIdentifier(0),
          componentEfficiency(100.0),
          componentManufacturer("Unknown"),
          componentType(COMPONENT_TYPE_ENGINE),
          componentStatus(COMPONENT_STATUS_OPERATIONAL){}

    // Parameterized constructor
    AerospaceComponent(int id, double efficiency, const string &manufacturer,
                       ComponentType type, ComponentStatus status)
        : componentIdentifier(id),
          componentEfficiency(efficiency),
          componentManufacturer(manufacturer),
          componentType(type),
          componentStatus(status){}

    // Destructor
    ~AerospaceComponent()
    {
        cout << "Component " << componentIdentifier << " destroyed." << endl;
    }

    // Update status based on efficiency
    void UpdateStatus()
    {
        if (componentEfficiency < 50.0)
        {
            componentStatus = COMPONENT_STATUS_FAILED;
        }
        else if (componentEfficiency < 80.0)
        {
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        }
        else
        {
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
        }
    }

    // Simulate usage
    void SimulateUsage(int usageHours)
    {
        for (int i = 0; i < usageHours; ++i)
        {
            componentEfficiency -= componentEfficiency * 0.005; // reduce by 0.5%
            if (componentEfficiency < 0.0)
            {
                componentEfficiency = 0.0;
                break;
            }
        }
        UpdateStatus();
    }

    // Perform maintenance check
    void PerformMaintenanceCheck() const
    {
        switch (componentStatus)
        {
        case COMPONENT_STATUS_OPERATIONAL:
            cout << "Component " << componentIdentifier << " is operational." << endl;
            break;
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
            cout << "Component " << componentIdentifier << " requires maintenance." << endl;
            break;
        case COMPONENT_STATUS_FAILED:
            cout << "Component " << componentIdentifier << " has failed!" << endl;
            break;
        default:
            cout << "Unknown status." << endl;
            break;
        }
    }

    // Boost efficiency to 100%
    void BoostEfficiency()
    {
        while (componentEfficiency < 100.0)
        {
            componentEfficiency += 1.0;
        }
        UpdateStatus();
    }

    // Display component details
    void DisplayDetails() const
    {
        cout << fixed << setprecision(2);
        cout << "ID: " << componentIdentifier
             << ", Efficiency: " << componentEfficiency
             << ", Manufacturer: " << componentManufacturer
             << ", Type: " << componentType
             << ", Status: " << componentStatus << endl;
    }

    // Setters and getters
    void SetManufacturer(const string &manufacturer)
    {
        if (!manufacturer.empty())
        {
            componentManufacturer = manufacturer;
        }
    }

    double getEfficiency() const
    {
        return componentEfficiency;
    }

    ComponentType getType() const
    {
        return componentType;
    }

    ComponentStatus getStatus() const
    {
        return componentStatus;
    }

    int getIdentifier() const
    {
        return componentIdentifier;
    }
};

// Global functions
void AssignManufacturer(AerospaceComponent &component, const string &manufacturerName)
{
    component.SetManufacturer(manufacturerName);
}

bool IsEfficient(const AerospaceComponent &component)
{
    return component.getEfficiency() > 85.0;
}

bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return componentA.getType() == componentB.getType();
}

bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return componentA.getStatus() == componentB.getStatus();
}

void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize)
{
    cout << "\n Component List \n";
    for (int i = 0; i < listSize; ++i)
    {
        componentList[i].DisplayDetails();
    }
}

int SearchComponentByIdentifier(const AerospaceComponent componentList[], const int listSize, const int searchIdentifier)
{
    for (int i = 0; i < listSize; ++i)
    {
        if (componentList[i].getIdentifier() == searchIdentifier)
        {
            return i;
        }
    }
    return -1;
}

// Main function
int main()
{
    AerospaceComponent componentList[3] = {
        AerospaceComponent(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL),
        AerospaceComponent(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED),
        AerospaceComponent()};

    int choice = 0;

    while (true)
    {
        cout << "\n Aerospace Component Menu\n";
        cout << "1. Assign Manufacturer\n";
        cout << "2. Simulate Usage\n";
        cout << "3. Boost Efficiency\n";
        cout << "4. Check Maintenance Status\n";
        cout << "5. Compare Components\n";
        cout << "6. Search by Component ID\n";
        cout << "7. Display All Components\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
            break;

        switch (choice)
        {
        case 1:
        {
            int id;
            string manufacturer;
            cout << "Enter component ID to assign manufacturer: ";
            cin >> id;
            cin.ignore();
            cout << "Enter manufacturer name: ";
            getline(cin, manufacturer);

            int index = SearchComponentByIdentifier(componentList, 3, id);
            if (index != -1 && !manufacturer.empty())
            {
                AssignManufacturer(componentList[index], manufacturer);
                cout << "Manufacturer assigned." << endl;
            }
            else
            {
                cout << "Invalid ID or manufacturer name." << endl;
            }
            break;
        }
        case 2:
        {
            int id, hours;
            cout << "Enter component ID to simulate usage: ";
            cin >> id;
            cout << "Enter usage hours: ";
            cin >> hours;

            int index = SearchComponentByIdentifier(componentList, 3, id);
            if (index != -1 && hours > 0)
            {
                componentList[index].SimulateUsage(hours);
                cout << "Usage simulated." << endl;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter component ID to boost efficiency: ";
            cin >> id;

            int index = SearchComponentByIdentifier(componentList, 3, id);
            if (index != -1)
            {
                componentList[index].BoostEfficiency();
                cout << "Efficiency boosted." << endl;
            }
            else
            {
                cout << "Invalid component ID." << endl;
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < 3; ++i)
            {
                componentList[i].PerformMaintenanceCheck();
            }
            break;
        }
        case 5:
        {
            int id1, id2;
            cout << "Enter first component ID: ";
            cin >> id1;
            cout << "Enter second component ID: ";
            cin >> id2;

            int index1 = SearchComponentByIdentifier(componentList, 3, id1);
            int index2 = SearchComponentByIdentifier(componentList, 3, id2);

            if (index1 != -1 && index2 != -1)
            {
                cout << "Same Type: " << (IsSameType(componentList[index1], componentList[index2]) ? "Yes" : "No") << endl;
                cout << "Same Status: " << (IsSameStatus(componentList[index1], componentList[index2]) ? "Yes" : "No") << endl;
            }
            else
            {
                cout << "Invalid component IDs." << endl;
            }
            break;
        }
        case 6:
        {
            int id;
            cout << "Enter component ID to search: ";
            cin >> id;
            int index = SearchComponentByIdentifier(componentList, 3, id);
            if (index != -1)
            {
                componentList[index].DisplayDetails();
            }
            else
            {
                cout << "Component not found." << endl;
            }
            break;
        }
        case 7:
            PrintFormattedComponentList(componentList, 3);
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
