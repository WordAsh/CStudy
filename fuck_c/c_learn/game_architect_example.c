#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

//�¼�������
//Event -> Function
//1.�����¼����ͺ��¼�������ǩ�����������Ƕ�����Ϸ�п��ܷ������¼����ͣ��Լ�������Щ������ǩ��
//2.ʵ���¼�ע��ͷַ����ƣ�ʵ��һ�����ƣ�����Ϊ��ͬ�����͵��¼�ע�ᴦ��������������Ӧ���¼�����ʱ������Щ����
//3.�����¼�������������Ϊ��Ϸ�е�ÿһ���¼����Ͷ��������¼�������
//4.����Ϸ��ʹ���¼�����ϵͳ��main��ע���¼�������������ģ���¼��ķ�������ʾϵͳ�Ĺ�������

typedef enum {
	PLAYER_ATTACK,
	PLAYER_MOVE,
	// ...
	EVENT_COUNT	//��¼�¼�������(����enumĬ��ֵ�����ԣ�count�������)
}GameEventType;

typedef void (*EventHandler)(const char* playerName);

EventHandler eventHandlers[EVENT_COUNT];	//�¼�������������
//������һ�����飬��������е�ÿ��Ԫ�ض���EventHandler���͵ĺ���ָ�룬��ζ��ÿ������Ԫ�ض����Դ洢һ��ָ������ָ�룬�����������EventHandler��ǩ��������һ��const char* �Ĳ������Ͳ��ҷ���void

//ע���¼�������
void registerEventHandler(GameEventType eventType, EventHandler handler);

//�ַ��¼�
void dispatchEvent(GameEventType eventType, const char* playerName);

void handlePlayerAttack(const char* playerName);

void handlePlayerMove(const char* playerName);

int main_game_architect(void)
{
	//ע���¼�������
	registerEventHandler(PLAYER_ATTACK, handlePlayerAttack);
	registerEventHandler(PLAYER_MOVE, handlePlayerMove);

	//�м��и��ָ����Ĵ���
	//ͻȻ�¼�������
	dispatchEvent(PLAYER_ATTACK, "Hero");
	dispatchEvent(PLAYER_MOVE, "Hero");

	return EXIT_SUCCESS;
}

void registerEventHandler(GameEventType eventType, EventHandler handler) {
	if (eventType >= 0 && eventType < EVENT_COUNT) {
		eventHandlers[eventType] = handler;

		//TODO...
	}
	else {
		fprintf(stderr, "Invalid eventType: %d\n", eventType);
	}
}

void dispatchEvent(GameEventType eventType, const char* playerName) {
	if (eventHandlers[eventType] != NULL) {
		eventHandlers[eventType](playerName);
	}
}

void handlePlayerAttack(const char* playerName) {
	printf("%s attacks!\n",playerName);
}

void handlePlayerMove(const char* playerName) {
	printf("%s moves!\n", playerName);
}