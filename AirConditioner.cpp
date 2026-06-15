#include "AirConditioner.h"

AirConditioner::AirConditioner(string name, double powerConsumption)
    : Device(name, "Air Conditioner", powerConsumption), temperature(22) {}

void AirConditioner::setTemperature(int temp) {
    if (temp < 16) temperature = 16;
    else if (temp > 30) temperature = 30;
    else temperature = temp;
    cout << "❄️ " << name << " temperature set to " << temperature << "°C" << endl;
}

int AirConditioner::getTemperature() const {
    return temperature;
}

void AirConditioner::display() const {
    cout << "❄️ AC: " << name << " | Power: " << powerConsumption << "W | Status: " 
         << (isOn ? "ON" : "OFF") << " | Temperature: " << temperature << "°C" << endl;
}

void AirConditioner::turnOn() {
    isOn = true;
    cout << "✓ ❄��� " << name << " is now ON (Temperature: " << temperature << "°C)" << endl;
}

void AirConditioner::turnOff() {
    isOn = false;
    cout << "✗ ❄️ " << name << " is now OFF" << endl;
}
