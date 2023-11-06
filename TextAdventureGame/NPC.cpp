#include <iostream>
#include <string>
#include <functional>
#include "NPC.h"

NPC::NPC(std::string newNpcName, int newNpcLevel, std::function<int()> dialogueFunction)
{
	this->npcName = newNpcName;
	this->npcLevel = newNpcLevel;
	this->npcHealth = npcLevel * 10;
	this->npcDamage = npcLevel * 2;
	this->npcDialogueFunction = dialogueFunction;
	this->defeated = false;

}

std::string NPC::get_npc_name() {
	return this->npcName;
}

int NPC::get_npc_level() {
	return this->npcLevel;
}

int NPC::get_npc_health() {
	return this->npcHealth;
}

int NPC::get_npc_damage() {
	return this->npcDamage;
}

int NPC::get_npc_dialogue_func(){
	return this->npcDialogueFunction();
}

bool NPC::get_npc_defeated() {
	return this->defeated;
}

void NPC::set_npc_defeated(bool isDefeated) {
	this->defeated = isDefeated;
}

void NPC::print_npc_info() {
	std::cout << "Name: " << npcName << "\n";
	std::cout << "Level: " << npcLevel << "\n";
	std::cout << "Health: " << npcHealth << "\n";
	std::cout << std::endl;
}
