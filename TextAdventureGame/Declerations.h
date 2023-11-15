#pragma once
#include "Location.h"
#include "NPC.h"
#include "Player.h"


Location make_choice();

bool encounter_npc(NPC npc);

int GoldSpandexManDialogue();
int bobDialogue();
int fredDialogue();


NPC GoldSpandexMan = NPC("GoldSpandexMan", 3, GoldSpandexManDialogue);
NPC Bob = NPC("Bob", 100, bobDialogue);
NPC Fred = NPC("Fred", 10, fredDialogue);

NPC defaultNPC = NPC("", 0, 0);

