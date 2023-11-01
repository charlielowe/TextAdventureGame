#include <iostream>
#include <string>
#include "Location.h"
#include "LocationList.h"


using namespace std;

Location currentLocation = house;

Location make_choice();

int main()
{
    while (true) {
        currentLocation.print_location();
        currentLocation = make_choice();
    }
   
}

Location make_choice() {
    string playerChoice;
    bool locationFound = false;

    while (true) {
        cin >> playerChoice;

        for (auto location : listOfLocations) {
            if (playerChoice == location.locationName) {
                currentLocation = location;
                locationFound = true;
                break;
            }
        }
        if (locationFound == false) {
            cout << "That isn't an option" << endl;
        }
        else {
            return currentLocation;
            break;
        }
    }

   
}


