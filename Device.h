#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

using namespace std;

// Base class for all smart home devices
class Device {
protected:
    string name;
    string type;
    double powerConsumption;  // in watts
    bool isOn;

public:
    // Constructor
    Device(string name, string type, double powerConsumption);
    
    // Virtual destructor
    virtual ~Device();
    
    // Virtual methods
    virtual void turnOn();
    virtual void turnOff();
    virtual void display() const;
    virtual double getPowerUsage() const;
    
    // Getters
    string getName() const;
    string getType() const;
    bool getStatus() const;
    double getPowerConsumption() const;
    
    // Operator Overloading
    bool operator==(const Device& other) const;
    bool operator<(const Device& other) const;
    Device& operator=(const Device& other);
    friend ostream& operator<<(ostream& os, const Device& device);
};

#endif
