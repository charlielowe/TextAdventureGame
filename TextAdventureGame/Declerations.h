#pragma once
#include "Location.h"
#include "NPC.h"


Location make_choice();

bool encounter_npc(NPC npc);

int GoldSpandexManDialogue();

NPC GoldSpandexMan = NPC("GoldSpandexMan", 3, GoldSpandexManDialogue);
NPC SilverSpandexMan = NPC("SilverSpandexMan", 100, GoldSpandexManDialogue);
NPC emtpy = NPC("", 0, 0);