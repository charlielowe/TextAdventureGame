#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NPC.h"

using namespace std;

class Location
{
private:
	string locationName;
	string asciiImageOfLocation;
	string textPrintedAtLocation;
	vector<string> optionsPrintedAtLocation;
	NPC *npc;
public:
	Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation, NPC *newNPC);

	string get_location_name();
	vector<string> get_options();
	NPC* get_npc();
	void print_location();
};

