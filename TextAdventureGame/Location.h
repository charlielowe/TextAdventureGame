#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NPC.h"

using namespace std;

class Location
{
public:
	string locationName;
	string asciiImageOfLocation;
	string textPrintedAtLocation;
	vector<string> optionsPrintedAtLocation;
	NPC npc;

	Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation, NPC newNPC);

	void print_location();
};

