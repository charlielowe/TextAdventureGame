#pragma once
#include "Location.h"
#include "NPC.h"
#include "Player.h"
#include <map>

int textDelayTime;

Location make_choice();
void set_text_delay_time();
bool encounter_npc(NPC npc);
string battle(NPC opponent);
int attack();
void level_up();
void lose_game();
void win_game();

int shady_man_dialogue();
int warehouse_boss_dialogue();

map<string, int> danceMoves = { {"Box Step", 5}, {"Floss", 4}, {"Moon Walk", 6}, {"Default Dance", 5}, {"Pirouette", 3}, {"Twist", 4}, {"Cha Cha Slide", 6}, {"Macarena", 3}, {"Pop and Lock", 2} };


NPC shadyMan = NPC("Shady Man", 3, shady_man_dialogue);
NPC bigWarehouseBoss = NPC("Big Warehouse Boss", 7, warehouse_boss_dialogue);

NPC defaultNPC = NPC("", 0, 0);

