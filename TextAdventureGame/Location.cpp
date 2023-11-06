#include "Location.h"
#include "NPC.h"

Location::Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation, NPC *newNPC)
  {
    this->locationName = newLocationName;
    this->asciiImageOfLocation = newAsciiImageOfLocation;
    this->textPrintedAtLocation = newTextPrintedAtLocation;
    this->optionsPrintedAtLocation = newOptionsPrintedAtLocation;
    this->npc = newNPC;
}

string Location::get_location_name() {
    return this->locationName;
}

vector<string> Location::get_options() {
    return this->optionsPrintedAtLocation;
}

NPC* Location::get_npc() {
    return this->npc;
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

    if ((*npc).get_npc_name() != "" && (*npc).get_npc_defeated() == false) {
        cout << "Talk to " << (*npc).get_npc_name() << endl;
    }
    cout << '\n';
}