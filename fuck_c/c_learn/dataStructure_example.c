#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

//��̬���ݽṹ�Ĺ��������޸�ָ��ṹ���ָ�룬��������޸�ɾ���ڵ㣬����Ҫ���ض����µ�ͷָ�롣

typedef struct Node {
	int data;
	struct Node* next;
}Node;

void addAtHead(Node** head, int data);
void printList(Node* head);

int main_node(void) 
{
	Node* head = NULL;

	addAtHead(&head, 1);
	addAtHead(&head, 2);
	addAtHead(&head, 3);

	printList(head);

	Node* temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}

	return EXIT_SUCCESS;
}


void addAtHead(Node** head, int data) {
	Node* newNode = malloc(sizeof(Node));

	if (newNode == NULL) {
		perror("Failed to allocate memory for new node.\n");
		return;
	}

	newNode->data = data;
	newNode->next = *head;		//�½ڵ�ָ��ԭͷ�ڵ�
	*head = newNode;			//����ͷ�ڵ�Ϊ�½ڵ�
}

void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ",current->data);
		current = current->next;
	}
	printf("NULL\n");
}