#include <iostream>
#include <cstring>
#include "Flight.h"

// Constructor
Flight::Flight(std::string air, std::string number, std::string model, int altitude, int speed, int dir, std::string from, std::string to,
               std::string depart, std::string arrive, FlightStatus stat)
    : airline(air), flightNumber(number), makeModel(model),
      airSpeed(speed), direction(dir), departureTime(depart),
      arrivalTime(arrive), status(stat), currentAltitude(altitude)
{
    std::strncpy(origin, from.c_str(), 3); // Copy origin
    std::strncpy(destination, to.c_str(), 3); // Copy destination
}

// Getters
std::string Flight::getAirline() const { return airline; }
std::string Flight::getFlightNumber() const { return flightNumber; }
std::string Flight::getMakeModel() const { return makeModel; }
int Flight::getCurrentAltitude() const { return currentAltitude; }
int Flight::getAirSpeed() const { return airSpeed; }
int Flight::getDirection() const { return direction; }
std::string Flight::getOrigin() const { return std::string(origin, 3); }
std::string Flight::getDestination() const { return std::string(destination, 3); }
std::string Flight::getDepartureTime() const { return departureTime; }
std::string Flight::getArrivalTime() const { return arrivalTime; }
FlightStatus Flight::getStatus() const { return status; }

// Setters
void Flight::setAirline(const std::string &air) { airline = air; }
void Flight::setFlightNumber(const std::string &number) { flightNumber = number; }
void Flight::setMakeModel(const std::string &model) { makeModel = model; }
void Flight::setCurrentAltitude(int altitude) { currentAltitude = altitude; }
void Flight::setAirSpeed(int speed) { airSpeed = speed; }
void Flight::setDirection(int dir) { direction = dir; }
void Flight::setOrigin(const std::string &from) { std::strncpy(origin, from.c_str(), 3); }
void Flight::setDestination(const std::string &to) { std::strncpy(destination, to.c_str(), 3); }
void Flight::setDepartureTime(const std::string &time) { departureTime = time; }
void Flight::setArrivalTime(const std::string &time) { arrivalTime = time; }
void Flight::setStatus(FlightStatus stat) { status = stat; }

// Change flight altitude
void Flight::changeAltitude(int newAlt)
{
    std::cout << airline << " " << flightNumber
              << " changing altitude from " << currentAltitude
              << " to " << newAlt << " feet.\n"; // Announce change
    currentAltitude = newAlt; // Update altitude
    status = CHANGING_ALTITUDE; // Update status
}

// Reduce flight speed
void Flight::reduceSpeed(int newSpeed)
{
    std::cout << airline << " " << flightNumber
              << " reducing speed from " << airSpeed
              << " to " << newSpeed << ".\n"; // Announce change
    airSpeed = newSpeed; // Update speed
}

// Begin landing approach
void Flight::beginLandingApproach()
{
    std::cout << airline << " " << flightNumber
              << " beginning landing approach.\n"; // Announce landing
    status = DESCENDING; // Update status
    setCurrentAltitude(getCurrentAltitude() - 5000); // Descend
}

// Get flight details as a string
std::string Flight::toString() const
{
    std::string statusText[] = {
        "Parked", "Taxiing", "Waiting to Take Off", "Taking Off",
        "Climbing", "Cruising", "Changing Altitude", "Descending",
        "Landing", "At Gate"}; // Status strings

    std::string info = airline + " " + flightNumber + " [" + makeModel + "]\n"; // Basic info
    info += "From " + std::string(origin, 3) + " to " + std::string(destination, 3) + "\n"; // Route
    info += "Departure: " + departureTime + ", Arrival: " + arrivalTime + "\n"; // Times
    info += "Speed of Air: " + std::to_string(airSpeed) + " , Direction: " + std::to_string(direction) + "\n"; // Speed and direction
    info += "Current Altitude: " + std::to_string(currentAltitude) + " ft\n"; // Altitude
    info += "Status: " + statusText[status] + "\n"; // Status

    return info;
}