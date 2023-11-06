#pragma once
#include "Location.h"
#include "NPC.h"


Location make_choice();

bool encounter_npc(NPC npc);

int GoldSpandexManDialogue();
int bobDialogue();


NPC GoldSpandexMan = NPC("GoldSpandexMan", 3, GoldSpandexManDialogue);
NPC Bob = NPC("Bob", 100, bobDialogue);


NPC emtpy = NPC("", 0, 0);
