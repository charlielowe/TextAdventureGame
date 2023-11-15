#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NPC.h"


using namespace std;

void type_text(const string& text);

class Location
{
private:
	string locationName;
	string asciiImageOfLocation;
	string textPrintedAtLocation;
	vector<string> optionsPrintedAtLocation;
	NPC *npc;
	bool locked;
	string itemToUnlock;
public:

	Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation, NPC *newNPC, bool locked = false, string itemToUnlock = "");

	string get_location_name();
	vector<string> get_options();
	NPC* get_npc();
	string get_item_to_unlock();
	void print_location();
	bool get_locked();
	void set_locked(bool isLocked);
};

