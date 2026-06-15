#ifndef SMARTHOME_H
#define SMARTHOME_H

#include "Device.h"
#include "Light.h"
#include "AirConditioner.h"
#include "Television.h"
#include <vector>

class SmartHome {
private:
    vector<Device*> devices;
    string homeName;

public:
    SmartHome(string name);
    ~SmartHome();
    
    // Device management
    void addDevice(Device* device);
    void removeDevice(int index);
    void displayAllDevices() const;
    Device* findDevice(string name) const;
    
    // Device control
    void turnOnDevice(int index);
    void turnOffDevice(int index);
    void turnOnAllDevices();
    void turnOffAllDevices();
    
    // Power consumption
    double calculateTotalPowerUsage() const;
    void displayPowerUsage() const;
    
    // Getters
    int getDeviceCount() const;
    Device* getDevice(int index) const;
    string getHomeName() const;
    
    // Operator Overloading
    Device* operator[](int index) const;
    SmartHome& operator+=(Device* device);
    SmartHome& operator-=(int index);
    friend ostream& operator<<(ostream& os, const SmartHome& home);
};

#endif
