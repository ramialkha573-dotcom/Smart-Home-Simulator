#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

// Light class - inherits from Device
class Light : public Device {
private:
    int brightness;  // 0-100

public:
    Light(string name, double powerConsumption);
    
    void setBrightness(int level);
    int getBrightness() const;
    
    void display() const override;
    void turnOn() override;
    void turnOff() override;
};

#endif
