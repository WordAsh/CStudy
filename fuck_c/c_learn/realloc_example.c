#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

#define TIME_STRING_SIZE 26

typedef struct Player {
	int id;
	char name[30];
}Player;

//如果函数不写返回值，Warning C4033 隐式声明返回一个int
void updatePlayerList(Player** players, int* currentSize, int newSize, Player player);

void printPlayers(Player* players, int size);

//Log4c, Syslog, spdlog
void logError(const char* string);
void logInfo(const char* string);
void logMessage(const char* level, const char* message);

int main_realloc(void)
{
	Player* players = NULL;		//玩家初始化列表为空
	int currentSize = 0;		//当前玩家数量
	
	//初始化三个结构体，模拟玩家进入
	Player player1 = { 1,"PlayerOne" };
	updatePlayerList(&players, &currentSize, currentSize + 1, player1);

	Player player2 = { 2,"PlayerTwo" };
	updatePlayerList(&players, &currentSize, currentSize + 1, player2);

	Player player3 = { 3,"PlayerThree" };
	updatePlayerList(&players, &currentSize, currentSize + 1, player3);

	//整个players指向的数组，不是我们所固定的静态数组，而是一个malloc函数生成的动态数组
	printPlayers(players, currentSize);

	return EXIT_SUCCESS;
}

void updatePlayerList(Player** players, int* currentSize, int newSize, Player player) {
	
	//防止减小数组大小时丢失数据
	if(newSize < *currentSize){
		logError("Error: newSize is smaller than currentSize.");
		return;
	}

	//当增加玩家时，确保newSize大于currentSize
	if (newSize == *currentSize) {
		logInfo("No resizing needed. The newSize must be greater than currentSize to add a new player.\n");
		return;
	}

	Player* tmp = (Player*)realloc(*players, newSize * sizeof(Player));
	//malloc(newSize*sizeof(Player))

	if (tmp == NULL) {
		//在重新分配失败的时候，保持原始列表不变，避免数据丢失
		logError("Error: reallocating memory!\n");
	}
	else {
		*players = tmp;
		//如果是扩容，则添加新玩家到新列表
		if (newSize > *currentSize) {
			(*players)[*currentSize] = player;	//添加新玩家
		}
		*currentSize = newSize;	//更新当前大小

		logInfo("Player added successfully.");
		char infoMessage[100];
		snprintf(infoMessage, sizeof(infoMessage), "Current player count: %d", *currentSize);
		logInfo(infoMessage);
	}
}

void printPlayers(Player* players, int size) {
	printf("Current Players:\n");
	for (size_t i = 0; i < size;++i) {
		printf("ID: %d, Name: %s\n", players[i].id, players[i].name);
	}
}

void logError(const char* message) {
	logMessage("ERROR", message);
	//在实际企业中，并非这两行代码简单，应该替换为更复杂的日志系统调用
}

void logInfo(const char* message) {
	logMessage("INFO", message);
	//在实际企业中，并非这两行代码简单，应该替换为更复杂的日志系统调用
}

void logMessage(const char* level, const char* message) {
	time_t now = time(NULL);
	char timeStr[TIME_STRING_SIZE];

	if (ctime_s(timeStr,sizeof(timeStr),&now) == 0) {
		timeStr[24] = '\0';
		fprintf(stderr, "[%s] %s: %s\n", timeStr, level, message);
	}
	else {
		fprintf(stderr, "[ERROR] Failed to get current time.\n");
	}
}