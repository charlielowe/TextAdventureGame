#pragma once
#include <string>
#include <functional>

class NPC
{
public:
	std::string npcName;
	int npcLevel;
	int npcHealth;
	int npcDamage;
	std::function<int()> npcDialogueFunction;
	bool defeated;

	NPC() : npcName(""), npcLevel(0), npcHealth(0), npcDamage(0), defeated(false){}
	~NPC() = default;

	NPC(std::string newNpcName, int newNpcLevel, std::function<int()> dialogueFunction);

	void print_npc_info();
};

