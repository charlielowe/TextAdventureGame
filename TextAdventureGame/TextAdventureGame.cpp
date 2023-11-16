#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
#include "Location.h"
#include "LocationList.h"
#include "Declerations.h"
#include "NPC.h"
#include "Player.h"

// Comments include references to line numbers, this should be line 9 for them to line up

using namespace std;

// Instances of the location class are declared in "LocationList.h"
//Variables and functions are declared in "Declerations.h"

Location currentLocation = house; // Set a variable called currentLocation to the location that I want the game to start in (check LocationList.h to see locations)
string playerName;
Player player = Player("playerName", 100, 1, {});

int main()
{
    cout << "Enter your name: ";
    cin >> ws;
    getline(cin, playerName);
    player.set_player_name(playerName);
    while (true) { // Game loop that allows the user to move around the map by printing out the current location and then running a function to take their choice for the next location
        system("cls"); // Clear the terminal
        currentLocation.print_location(); // Runs the print_location() function of the currentLocation. Check Location.cpp to see function
        currentLocation = make_choice(); // Sets the currentLocation to the value returned by the make_choice() function.
    }
    
}

Location make_choice() { // Function to take user input, do different things depending on input, and then return what the new currentLocation is
    string playerChoice; // String for player input
    bool optionFound = false; // boolean to say if what the player inputted was one of the options available to them

    while (true) { // While loop to keep looping until the player enters a valid input
        cin.clear();
        
        getline(cin, playerChoice); // Takes player input
        if (playerChoice == "Talk to " + (*currentLocation.get_npc()).get_npc_name() && (*currentLocation.get_npc()).get_npc_defeated() == false) { // If the player inputs "talk to" and then the name of the npc at the current location, and the npc isn't defeated
            if (encounter_npc((*currentLocation.get_npc())) == true) { // Runs the encounter_npc() function using the current npc as a parameter and checks if the function returns true

                (*currentLocation.get_npc()).set_npc_defeated(true); // Set the currentLocation's npc to be defeated
            }
            
            optionFound = true; // Sets optionFound to true 
        }
        else{
            for (auto location : currentLocation.get_options()){ // Inside the "LocationList.h" file, when declaring new instances of the location class, a vector of strings is inputted which is printed out later to tell the user what their options are (which locations they can move to). This line loops through that vector
                if (playerChoice == location) { // Checks to see if what the user inputted is actually one of the options pritned out for them
                    for (auto &loc : listOfLocations){ // Loops through a vector ListOfLocations which is declared in "LocationList.h". This stores the instances of the location class
                        if (playerChoice == loc.get_location_name()) { // Find out which location the user inputted
                            optionFound = true; // Sets optionFound to true
                            if (loc.get_locked() == false) { // If the location isn't locked
                                currentLocation = loc; // Sets the current location to that location
                            }
                            else { // If the location is locked
                                bool playerHasKey = false; // Variable to see if the player has the key to unlock the location
                   
                                for (auto item : player.get_player_inventory()) { // Loops through the player's inventory
                                    if (item == loc.get_item_to_unlock()) { // If the player has the item that is set as the location's "item to unlock" variable
                                      
                                        playerHasKey = true; // Set playerHasKey variable to true
                                    }
                                }
                                if (playerHasKey == true) { // If playerHasKey is true
                                    currentLocation = loc; // Set the current location to the new location the player selected
                                }
                                else { // If PlayerHasKey is false
                                    type_text("That location is locked... To unlock it you must have a " + loc.get_item_to_unlock()); // Tell the player the location is locked
                                    cout << "\n" << "Press a key to continue...";
                                    cout << _getch();
                                }
                                
                            }
                            
                            break; // Breaks out of the loop after finding the right location
                        }
                    }
                    break; // Breaks out of the loop after finding the right option
                }
            }
        }
        if (playerChoice == "Check inventory") {
            for (auto item : player.get_player_inventory()) {
                cout << item << "\n";
            }
            cout << "\n" << "Press a key to continue...";
            cout << _getch();
            optionFound = true;
        }
        
        if (optionFound == false) { 
            cout << "That isn't an option" << endl; // If the user inputs an option that isn't available to them, tell them it isn't an option, then go back to the start of the while loop on line 31
        }
        else {
            return currentLocation; // If the user did enter a valid input, return the currentLocation (which has now been updated to whatever the player inputted)
            break; // Break out of while loop
        }
    }

   
}

