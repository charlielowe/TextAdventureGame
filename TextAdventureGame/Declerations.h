#pragma once
#include "Location.h"
#include "NPC.h"
#include "Player.h"
#include <map>

Location make_choice();

bool encounter_npc(NPC npc);
string battle(NPC opponent);
int attack();

int GoldSpandexManDialogue();
int bobDialogue();
int fredDialogue();

map<string, int> danceMoves = { {"Box Step", 5}, {"Floss", 4}, {"Moon Walk", 6}, {"Default Dance", 5}, {"Pirouette", 3}, {"Twist", 4}, {"Cha Cha Slide", 6}, {"Macarena", 3}, {"Pop and Lock", 2} };


NPC GoldSpandexMan = NPC("GoldSpandexMan", 3, GoldSpandexManDialogue);
NPC Bob = NPC("Bob", 100, bobDialogue);
NPC Fred = NPC("Fred", 10, fredDialogue);

NPC defaultNPC = NPC("", 0, 0);

