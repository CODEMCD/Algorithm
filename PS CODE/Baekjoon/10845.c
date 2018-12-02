#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 200

typedef struct queue
{
	int arr[N];
	int front;
	int back;
} Que;

void QInit(Que *que)
{
	que->front = 0;
	que->back = 0;
}

void QPush(Que *que, int data)
{
	que->arr[que->back] = data;
	(que->back)++;
}
int QPop(Que *que)
{
	if (que->back == que->front)
		return -1;
	int pop = que->arr[que->front];
	for (int i = 0; i < que->back; i++)
		que->arr[i] = que->arr[i + 1];
	(que->back)--;
	return pop;
}

int QSize(Que *que)
{
	return que->back;
}
int QEmpty(Que *que)
{
	if (que->back == 0)
		return 1;
	else
		return 0;
}
int QFront(Que *que)
{
	if (que->back == 0)
		return -1;
	return que->arr[que->front];
}
int QBack(Que *que)
{
	if (que->back == 0)
		return -1;
	return que->arr[(que->back) - 1];
}
int main() 
{
	Que que;
	QInit(&que);

	int cmdN, data;
	char cmd[N];
	scanf("%d", &cmdN);
	for (int i = 0; i < cmdN; i++) {
		scanf("%s", cmd);
		if (strstr(cmd, "push")) {
			scanf("%d", &data);
			QPush(&que, data);
		}
		else if (strstr(cmd, "pop")) {
			printf("%d\n", QPop(&que));
		}
		else if (strstr(cmd, "size")) {
			printf("%d\n", QSize(&que));
		}
		else if (strstr(cmd, "empty")) {
			printf("%d\n", QEmpty(&que));
		}
		else if (strstr(cmd, "front")) {
			printf("%d\n", QFront(&que));
		}
		else if (strstr(cmd, "back")) {
			printf("%d\n", QBack(&que));
		}
	}
	return 0;
}

