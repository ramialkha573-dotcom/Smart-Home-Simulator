#ifndef AIRCONDITIONER_H
#define AIRCONDITIONER_H

#include "Device.h"

// Air Conditioner class - inherits from Device
class AirConditioner : public Device {
private:
    int temperature;  // in Celsius

public:
    AirConditioner(string name, double powerConsumption);
    
    void setTemperature(int temp);
    int getTemperature() const;
    
    void display() const override;
    void turnOn() override;
    void turnOff() override;
};

#endif
