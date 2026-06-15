#include "Light.h"

Light::Light(string name, double powerConsumption)
    : Device(name, "Light", powerConsumption), brightness(0) {}

void Light::setBrightness(int level) {
    if (level < 0) brightness = 0;
    else if (level > 100) brightness = 100;
    else brightness = level;
    cout << "💡 " << name << " brightness set to " << brightness << "%" << endl;
}

int Light::getBrightness() const {
    return brightness;
}

void Light::display() const {
    cout << "💡 Light: " << name << " | Power: " << powerConsumption << "W | Status: " 
         << (isOn ? "ON" : "OFF") << " | Brightness: " << brightness << "%" << endl;
}

void Light::turnOn() {
    isOn = true;
    brightness = 100;
    cout << "✓ 💡 " << name << " is now ON (100% brightness)" << endl;
}

void Light::turnOff() {
    isOn = false;
    brightness = 0;
    cout << "✗ 💡 " << name << " is now OFF" << endl;
}
