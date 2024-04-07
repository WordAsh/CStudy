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

//���������д����ֵ��Warning C4033 ��ʽ��������һ��int
void updatePlayerList(Player** players, int* currentSize, int newSize, Player player);

void printPlayers(Player* players, int size);

//Log4c, Syslog, spdlog
void logError(const char* string);
void logInfo(const char* string);
void logMessage(const char* level, const char* message);

int main_realloc(void)
{
	Player* players = NULL;		//��ҳ�ʼ���б�Ϊ��
	int currentSize = 0;		//��ǰ�������
	
	//��ʼ�������ṹ�壬ģ����ҽ���
	Player player1 = { 1,"PlayerOne" };
	updatePlayerList(&players, &currentSize, currentSize + 1, player1);

	Player player2 = { 2,"PlayerTwo" };
	updatePlayerList(&players, &currentSize, currentSize + 1, player2);

	Player player3 = { 3,"PlayerThree" };
	updatePlayerList(&players, &currentSize, currentSize + 1, player3);

	//����playersָ������飬�����������̶��ľ�̬���飬����һ��malloc�������ɵĶ�̬����
	printPlayers(players, currentSize);

	return EXIT_SUCCESS;
}

void updatePlayerList(Player** players, int* currentSize, int newSize, Player player) {
	
	//��ֹ��С�����Сʱ��ʧ����
	if(newSize < *currentSize){
		logError("Error: newSize is smaller than currentSize.");
		return;
	}

	//���������ʱ��ȷ��newSize����currentSize
	if (newSize == *currentSize) {
		logInfo("No resizing needed. The newSize must be greater than currentSize to add a new player.\n");
		return;
	}

	Player* tmp = (Player*)realloc(*players, newSize * sizeof(Player));
	//malloc(newSize*sizeof(Player))

	if (tmp == NULL) {
		//�����·���ʧ�ܵ�ʱ�򣬱���ԭʼ�б��䣬�������ݶ�ʧ
		logError("Error: reallocating memory!\n");
	}
	else {
		*players = tmp;
		//��������ݣ����������ҵ����б�
		if (newSize > *currentSize) {
			(*players)[*currentSize] = player;	//��������
		}
		*currentSize = newSize;	//���µ�ǰ��С

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
	//��ʵ����ҵ�У����������д���򵥣�Ӧ���滻Ϊ�����ӵ���־ϵͳ����
}

void logInfo(const char* message) {
	logMessage("INFO", message);
	//��ʵ����ҵ�У����������д���򵥣�Ӧ���滻Ϊ�����ӵ���־ϵͳ����
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