void type_text(const string& text)
{
    // loop through each character in the text
    for (size_t i = 0; i < text.size(); ++i)
    {
        // output one character
        // flush to make sure the output is not delayed
        cout << text[i] << flush;

        // sleep 30 milliseconds
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}

bool encounter_npc(NPC npc) { // Function to be ran when the player talks to an NPC
    system("cls");
    npc.print_npc_info(); // Prints out the npc info using the function print_npc_info() (declared in NPC.cpp)
    if (npc.get_npc_dialogue_func() == 1) { // Runs the dialogue function of the current npc and checks if it returns 1
        return true; // Returns true, which is checked back on line 36
    }
    else {
        return false;
    }
    
}

string battle(NPC opponent)
{
    string result;
    while (opponent.get_npc_health() > 0)
    {
        system("cls");
        cout << "Name: " << player.get_player_name() << " | Health: " << player.get_player_health() << " | Level: " << player.get_player_level() << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << endl;
        cout << "VS" << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Name: " << opponent.get_npc_name() << " | Health: " << opponent.get_npc_health() << " | Level: " << opponent.get_npc_level() << endl;
        cout << endl;
        int playerDamage = player.get_player_level() * 5;
        int oppDamage;

        this_thread::sleep_for(chrono::milliseconds(100));

        auto item = danceMoves.begin();
        advance(item, rand() % danceMoves.size());
        string randomKey = item->first;
        oppDamage = (item->second) * opponent.get_npc_level();
        type_text(opponent.get_npc_name() + " uses " + randomKey);
        cout << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(100));

        int dodgeChance = rand() % 100;
        if (dodgeChance < 20)
        {
            type_text("You closed your eyes just in time to avoid looking at your opponents sick moves, you don't take any damage");
            cout << endl;
            cout << endl;
        }
        else
        {
            type_text("Your opponent's moves were too fire, you take " + to_string(oppDamage) + " damage!");
            cout << endl;
            cout << endl;
            player.set_player_health(player.get_player_health() - oppDamage);
            type_text("Your health is now " + to_string(player.get_player_health()));
            cout << endl;
            cout << endl;

            if (player.get_player_health() <= 0) {
                this_thread::sleep_for(chrono::milliseconds(100));
                type_text("You have been defeated...");
                result = "lost";
                break;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(100));

        int attackChoice = attack();
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << endl;
        cout << endl;
        if (attackChoice == 1)
        {
            type_text("You deal " + to_string(playerDamage) + " damage to " + opponent.get_npc_name());
            opponent.set_npc_health(opponent.get_npc_health() - playerDamage);
            cout << endl;
            cout << endl;
            type_text("Your opponent's health is now " + to_string(opponent.get_npc_health()));
        }
        else if (attackChoice == 2)
        {
            if (rand() % 10 > 5) {
                if (player.get_player_health() < 100) {
                    type_text("You successfully healed yourself for " + to_string(player.get_player_level() * 10) + " health");
                    player.set_player_health(player.get_player_health() + 10);
                }
                else {
                    type_text("You are already at full health");
                }
            }
            else {
                type_text("Your dance moves weren't good enough, you were unsuccessful in healing yourself.");
            }
        }
        else if (attackChoice == 3) {
            if (rand() % 10 > 1) {
                type_text("You performed the running man and ran away");
                cout << endl;
                cout << endl;
                this_thread::sleep_for(chrono::milliseconds(100));
                type_text("You have been healed back to 100 health");
                cout << endl;
                cout << endl;
                this_thread::sleep_for(chrono::milliseconds(100));
                player.set_player_health(100);
                break;
            }
            else {
                type_text("You didn't running man fast enough, you failed to escape");
            }
        }

        if (opponent.get_npc_health() <= 0) {
            cout << endl;
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            type_text("You have defeated " + opponent.get_npc_name() + " with your sick dance moves!");
            cout << endl;
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            type_text("You have been healed back to 100 health");
            player.set_player_health(100);
            result = "won";
        }
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << endl;
        cout << endl;
        cout << "Press a key to continue" << endl;
        cout << _getch();
        system("cls");
    }

    if (result == "lost") {
        return "lost";
    }
    else if (result == "won") {
        return "won";
    }
    else {
        return " ";
    }

}

int attack()
{
    int choice;

    while (true)
    {
        type_text("Choose a move:");
        cout << endl;
        cout << endl;

        cout << "Worm (attack)" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "Shuffle (chance to heal)" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "Running Man (chance to run away)" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));

        cout << endl;

        string playerChoice;
        cout << "Choice (Enter a number from 1-3): ";
        getline(cin >> ws, playerChoice);

        this_thread::sleep_for(chrono::milliseconds(100));
        if (playerChoice == "1" or playerChoice == "2" or playerChoice == "3")
        {
            choice = stoi(playerChoice);
            cout << endl;
            cout << endl;
            break;
        }
        else
        {
            type_text("That isn't a number between 1 and 3... try again.");
            cout << endl;
            cout << endl;
        }
    }

    if (choice == 1)
    {
        type_text("You chose Worm. You drop on the floor and wiggle like there's no tomorrow.");
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    else if (choice == 2)
    {
        type_text("You chose Shuffle. You do your best impression of the penguin from happy feet.");
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    else if (choice == 3)
    {
        type_text("You chose Running Man. You attempt to flee the scene... in style.");
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return choice;
}


int GoldSpandexManDialogue(){ // Specific NPC dialogue function. Each NPC has their own dialogue function containing outputs and inputs allowing the player to have a conversation with the NPC.
    type_text("Hey, you there! I'm gold spandex man! Fight me!");
    cout << endl;
    cin.clear();
    string battleResult = battle(GoldSpandexMan);
    if (battleResult == "won") {
        player.add_to_inventory("barKey"); // Add the "BarKey" item to the player's inventory
        type_text("You have gained +1 barKey");
        cout << "\n" << "Press a key to continue...";
        cout << _getch();
        return 1; // Returning 1 means the NPC is defeated, which is checked by encounter_npc() on line 74, which ultimately sets the "defeated" variable of the current npc to true on line 38
    }
    else if(battleResult == "lost") {
        cout << "YOU HAVE LOST" << endl;
        _getch();
        return 0;
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
        player.add_to_inventory("townKey");
        type_text("You have gained +1 townKey");
        cout << "\n" << "Press a key to continue...";
        cout << _getch();
        return 1;
    }
    else {
        return 0;
    }
}

int fredDialogue() { // Specific NPC dialogue function
    cout << "Hi I'm Fred" << endl;
    cin.clear();
    string choice;
    getline(cin, choice);
    if (choice == "defeat") {
        player.add_to_inventory("dungeonKey");
        type_text("You have gained +1 dungeonKey");
        cout << "\n" << "Press a key to continue...";
        cout << _getch();
        return 1;
    }
    else {
        return 0;
    }
}

