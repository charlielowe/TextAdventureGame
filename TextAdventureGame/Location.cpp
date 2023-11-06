#include "Location.h"
#include "NPC.h"

Location::Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation, NPC newNPC)
{
    this->locationName = newLocationName;
    this->asciiImageOfLocation = newAsciiImageOfLocation;
    this->textPrintedAtLocation = newTextPrintedAtLocation;
    this->optionsPrintedAtLocation = newOptionsPrintedAtLocation;
    this->npc = newNPC;
}

void Location::print_location()
{
    cout << this->asciiImageOfLocation << '\n';
    cout << '\n';
    cout << this->textPrintedAtLocation << '\n';
    cout << '\n';
    cout << "Choose an option: " << '\n';
    for (auto option : this->optionsPrintedAtLocation) {
        cout << option << '\n';
    }

    if (npc.npcName != "" && npc.defeated == false) {
        cout << "Talk to " << npc.npcName << endl;
    }
    cout << '\n';
}