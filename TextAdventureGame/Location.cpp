#include "Location.h"
Location::Location(string newLocationName, string newAsciiImageOfLocation, string newTextPrintedAtLocation, vector<string> newOptionsPrintedAtLocation)
{
    this->locationName = newLocationName;
    this->asciiImageOfLocation = newAsciiImageOfLocation;
    this->textPrintedAtLocation = newTextPrintedAtLocation;
    this->optionsPrintedAtLocation = newOptionsPrintedAtLocation;
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
    cout << '\n';
}