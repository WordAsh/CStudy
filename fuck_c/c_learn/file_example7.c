#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <errno.h>

typedef struct GameSettings {
	float volume;
	int resolution_x;
	int resolution_y;
	int difficulty;
}GameSettings;

void save_settings(const GameSettings* settings, const char* filename);
void load_settings(GameSettings* settings, const char* filename);

int main_file7(void)
{
	//fread
	//fwrite
	
	//写二进制
	//GameSettings settings = { 0.75,1920,1080,2 };
	//
	//save_settings(&settings, "C:\\Users\\Rigon\\Desktop\\game_settings.bin");

	GameSettings loaded_settings;

	load_settings(&loaded_settings, "C:\\Users\\Rigon\\Desktop\\game_settings.bin");

	printf("游戏设置已经加载!\n");
	printf("音量: %.2f\n分辨率: %dx%d\n难度: %d\n",
		loaded_settings.volume,
		loaded_settings.resolution_x,
		loaded_settings.resolution_y,
		loaded_settings.difficulty);

	return 0;
}

void save_settings(const GameSettings* settings, const char* filename) {
	FILE* file_ptr;
	errno_t err = fopen_s(&file_ptr, filename, "wb");
	if (err != 0 || file_ptr == NULL) {
		perror("无法打开文件进行写入操作");
		return;
	}

	fwrite(settings, sizeof(GameSettings), 1, file_ptr);

	fclose(file_ptr);
}


void load_settings(GameSettings* settings, const char* filename) {
	FILE* file_ptr;
	errno_t err = fopen_s(&file_ptr, filename, "rb");
	if (err != 0 || file_ptr == NULL) {
		perror("无法打开文件进行读取操作");
		return;
	}

	fread(settings, sizeof(GameSettings),1, file_ptr);
	fclose(file_ptr);
}