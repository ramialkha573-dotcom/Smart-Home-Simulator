#include "Device.h"

// Constructor
Device::Device(string name, string type, double powerConsumption)
    : name(name), type(type), powerConsumption(powerConsumption), isOn(false) {}

// Destructor
Device::~Device() {}

// Turn on the device
void Device::turnOn() {
    isOn = true;
    cout << "✓ " << name << " is now ON" << endl;
}

// Turn off the device
void Device::turnOff() {
    isOn = false;
    cout << "✗ " << name << " is now OFF" << endl;
}

// Display device information
void Device::display() const {
    cout << "Device: " << name << " | Type: " << type 
         << " | Power: " << powerConsumption << "W | Status: " 
         << (isOn ? "ON" : "OFF") << endl;
}

// Get power usage
double Device::getPowerUsage() const {
    return isOn ? powerConsumption : 0.0;
}

// Getters
string Device::getName() const {
    return name;
}

string Device::getType() const {
    return type;
}

bool Device::getStatus() const {
    return isOn;
}

double Device::getPowerConsumption() const {
    return powerConsumption;
}

// Operator Overloading - Equality
bool Device::operator==(const Device& other) const {
    return this->name == other.name && this->type == other.type;
}

// Operator Overloading - Less than (for sorting)
bool Device::operator<(const Device& other) const {
    return this->powerConsumption < other.powerConsumption;
}

// Operator Overloading - Assignment
Device& Device::operator=(const Device& other) {
    if (this != &other) {
        this->name = other.name;
        this->type = other.type;
        this->powerConsumption = other.powerConsumption;
        this->isOn = other.isOn;
    }
    return *this;
}

// Operator Overloading - Stream output
ostream& operator<<(ostream& os, const Device& device) {
    os << "[" << device.type << "] " << device.name 
       << " (" << device.powerConsumption << "W) - " 
       << (device.isOn ? "ON" : "OFF");
    return os;
}
