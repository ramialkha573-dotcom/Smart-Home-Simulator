#include "Television.h"

Television::Television(string name, double powerConsumption)
    : Device(name, "Television", powerConsumption), volume(50), channel(1) {}

void Television::setVolume(int vol) {
    if (vol < 0) volume = 0;
    else if (vol > 100) volume = 100;
    else volume = vol;
    cout << "📺 " << name << " volume set to " << volume << "%" << endl;
}

void Television::setChannel(int ch) {
    if (ch < 1) channel = 1;
    else if (ch > 999) channel = 999;
    else channel = ch;
    cout << "📺 " << name << " channel changed to " << channel << endl;
}

int Television::getVolume() const {
    return volume;
}

int Television::getChannel() const {
    return channel;
}

void Television::display() const {
    cout << "📺 TV: " << name << " | Power: " << powerConsumption << "W | Status: " 
         << (isOn ? "ON" : "OFF") << " | Channel: " << channel 
         << " | Volume: " << volume << "%" << endl;
}

void Television::turnOn() {
    isOn = true;
    cout << "✓ 📺 " << name << " is now ON (Channel: " << channel << ")" << endl;
}

void Television::turnOff() {
    isOn = false;
    cout << "✗ 📺 " << name << " is now OFF" << endl;
}
