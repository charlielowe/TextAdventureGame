#pragma once
#include <string>
#include <functional>

class NPC
{
private:
	std::string npcName;
	int npcLevel;
	int npcHealth;
	int npcDamage;
	std::function<int()> npcDialogueFunction;
	bool defeated;

public:

	NPC() : npcName(""), npcLevel(0), npcHealth(0), npcDamage(0), defeated(false){}
	~NPC() = default;

	NPC(std::string newNpcName, int newNpcLevel, std::function<int()> dialogueFunction);

	std::string get_npc_name();
	int get_npc_level();
	int get_npc_health();
	int get_npc_damage();
	int get_npc_dialogue_func();
	bool get_npc_defeated();

	void set_npc_defeated(bool isDefeated);

	void print_npc_info();
};

