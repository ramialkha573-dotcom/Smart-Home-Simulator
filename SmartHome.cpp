#include "SmartHome.h"

SmartHome::SmartHome(string name) : homeName(name) {}

SmartHome::~SmartHome() {
    for (int i = 0; i < devices.size(); i++) {
        delete devices[i];
    }
    devices.clear();
}

void SmartHome::addDevice(Device* device) {
    devices.push_back(device);
    cout << "✓ Device '" << device->getName() << "' added to " << homeName << endl;
}

void SmartHome::removeDevice(int index) {
    if (index >= 0 && index < devices.size()) {
        cout << "✗ Device '" << devices[index]->getName() << "' removed from " << homeName << endl;
        delete devices[index];
        devices.erase(devices.begin() + index);
    } else {
        cout << "❌ Invalid device index!" << endl;
    }
}

void SmartHome::displayAllDevices() const {
    cout << "\n══════════════════════��════════════════════════════════════" << endl;
    cout << "        📡 " << homeName << " - All Devices" << endl;
    cout << "═══════════════════════════════════════════════════════════" << endl;
    
    if (devices.empty()) {
        cout << "No devices in the home!" << endl;
    } else {
        for (int i = 0; i < devices.size(); i++) {
            cout << "[" << i << "] ";
            devices[i]->display();
        }
    }
    cout << "═══════════════════════════════════════════════════════════\n" << endl;
}

Device* SmartHome::findDevice(string name) const {
    for (int i = 0; i < devices.size(); i++) {
        if (devices[i]->getName() == name) {
            return devices[i];
        }
    }
    return nullptr;
}

void SmartHome::turnOnDevice(int index) {
    if (index >= 0 && index < devices.size()) {
        devices[index]->turnOn();
    } else {
        cout << "❌ Invalid device index!" << endl;
    }
}

void SmartHome::turnOffDevice(int index) {
    if (index >= 0 && index < devices.size()) {
        devices[index]->turnOff();
    } else {
        cout << "❌ Invalid device index!" << endl;
    }
}

void SmartHome::turnOnAllDevices() {
    cout << "\n🔋 Turning ON all devices..." << endl;
    for (int i = 0; i < devices.size(); i++) {
        devices[i]->turnOn();
    }
}

void SmartHome::turnOffAllDevices() {
    cout << "\n🔌 Turning OFF all devices..." << endl;
    for (int i = 0; i < devices.size(); i++) {
        devices[i]->turnOff();
    }
}

double SmartHome::calculateTotalPowerUsage() const {
    double total = 0.0;
    for (int i = 0; i < devices.size(); i++) {
        total += devices[i]->getPowerUsage();
    }
    return total;
}

void SmartHome::displayPowerUsage() const {
    cout << "\n═══════════════════════════════════════════════════════════" << endl;
    cout << "        ⚡ Power Consumption Report" << endl;
    cout << "═══════════════════════════════════════════════════════════" << endl;
    
    for (int i = 0; i < devices.size(); i++) {
        cout << "[" << i << "] " << devices[i]->getName() << ": ";
        if (devices[i]->getStatus()) {
            cout << devices[i]->getPowerConsumption() << "W (ON)" << endl;
        } else {
            cout << "0W (OFF)" << endl;
        }
    }
    
    cout << "───────────────────────────────────────────────────────────" << endl;
    cout << "Total Power Usage: " << calculateTotalPowerUsage() << "W" << endl;
    cout << "════════════════════════════════════���══════════════════════\n" << endl;
}

int SmartHome::getDeviceCount() const {
    return devices.size();
}

Device* SmartHome::getDevice(int index) const {
    if (index >= 0 && index < devices.size()) {
        return devices[index];
    }
    return nullptr;
}

string SmartHome::getHomeName() const {
    return homeName;
}

// Operator Overloading - Index operator
Device* SmartHome::operator[](int index) const {
    return getDevice(index);
}

// Operator Overloading - Addition (add device)
SmartHome& SmartHome::operator+=(Device* device) {
    addDevice(device);
    return *this;
}

// Operator Overloading - Subtraction (remove device)
SmartHome& SmartHome::operator-=(int index) {
    removeDevice(index);
    return *this;
}

// Operator Overloading - Stream output
ostream& operator<<(ostream& os, const SmartHome& home) {
    os << "\n🏠 Smart Home: " << home.homeName << endl;
    os << "📊 Total Devices: " << home.devices.size() << endl;
    os << "⚡ Total Power: " << home.calculateTotalPowerUsage() << "W" << endl;
    return os;
}
