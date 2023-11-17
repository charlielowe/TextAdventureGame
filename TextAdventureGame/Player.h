#pragma once
#include <string>
#include <vector>
class Player
{
private:
	std::string playerName;
	int playerHealth;
	int playerLevel;
	std::vector<std::string> playerInventory;

public:
	Player(std::string NewPlayerName, int newPlayerHealth, int newPlayerLevel, std::vector<std::string> newPlayerInventory);

	std::string get_player_name();
	int get_player_health();
	int get_player_level();
	std::vector<std::string> get_player_inventory();

	void set_player_name(std::string playerName);
	void set_player_health(int playerHealth);
	void set_player_level(int playerLevel);
	void add_to_inventory(std::string item);


};

