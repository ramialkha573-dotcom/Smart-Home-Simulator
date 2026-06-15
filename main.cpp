#include "SmartHome.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void displayMenu() {
    cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║           🏠 SMART HOME SIMULATOR - MAIN MENU 🏠           ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ 1. ➕  Add Device                                          ║" << endl;
    cout << "║ 2. ❌  Remove Device                                       ║" << endl;
    cout << "║ 3. 📋  Display All Devices                                 ║" << endl;
    cout << "║ 4. 💡  Turn On Device                                      ║" << endl;
    cout << "║ 5. 🌙  Turn Off Device                                     ║" << endl;
    cout << "║ 6. 🔋  Turn On All Devices                                 ║" << endl;
    cout << "║ 7. 🔌  Turn Off All Devices                                ║" << endl;
    cout << "║ 8. ⚡  View Power Consumption                              ║" << endl;
    cout << "║ 9. ℹ️   About Smart Home                                    ║" << endl;
    cout << "║ 0. 🚪  Exit                                                ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << "Enter your choice: ";
}

void displayDeviceTypeMenu() {
    cout << "\n╔═══════════════════════════════════════════════���════════════╗" << endl;
    cout << "║              SELECT DEVICE TYPE TO ADD                     ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ 1. 💡 Light        (60W)                                  ║" << endl;
    cout << "║ 2. ❄️  Air Conditioner (1500W)                            ║" << endl;
    cout << "║ 3. 📺 Television   (100W)                                 ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << "Select device type: ";
}

int main() {
    SmartHome home("My Smart Home");
    int choice;
    bool running = true;

    cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║     🏠 WELCOME TO SMART HOME SIMULATOR 🏠                 ║" << endl;
    cout << "║                  Version 1.0                              ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Device
                displayDeviceTypeMenu();
                int deviceType;
                cin >> deviceType;
                cin.ignore();

                string deviceName;
                cout << "Enter device name: ";
                getline(cin, deviceName);

                if (deviceType == 1) {
                    Light* light = new Light(deviceName, 60);
                    home += light;
                } else if (deviceType == 2) {
                    AirConditioner* ac = new AirConditioner(deviceName, 1500);
                    home += ac;
                } else if (deviceType == 3) {
                    Television* tv = new Television(deviceName, 100);
                    home += tv;
                } else {
                    cout << "❌ Invalid device type!" << endl;
                }
                break;
            }

            case 2: {
                // Remove Device
                home.displayAllDevices();
                int index;
                cout << "Enter device index to remove: ";
                cin >> index;
                home -= index;
                break;
            }

            case 3: {
                // Display All Devices
                home.displayAllDevices();
                break;
            }

            case 4: {
                // Turn On Device
                home.displayAllDevices();
                int index;
                cout << "Enter device index to turn ON: ";
                cin >> index;
                home.turnOnDevice(index);
                break;
            }

            case 5: {
                // Turn Off Device
                home.displayAllDevices();
                int index;
                cout << "Enter device index to turn OFF: ";
                cin >> index;
                home.turnOffDevice(index);
                break;
            }

            case 6: {
                // Turn On All Devices
                home.turnOnAllDevices();
                break;
            }

            case 7: {
                // Turn Off All Devices
                home.turnOffAllDevices();
                break;
            }

            case 8: {
                // View Power Consumption
                home.displayPowerUsage();
                break;
            }

            case 9: {
                // About Smart Home
                cout << home << endl;
                break;
            }

            case 0: {
                // Exit
                cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
                cout << "║      Thank you for using Smart Home Simulator! 👋          ║" << endl;
                cout << "╚═══════════════════════════════════════════════════════════��╝\n" << endl;
                running = false;
                break;
            }

            default:
                cout << "❌ Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
