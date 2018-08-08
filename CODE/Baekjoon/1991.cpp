#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int tree[50][2];

void preorder(int x)
{
	if (x == -1) return;
	printf("%c", x + 'A');
	preorder(tree[x][0]);
	preorder(tree[x][1]);
}

void inorder(int x)
{
	if (x == -1) return;
	inorder(tree[x][0]);
	printf("%c", x + 'A');
	inorder(tree[x][1]);
}

void postorder(int x)
{
	if (x == -1) return;
	postorder(tree[x][0]);
	postorder(tree[x][1]);
	printf("%c", x + 'A');
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		if (y == '.')
			tree[x - 'A'][0] = -1;
		else
			tree[x - 'A'][0] = y - 'A';
		if (z == '.')
			tree[x - 'A'][1] = -1;
		else
			tree[x - 'A'][1] = z - 'A';
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");

	return 0;
}