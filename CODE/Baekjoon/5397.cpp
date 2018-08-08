#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1000001
char str[N];
typedef struct STACK
{
	char arr[N];
	int tidx;
} STACK;
typedef STACK Stack;
Stack s1, s2;

void init(Stack *pstack)
{
	pstack->tidx = -1;
	memset(pstack->arr, '\0', sizeof(pstack->arr));
}

bool empty(Stack *pstack)
{
	if (pstack->tidx == -1)
		return true;
	else
		return false;
}

void push(Stack *pstack, char c)
{
	pstack->tidx++;
	pstack->arr[pstack->tidx] = c;
}

char pop(Stack *pstack)
{
	int ridx;
	if (empty(pstack))
		exit(-1);
	ridx = pstack->tidx--;
	return pstack->arr[ridx];
}

int main(void)
{
	int n;
	scanf("%d", &n);
	while (n--) {
		memset(str, '\0', sizeof(str));
		scanf("%s", str);
		init(&s1); init(&s2);
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] == '<') {
				if (!empty(&s1)) {
					push(&s2, pop(&s1));
				}
			}
			else if (str[i] == '>') {
				if (!empty(&s2)) {
					push(&s1, pop(&s2));
				}
			}
			else if (str[i] == '-') {
				if (!empty(&s1))
					pop(&s1);
			}
			else {
				push(&s1, str[i]);
			}
		}
		for (int i = 0; i <= s1.tidx; i++)
			printf("%c", s1.arr[i]);
		while (!empty(&s2)) {
			printf("%c", pop(&s2));
		}
		printf("\n");
	}

	return 0;
}