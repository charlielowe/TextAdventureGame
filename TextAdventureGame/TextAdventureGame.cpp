#include <iostream>
#include <string>
#include "Location.h"
#include "LocationList.h"
#include "Declerations.h"
#include "NPC.h"

using namespace std;

Location currentLocation = house;


int main()
{
    while (true) {
        system("cls");
        currentLocation.print_location();
        currentLocation = make_choice();
    }

}

Location make_choice() {
    string playerChoice;
    bool locationFound = false;

    while (true) {
        cin.clear();
        getline(cin, playerChoice);
        
        if (playerChoice == "Talk to " + currentLocation.npc.npcName && currentLocation.npc.defeated == false) {
            if (encounter_npc(currentLocation.npc) == true) {
                currentLocation.npc.defeated = true;
                
            }
            
            locationFound = true;
        }
        else{
            for (auto location : currentLocation.optionsPrintedAtLocation) {
                if (playerChoice == location) {
                    for (auto loc : listOfLocations) {
                        if (playerChoice == loc.locationName) {
                            currentLocation = loc;
                            locationFound = true;
                            break;
                        }
                    }
                    break;
                }
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

bool encounter_npc(NPC npc) {
    system("cls");
    npc.print_npc_info();
    if (npc.npcDialogueFunction() == 1) {
        return true;
    }
    
}

int GoldSpandexManDialogue(){
    cout << "Hey, you there! I'm gold spandex man! Fight me!" << endl;
    cout << endl;
    cin.clear();
    string choice;
    getline(cin, choice);
    if (choice == "defeat") {
        return 1;
    }
    else {
        return 0;
    }
    
}


