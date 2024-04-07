#include "G_game_functions.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>


void create_player(Player* player, const char* name, CharacterClass char_class) {
	errno_t err;
	err = strcpy_s(player->name, sizeof(player->name), name, _TRUNCATE);
	if (err != 0) {
		printf("Error copying name :%d\n",err);
	}

	player->char_class = char_class;
	player->level = 1;
	player->health = 100;

	switch (char_class)
	{
	case Warrior:
		player->ability.strength = 10;
		break;
	case Mage:
		player->ability.mana = 50;
		break;
	case Rogue:
		player->ability.stealth = 20;
		break;
	}
};

Enemy generate_enemy(EnemyType type, int32_t level) {
	Enemy enemy;
	enemy.type = type;
	enemy.level = level;
	enemy.health = level * 20;

	switch (type)
	{
	case Goblin:
		enemy.ability.strength = 5 * level;
		break;
	case Troll:
		enemy.ability.strength = 10 * level;
		break;
	case Dragon:
		enemy.ability.mana = 100 * level;
		break;
	}
	return enemy;
};

void battle(Player* player, Enemy* enemy) {
	printf("%s encounters a level %d %d! A battle begins...\n",player->name,enemy->level,enemy->type);

	//假设战斗总能win
	player->exp += 50;
	printf("%s has defeated the enemy and gained 50 exp points.\n",player->name);
};

void print_player_info(const Player* player) {
	printf("Player Info : %s \n",player->name);
	printf("Class: %d, Level: %d, Health: %d\n",player->char_class,player->level,player->health);
};

void print_enemy_info(const Enemy* enemy) {
	printf("Enemy Info: Type %d, Level %d, Health %d\n",enemy->type,enemy->level,enemy->health);
};

void init(void) {
	puts("Welcome to the Text RPG Game!\n");

	Player player;
	create_player(&player, "frank", Warrior);
	Enemy enemy = generate_enemy(Dragon, 1);

	battle(&player, &enemy);

	print_player_info(&player);
	print_enemy_info(&enemy);
}