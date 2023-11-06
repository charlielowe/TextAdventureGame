#include <iostream>
#include <string>
#include <conio.h>
#include "Location.h"
#include "LocationList.h"
#include "Declerations.h"
#include "NPC.h"

// Comments include references to line numbers, this should be line 9 for them to line up

using namespace std;

// Instances of the location class are declared in "LocationList.h"
//Variables and functions are declared in "Declerations.h"

Location &currentLocation = house; // Set a variable called currentLocation to the location that I want the game to start in (check LocationList.h to see locations)


int main()
{
    while (true) { // Game loop that allows the user to move around the map by printing out the current location and then running a function to take their choice for the next location
        system("cls"); // Clear the terminal
        currentLocation.print_location(); // Runs the print_location() function of the currentLocation. Check Location.cpp to see function
        currentLocation = make_choice(); // Sets the currentLocation to the value returned by the make_choice() function.
    }

}

Location make_choice() { // Function to take user input, do different things depending on input, and then return what the new currentLocation is
    string playerChoice; // String for player input
    bool locationFound = false; // boolean to say if what the player inputted is actually a location, gets updated later in code

    while (true) { // While loop to keep looping until the player enters a valid input
        cin.clear();
        getline(cin, playerChoice); // Takes player input

        if (playerChoice == "Talk to " + (*currentLocation.get_npc()).get_npc_name() && (*currentLocation.get_npc()).get_npc_defeated() == false) { // If the player inputs "talk to" and then the name of the npc at the current location, and the npc isn't defeated
            if (encounter_npc((*currentLocation.get_npc())) == true) { // Runs the encounter_npc() function using the current npc as a parameter and checks if the function returns true

                (*currentLocation.get_npc()).set_npc_defeated(true); // Set the currentLocation's npc to be defeated

            }
            
            locationFound = true; // Sets locationFound to true 
        }
        else{
            for (auto location : currentLocation.get_options()){ // Inside the "LocationList.h" file, when declaring new instances of the location class, a vector of strings is inputted which is printed out later to tell the user what their options are (which locations they can move to). This line loops through that vector
                if (playerChoice == location) { // Checks to see if what the user inputted is actually one of the options pritned out for them
                    for (auto &loc : listOfLocations){ // Loops through a vector ListOfLocations which is declared in "LocationList.h". This stores the actual instances of the location class
                        if (playerChoice == loc.get_location_name()) { // Find out which location the user inputted
                            currentLocation = loc; // Sets the current location to that location
                            locationFound = true; // Sets locationFound to true
                            break; // Breaks out of the loop after finding the right location
                        }
                    }
                    break; // Breaks out of the loop after finding the right option
                }
            }
        }
        
        if (locationFound == false) { 
            cout << "That isn't an option" << endl; // If the user inputs an option that isn't available to them, tell them it isn't an option, then go back to the start of the while loop on line 31
        }
        else {
            return currentLocation; // If the user did enter a valid input, return the currentLocation (which has now been updated to whatever the player inputted)
            break; // Break out of while loop
        }
    }

   
}

bool encounter_npc(NPC npc) { // Function to be ran when the player talks to an NPC
    system("cls");
    npc.print_npc_info(); // Prints out the npc info using the function print_npc_info() (declared in NPC.cpp)
    if (npc.get_npc_dialogue_func() == 1) { // Runs the dialogue function of the current npc and checks if it returns 1
        return true; // Returns true, which is checked back on line 36
    }
    
}

int GoldSpandexManDialogue(){ // Specific NPC dialogue function. Each NPC has their own dialogue function containing outputs and inputs allowing the player to have a conversation with the NPC.
    cout << "Hey, you there! I'm gold spandex man! Fight me!" << endl;
    cout << endl;
    cin.clear();
    string choice;
    getline(cin, choice);
    if (choice == "defeat") { 
        return 1; // Returning 1 means the NPC is defeated, which is checked by encounter_npc() on line 74, which ultimately sets the "defeated" variable of the current npc to true on line 38
    }
    else {
        return 0;
    }
    
}

int bobDialogue() { // Specific NPC dialogue function
    cout << "Hi I'm Bob" << endl;
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


