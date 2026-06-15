#ifndef TELEVISION_H
#define TELEVISION_H

#include "Device.h"

// Television class - inherits from Device
class Television : public Device {
private:
    int volume;      // 0-100
    int channel;     // 1-999

public:
    Television(string name, double powerConsumption);
    
    void setVolume(int vol);
    void setChannel(int ch);
    int getVolume() const;
    int getChannel() const;
    
    void display() const override;
    void turnOn() override;
    void turnOff() override;
};

#endif
