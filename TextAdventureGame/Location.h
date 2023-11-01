#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Location
{
public:
	string locationName;
	string asciiImageOfLocation;
	string textPrintedAtLocation;
	vector<string> optionsPrintedAtLocation;

	Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation);

	void print_location();
};

