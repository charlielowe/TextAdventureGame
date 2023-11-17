#include "Player.h"

Player::Player(std::string NewPlayerName, int newPlayerHealth, int newPlayerLevel, std::vector<std::string> newPlayerInventory) {
	this->playerName = NewPlayerName;
	this->playerHealth = newPlayerHealth;
	this->playerLevel = newPlayerLevel;
	this->playerInventory = newPlayerInventory;
}

std::string Player::get_player_name() {
	return this->playerName;
}

int Player::get_player_health() {
	return this->playerHealth;
}

int Player::get_player_level() {
	return this->playerLevel;
}

std::vector<std::string> Player::get_player_inventory() {
	return this->playerInventory;
}

void Player::set_player_name(std::string playerName) {
	this->playerName = playerName;
}

void Player::set_player_health(int playerHealth) {
	this->playerHealth = playerHealth;
}

void Player::set_player_level(int playerLevel) {
	this->playerLevel = playerLevel;
}

void Player::add_to_inventory(std::string item) {
	this->playerInventory.push_back(item);
}

