#include "Location.h"
#include "NPC.h"


Location::Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation, NPC *newNPC, bool locked, string itemToUnlock)
  {
    this->locationName = newLocationName;
    this->asciiImageOfLocation = newAsciiImageOfLocation;
    this->textPrintedAtLocation = newTextPrintedAtLocation;
    this->optionsPrintedAtLocation = newOptionsPrintedAtLocation;
    this->npc = newNPC;
    this->locked = locked;
    this->itemToUnlock = itemToUnlock;
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

string Location::get_item_to_unlock() {
    return this->itemToUnlock;
}

void Location::print_location()
{
    cout << this->asciiImageOfLocation << '\n';
    cout << '\n';
    type_text(this->textPrintedAtLocation + '\n');
    cout << '\n';
    cout << "Choose an option: " << '\n';
    for (auto option : this->optionsPrintedAtLocation) {
        cout << option << '\n';
    }

    if ((*npc).get_npc_name() != "" && (*npc).get_npc_defeated() == false) {
        cout << "Talk to " << (*npc).get_npc_name() << endl;
    }
    cout << "Check inventory" << endl;
}

bool Location::get_locked() {
    return this->locked;
}

void Location::set_locked(bool isLocked) {
    this->locked = isLocked;
}