#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

// Enum for flight status
enum FlightStatus
{
    PARKED,
    TAXIING,
    WAITING_TO_TAKEOFF,
    TAKING_OFF,
    CLIMBING,
    CRUISING,
    CHANGING_ALTITUDE,
    DESCENDING,
    LANDING,
    AT_GATE
};

// Flight class definition
class Flight
{
private:
    std::string airline;       // Airline name
    std::string flightNumber;  // Flight number
    std::string makeModel;     // Aircraft model
    int currentAltitude;       // Current altitude
    int airSpeed;              // Current airspeed
    int direction;             // Current direction
    char origin[3];            // Origin airport
    char destination[3];       // Destination airport
    std::string departureTime; // Departure time
    std::string arrivalTime;   // Arrival time
    FlightStatus status;       // Flight status

public:
    // Constructor
    Flight(std::string air, std::string number, std::string model, int altitude,
           int speed, int dir, std::string from, std::string to,
           std::string depart, std::string arrive, FlightStatus stat);

    // Getters
    std::string getAirline() const;
    std::string getFlightNumber() const;
    std::string getMakeModel() const;
    int getCurrentAltitude() const;
    int getAirSpeed() const;
    int getDirection() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    FlightStatus getStatus() const;

    // Setters
    void setAirline(const std::string &air);
    void setFlightNumber(const std::string &number);
    void setMakeModel(const std::string &model);
    void setCurrentAltitude(int altitude);
    void setAirSpeed(int speed);
    void setDirection(int dir);
    void setOrigin(const std::string &from);
    void setDestination(const std::string &to);
    void setDepartureTime(const std::string &time);
    void setArrivalTime(const std::string &time);
    void setStatus(FlightStatus stat);

    // Public methods
    void changeAltitude(int newAlt); // Change flight altitude
    void reduceSpeed(int newSpeed);  // Reduce flight speed
    void beginLandingApproach();     // Begin landing approach
    std::string toString() const;    // Get flight details as a string
};

#endif