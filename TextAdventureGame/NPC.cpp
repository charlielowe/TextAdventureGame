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

void NPC::print_npc_info() {
	std::cout << "Name: " << npcName << "\n";
	std::cout << "Level: " << npcLevel << "\n";
	std::cout << "Health: " << npcHealth << "\n";
	std::cout << std::endl;
}
