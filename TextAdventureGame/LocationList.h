#pragma once
#include "Location.h"
#include "Declerations.h"

//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------

Location house = Location("House", "(O_O)", "You are inside your house. It is a small damp appartment.", { "Street" }, &defaultNPC);

//----------------------------------------------------------------------------------------

Location street = Location("Street", "| S T R E E T |", "You walk down a dark street. There is a bar on one side and a big warehouse on the other.", { "House", "Warehouse", "Bar"}, &defaultNPC);

//----------------------------------------------------------------------------------------

Location bar = Location("Bar", "| B A R |", "You go inside the bar, it's bright, fun, and packed with people.", { "Street" }, &shadyMan);

//----------------------------------------------------------------------------------------

Location warehouse = Location("Warehouse", "| W A R E H O U S E |", "You go inside the warehouse. There are thousands of machines moving and working to create... something...", { "Street" }, &bigWarehouseBoss, true, "warehouse key");

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

vector<Location> listOfLocations = { house, street, bar, warehouse };