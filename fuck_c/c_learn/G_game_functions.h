#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include "G_game_structs.h"


//º¯ÊýÔ­ÐÍ
void create_player(Player* player,const char* name,CharacterClass char_class);

Enemy generate_enemy(EnemyType type,int32_t level);

void battle(Player* player,Enemy* enemy);

void print_player_info(const Player* player);

void print_enemy_info(const Enemy* enemy);

void init(void);

#endif // !GAME_FUNCTIONS_H
