#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <thread>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "Location.h"
#include "LocationList.h"
#include "Declerations.h"
#include "NPC.h"
#include "Player.h"

using namespace std;

// Instances of the location class are declared in "LocationList.h"
// Variables and functions are declared in "Declerations.h"

Location currentLocation = house; // Set a variable called currentLocation to the location that I want the game to start in (check LocationList.h to see locations)
Player player = Player("playerName", 100, 2, {"Useless piece of string"}); // Creates an instance of the player class called player and sets the values
int sleepTime = 1000; // A varaible that is passed into the sleep_for() function throughout the program

int main()
{
    srand(time(0)); // Set the random number seed to time which is constantly changing, this is so the random numbers aren't the same each time
    set_text_delay_time();
    system("cls");
    cout << R"(

    ,o888888o.  `8.`8888.      ,8' 8 888888888o   8 8888888888   8 888888888o.             8 8888888888   8 8888      88 b.             8 8 8888     ,88'
   8888     `88. `8.`8888.    ,8'  8 8888    `88. 8 8888         8 8888    `88.            8 8888         8 8888      88 888o.          8 8 8888    ,88'
,8 8888       `8. `8.`8888.  ,8'   8 8888     `88 8 8888         8 8888     `88            8 8888         8 8888      88 Y88888o.       8 8 8888   ,88'
88 8888            `8.`8888.,8'    8 8888     ,88 8 8888         8 8888     ,88            8 8888         8 8888      88 .`Y888888o.    8 8 8888  ,88'
88 8888             `8.`88888'     8 8888.   ,88' 8 888888888888 8 8888.   ,88'            8 888888888888 8 8888      88 8o. `Y888888o. 8 8 8888 ,88'
88 8888              `8. 8888      8 8888888888   8 8888         8 888888888P'             8 8888         8 8888      88 8`Y8o. `Y88888o8 8 8888 88'
88 8888               `8 8888      8 8888    `88. 8 8888         8 8888`8b                 8 8888         8 8888      88 8   `Y8o. `Y8888 8 888888<
`8 8888       .8'      8 8888      8 8888      88 8 8888         8 8888 `8b.               8 8888         ` 8888     ,8P 8      `Y8o. `Y8 8 8888 `Y8.
   8888     ,88'       8 8888      8 8888    ,88' 8 8888         8 8888   `8b.             8 8888           8888   ,d8P  8         `Y8o.` 8 8888   `Y8.
    `8888888P'         8 8888      8 888888888P   8 888888888888 8 8888     `88.           8 8888            `Y88888P'   8            `Yo 8 8888     `Y8.


        )" << '\n';
    cout << endl;
    cout << "(Please play using full screen)" << endl;
    
    cout << endl;
    cout << "Enter your name: "; // Ask for the player's name
    string playerName; // String variable for the player's name
    getline(cin >> ws, playerName); // Take in the user's input
    player.set_player_name(playerName); // Set the player's name to whatever they inputted
    cout << endl;
    type_text("Welcome to Cyber Funk, " + player.get_player_name() + ", a sci-fi adventure set in a futuristic world where humans have used technological enhancements to make themselves near-invincible, and the only way they can be harmed is through the psychological damage incurred by their opponent busting a sick move on the dance floor. Can you worm, moonwalk and boogie your way through the criminal underworld?... Let's find out. (Press any key to continue).");
    _getch(); // Pause the program until a button is pressed
    while (true) { // Game loop that allows the user to move around the map by printing out the current location and then running a function to take their choice for the next location
        system("cls"); // Clear the terminal
        currentLocation.print_location(); // Runs the print_location() function of the currentLocation. Check Location.cpp to see function
        currentLocation = make_choice(); // Sets the currentLocation to the value returned by the make_choice() function.
    }
    
}

// Function to let the player choose if they want the text to be printed one character at a time or all at once
void set_text_delay_time() { 
    textDelayTime = 30; // Set textDelayTime to 30 so the type_text function prints one character at a time in this function to give the user an example of what it will look like
    cout << endl;
    type_text("Would you like the text to be printed one character at a time for dramatic effect (like it's currently doing), or all at once for if you don't have much time?"); // Ask the player if they would like the text to be printed one character at a time or all at once
    cout << endl;
    cout << endl;
    cout << "Enter 1 for the text to be printed one character at a time." << endl;
    cout << endl;
    cout << "Enter 2 for the text to be printed all at once." << endl;
    cout << endl;
    
    while (true) { // While loop
        cout << "Enter choice: "; // Ask for the player's choice
        string textDelayChoice; // String variable for the player's choie
        getline(cin >> ws, textDelayChoice); // Take in the user's input
        if (textDelayChoice == "1") { // If the user inputted 1
            textDelayTime = 30; // Set the textDelayTime to 30. This variable is used in the type_text() function
            break; // Break out of the while loop
        }
        else if (textDelayChoice == "2") { // If the user inputted 2
            textDelayTime = 0; // Set the textDelayTime to 0
            break;
        }
        else {
            cout << endl;
            cout << "That isn't an option. Try again." << endl;
        }
    }
}

// Function to take user input, do different things depending on input, and then return what the new currentLocation is
Location make_choice() { 
    string playerChoice; // String for player input
    bool optionFound = false; // boolean to say if what the player inputted was one of the options available to them

    while (true) { // While loop to keep looping until the player enters a valid input
        cin.clear();
        cout << "\n" << "Enter your choice: ";
        
        getline(cin, playerChoice); // Takes player input
        transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::tolower); // Set it to lowercase so it doesn't matter if the user inputs capitals or not
        string currentNpcName = (*currentLocation.get_npc()).get_npc_name(); // Create a variable for the current NPC's name
        transform(currentNpcName.begin(), currentNpcName.end(), currentNpcName.begin(), ::tolower); // Set it to lowercase as well to compare to the user input
        if (playerChoice == "talk to " + currentNpcName && (*currentLocation.get_npc()).get_npc_defeated() == false) { // If the player inputs "talk to" and then the name of the npc at the current location, and the npc isn't defeated, run the following code
            
            if (encounter_npc((*currentLocation.get_npc())) == true) { // Runs the encounter_npc() function using the current npc as a parameter and checks if the function returns true

                (*currentLocation.get_npc()).set_npc_defeated(true); // Set the currentLocation's npc to be defeated
            }
            
            optionFound = true; // Sets optionFound to true 
        }
        else{
            for (auto location : currentLocation.get_options()){ // Inside the "LocationList.h" file, when declaring new instances of the location class, a vector of strings is inputted which is printed out later to tell the user what their options are (which locations they can move to). This line loops through that vector
                transform(location.begin(), location.end(), location.begin(), ::tolower); // Sets the item in the get_options array to lowercase as I set the playerChoice variable to lowercase earlier, and this way it doesn't matter if the user enters caps or not as both the input and option are being set to lowercase
                if (playerChoice == location) { // Checks to see if what the user inputted is actually one of the options pritned out for them
                    for (auto &loc : listOfLocations){ // Loops through a vector ListOfLocations which is declared in "LocationList.h". This stores the instances of the location class
                        string currentLocationName = loc.get_location_name(); // Create a variable for the name of the current location
                        transform(currentLocationName.begin(), currentLocationName.end(), currentLocationName.begin(), ::tolower); // Set it to lowercase as well
                        if (playerChoice == currentLocationName) { // Find out which location the user inputted
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
                                else { // If playerHasKey is false
                                    type_text("That location is locked... To unlock it you must have a " + loc.get_item_to_unlock()); // Tell the player the location is locked
                                    cout << "\n" << "Press a key to continue...";
                                    _getch();
                                }
                                
                            }
                            
                            break; // Breaks out of the loop after finding the right location
                        }
                    }
                    break; // Breaks out of the loop after finding the right option
                }
            }
        }
        if (playerChoice == "check inventory") { // If the player chooses to check their inventory
            cout << "\n";
            for (auto item : player.get_player_inventory()) { // Loops through the inventory
                cout << item << "\n"; // Prints out each item
            }
            cout << "\n" << "Press a key to continue...";
            _getch();
            cout << endl;
        }
        else if (optionFound == false) { 
            cout << "That isn't an option" << endl; // If the user inputs an option that isn't available to them, tell them it isn't an option, then go back to the start of the while loop
        }
        else {
            return currentLocation; // If the user did enter a valid input, return the currentLocation (which has now been updated to whatever the player inputted)
            break; // Break out of while loop
        }
    }

   
}

// Function to output text one character at a time.
void type_text(const string& text) 
{
    // loop through each character in the text
    for (size_t i = 0; i < text.size(); ++i)
    {
        // output one character
        // flush to make sure the output is not delayed
        cout << text[i] << flush;
       
        this_thread::sleep_for(chrono::milliseconds(textDelayTime)); // sleep 30 milliseconds or 0 milliseconds depending on what the user chose at the start of the game when the set_text_delay_time() function ran
    }
}

// Function to be ran when the player talks to an NPC
bool encounter_npc(NPC npc) { 
    system("cls");
    npc.print_npc_info(); // Prints out the npc info using the function print_npc_info() (declared in NPC.cpp)
    if (npc.get_npc_dialogue_func() == 1) { // Runs the dialogue function of the current npc and checks if it returns 1
        return true; // Returns true
    }
    else {
        return false;
    }
    
}

// Function to start a turn based battle with an NPC. Takes in an instance of the NPC class as a parameter
string battle(NPC opponent) 
{
    string result = " "; // String that gets returned at the end of the function. Will either be won or lost, or emtpy if the player escapes the battle
    while (opponent.get_npc_health() > 0) // Loop that runs until you defeat the NPC
    {
        system("cls"); // Clears the screen
        cout << "Name: " << player.get_player_name() << " | Health: " << player.get_player_health() << " | Level: " << player.get_player_level() << endl; // Prints out your name and info
        this_thread::sleep_for(chrono::milliseconds(sleepTime)); // Brief pause
        cout << endl;
        cout << "VS" << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
        cout << "Name: " << opponent.get_npc_name() << " | Health: " << opponent.get_npc_health() << " | Level: " << opponent.get_npc_level() << endl; // Prints out the opponent's name and info
        cout << endl;
        int playerDamage = player.get_player_level() * 5; // Creates a player damage variable which is equal to the player's level * 5
        int oppDamage; // Creates an opponent damage variable which is set later

        this_thread::sleep_for(chrono::milliseconds(sleepTime));

        auto item = danceMoves.begin(); // Creates a variale which is the first item in the danceMoves Map found in Declerations.h
        advance(item, rand() % danceMoves.size()); // Advances the item a random amount forward in the map
        string randomKey = item->first; // Creates a variable for the key of the item
        oppDamage = (item->second) * opponent.get_npc_level(); // Sets the opponent damage to the value of the item multiplied by the opponent's level
        type_text(opponent.get_npc_name() + " uses " + randomKey); // Outputs what move the NPC used
        cout << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));

        if ((rand() % 100) <= 20) // If a random number between 0 and 99 is less than or equal to 20, this line runs
        {
            type_text("You closed your eyes just in time to avoid looking at your opponents sick moves, you don't take any damage"); // Say that you don't take any damage
            cout << endl;
            cout << endl;
        }
        else // If the random number was over 20
        {
            type_text("Your opponent's moves were too fire, you take " + to_string(oppDamage) + " damage!"); // Output how much damage you take
            cout << endl;
            cout << endl;
            player.set_player_health(player.get_player_health() - oppDamage); // Decrease the player's health by the damage amount
            type_text("Your health is now " + to_string(player.get_player_health())); // Output the player's new health
            cout << endl;
            cout << endl;

            if (player.get_player_health() <= 0) { // If the player is dead
                this_thread::sleep_for(chrono::milliseconds(sleepTime));
                type_text("You have been defeated..."); // Tell them they were defeated
                result = "lost"; // Set result variable to lost
                break; // Break out of loop
            }
        }
        this_thread::sleep_for(chrono::milliseconds(sleepTime));

        int attackChoice = attack(); // Create variable called attack choice and set it to the value returned by the attack() function which is found below this function
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
        cout << endl;
        cout << endl;
        if (attackChoice == 1) // If the choice was 1
        {
            type_text("You deal " + to_string(playerDamage) + " damage to " + opponent.get_npc_name()); // Tell the player how much damage they delt
            opponent.set_npc_health(opponent.get_npc_health() - playerDamage); // Decrease the NPC's health by the playerDamage amount
            cout << endl;
            cout << endl;
            type_text("Your opponent's health is now " + to_string(opponent.get_npc_health())); // Output the NPC's new health
        }
        else if (attackChoice == 2) // If the choice was 2
        {
            if ((rand() % 10) >= 2) { // If a random number between 0 and 9 is bigger than or equal to 2 this line runs
                if (player.get_player_health() < 100) { // If the player isn't already at full health
                    type_text("You successfully healed yourself for " + to_string(player.get_player_level() * 10) + " health"); // Output that you healed yourself for 10 times your level
                    player.set_player_health(player.get_player_health() + (player.get_player_level() * 10)); // Increase the player's health
                    if (player.get_player_health() > 100) { // If the player's health is now over 100
                        player.set_player_health(100); // Set it back to 100
                    }
                }
                else {
                    type_text("You are already at full health"); // If the player is at full health, tell the player and do nothing
                }
            }
            else {
                type_text("Your dance moves weren't good enough, you were unsuccessful in healing yourself.");
            }
        }
        else if (attackChoice == 3) { // If the choice was 3
            if (rand() % 10 >= 7) { // 30% chance to run this line
                type_text("You performed the running man and ran away"); // Tell the player the move was successful
                cout << endl;
                cout << endl;
                this_thread::sleep_for(chrono::milliseconds(sleepTime));
                type_text("You have been healed back to 100 health"); // Tell the player they've been healed
                cout << endl;
                cout << endl;
                this_thread::sleep_for(chrono::milliseconds(sleepTime));
                player.set_player_health(100); // Set the player's health to 100
                break; // Break out of the loop
            }
            else {
                type_text("You didn't running man fast enough, you failed to escape"); // If the 10% chance fails, do nothing
            }
        }

        if (opponent.get_npc_health() <= 0) { // If the opponent goes below 1 health
            cout << endl;
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(sleepTime));
            type_text("You have defeated " + opponent.get_npc_name() + " with your sick dance moves!"); // Output that you defeated the opponent
            cout << endl;
            cout << endl;
            this_thread::sleep_for(chrono::milliseconds(sleepTime));
            type_text("You have been healed back to 100 health"); // Tell the player they've been healed
            player.set_player_health(100); // Set the player's health to 100
            result = "won"; // Set the result variable to won
        }
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
        cout << endl;
        cout << endl;
        cout << "Press a key to continue" << endl;
        cin.clear();
        _getch(); // Pause the program until the player presses a key
        system("cls"); // Clears the screen
    }

    return result; // Returns the result

}

// Function that runs when the player attacks in the battle function
int attack() 
{
    int choice; // Create a choice variable

    while (true) // Infinite loop
    {
        type_text("Choose a move:"); // Ask the player to choose a move
        cout << endl;
        cout << endl;

        // List of moves below
        cout << "Worm (attack)" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "Shuffle (chance to heal)" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "Running Man (chance to run away)" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));

        cout << endl;

        string playerChoice; // String for the player's choice
        cout << "Choice (Enter a number from 1-3): "; // Tell the player to enter a number from 1 to 3
        getline(cin >> ws, playerChoice); // Take in the player's input

        this_thread::sleep_for(chrono::milliseconds(100));
        if (playerChoice == "1" or playerChoice == "2" or playerChoice == "3") // If the player entered a valid number
        {
            choice = stoi(playerChoice); // Convert the input to an int. Reason for doing this instead of taking an int as an input is if the player enters a string when the input type is int it causes problems
            cout << endl;
            break; // Breaks out of the while loop
        }
        else
        {
            type_text("That isn't a number between 1 and 3... try again."); // If they didn't enter one of the options tell them to try again and goes back to the begining of the while loop
            cout << endl;
            cout << endl;
        }
    }

    if (choice == 1) // If the player's choice was 1
    {
        type_text("You chose Worm. You drop on the floor and wiggle like there's no tomorrow."); // Output the attack they chose
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
    return choice; // Returns the choice the player made
}

// Function to level up the player
void level_up() { 
    type_text("What this?..."); // Text for dramatic effect with pauses7
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    type_text("You feel your dance moves improving!...");
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    type_text("You have levelled up!");
    player.set_player_level(player.get_player_level() + 1); // Increment the player's level by 1
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    cout << endl;
    cout << "You are now level " << player.get_player_level() << endl; // Output the player's new level
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    cout << "Press a key to continue." << endl; // Pause the program until the player presses a key
    cin.clear();
    _getch();
}

// Function for if the player loses the game
void lose_game() { 
    cout << endl;
    cout << "YOU LOSE HAHAH SUCKER!" << endl; // Some rather mean text telling the player they lost
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << "Press a key to end the game." << endl; // Tell the player to press any key to end the game
    cin.clear();
    _getch();
    exit(0); // After the uses presses a key, exit the game
}

// Function for if the player wins the game
void win_game() { 
    cout << endl;
    type_text("Congratulations, " + player.get_player_name() + " you have won the game. As a prize, you now get to grade this work! Hope you enjoyed."); // Tell the player they won
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    cout << endl;
    cout << "Press a key to end the game." << endl;
    cin.clear();
    _getch();
    exit(0); // Exit the game after the player presses a key
}

// Specific NPC dialogue function. Each NPC has their own dialogue function containing outputs and inputs allowing the player to have a conversation with the NPC.
int shady_man_dialogue(){ 
    type_text("Shady Man: What you lookin at? punk."); 
    cout << endl;
    cout << endl;
    
    while (true) { // Infinite loop
        cout << "Choose a response: (type the option you want to say)." << endl;
        cout << endl;
        cout << "Your beautiful face kind sir" << endl;
        cout << "Give me your key" << endl;
        cout << "FIGHT ME COWARD" << endl;
        cout << endl;
        cout << "Enter your choice: "; // Ask the player for input
        string playerChoice; // Variable for the player's choice
        cin.clear();
        getline(cin, playerChoice); // Take input
        cout << endl;
        transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::tolower); // Set it to lowercase so it doesn't matter if the user inputted capitals or not
        if (playerChoice == "your beautiful face kind sir") { // If the first option was chosen
            type_text("Shady Man: Why... thank you *blushes*... I still ain't giving you this key though!"); // Output text and go back to the start of the while loop
            cout << endl;
            cout << endl;
        }
        else if(playerChoice == "give me your key") { // If the second option was chosen
            type_text("Shady Man: NUH UH. LET'S FIGHT!");
            cout << endl;
            cout << endl;
            cout << "Press any key to start the fight." << endl;
            cin.clear();
            _getch(); // Pause the program until the player presses a key
            break; // Break out of the while loop
        }
        else if (playerChoice == "fight me coward") { // If the third option was chosen
            type_text("Shady Man: but that's really mean... ok I guess..."); 
            cout << endl;
            cout << endl;
            cout << "Press any key to start the fight." << endl;
            cin.clear();
            _getch();
            break; // Pause the program until the player presses a key and then break out of the while loop
        }
        else {
            cout << "That wasn't a choice was it?" << endl; // If the player entered something that wasn't an option, tell them and go back to the start of the loop
        }
    }
   

    string battleResult = battle(shadyMan); // Set a variable called battleResult to the output returned by the battle function, the shadyMan NPC instance is being passed into the function
    if (battleResult == "won") { // If the result returned was won
        type_text("Shady Man: You... you killed me? GOODBYE CRUEL WORLD!"); // Type some text
        cout << endl;
        cout << endl;
        player.add_to_inventory("warehouse key"); // Add the "warehouse key" item to the player's inventory
        type_text("You have gained +1 warehouse key"); // Tell the player they gained the key
        cout << endl;
        cout << "\n" << "Press a key to continue...";
        cin.clear();
        _getch(); // Pause until a key is pressed
        cout << endl;
        level_up(); // Run the level up function
        return 1; // Returning 1 means the NPC is defeated, which is checked by the encounter_npc() function
    }
    else if(battleResult == "lost") { // If the result returned was lost
        lose_game(); // Run the lose_game() function
    }
    else {
        return 0; // If they player didn't win or lose the battle (they ran away), return 0
    }
    
}

// Specific dialogue function for the big warehouse boss NPC. Very similar to the shady_man_dialogue() function. It prints some text, takes the user's input, and then runs the battle function
int warehouse_boss_dialogue() { 
    type_text("Big Warehouse Boss: Well well well... You've finally found me... the big boss at the end of the game.");
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    cout << endl;
    type_text("Big Warehouse Boss: What do you mean 'already?', what is the game not long enough for you? I'm on a deadline here! Anyway... You need to fight me in order to stop my big evil plan!");
    this_thread::sleep_for(chrono::milliseconds(sleepTime));
    cout << endl;
    cout << endl;
    cout << "What do you say in response?: ";
    cin.clear();
    string playerChoice;
    getline(cin >> ws, playerChoice);
    cout << endl;
    type_text("Big Warehouse Boss: Those words you just said... they hurt me... Right in my heart... I'm going to kill you now!");
    cout << endl;
    cout << endl;
    cout << "Press any key to start the fight." << endl;
    cin.clear();
    _getch();
    string battleResult = battle(bigWarehouseBoss);
    if (battleResult == "won") {
        type_text("Big Warehouse Boss: Well I uh... I may have overestimated myself... Now I'm dead. I guess you win the game. Congrats.");
        cout << endl;
        win_game();
    }
    else if (battleResult == "lost") {
        lose_game();
    }
    else {
        return 0;
    }
}


