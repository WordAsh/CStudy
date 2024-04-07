#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Character {
	char* name;
	int level;
	int hp;
}Character;

Character* create_character(const char* name, int level, int hp);
void free_character(Character* character);

int main_malloc2(void)
{
	Character* hero = create_character("hero", 10, 100);

	if (hero == NULL) {
		return EXIT_FAILURE;
	}

	free_character(hero);

	return EXIT_SUCCESS;
}

Character* create_character(const char* name, int level, int hp) {
	Character* character = (Character*)malloc(sizeof(Character));

	if (character == NULL) {
		perror("Failed to create character.");
		return NULL;
	}

	character->name = (char*)malloc(strlen(name) + 1);

	if (character->name == NULL) {
		perror("Failed to create character name.");
		free(character);			//防止内存泄露
		return NULL;
	}

	strcpy_s(character->name, strlen(name) + 1, name);
	character->level = level;
	character->hp = hp;

	return character;
}


void free_character(Character* character) {
	if (character != NULL) {
		free(character->name);		//释放名字字符串占用的内存
		free(character);
	}
}