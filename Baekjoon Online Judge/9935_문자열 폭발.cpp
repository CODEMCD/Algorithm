#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define N 1000001

int main(void)
{
	//1) ��� ���ڿ��� ������ �迭
	char ans[N] = {};
	string str;
	string boom;

	cin >> str;
	cin >> boom;

	int bsize = (int)boom.size();
	//��������Ʈ(sp)�� ��� ���ڿ��� �����ִ����� �˻��ϱ����� -1�� �ʱ�ȭ
	int sp = -1, cp = 0, j;

	//����
	for (int i = 0; i < (int)str.size(); i++) {
		//2) ���� ���ڿ��� ������ ���ڰ� �ƴ� ��
		if (str[i] != boom[bsize - 1])
			ans[++sp] = str[i];
		//3) ���� ���ڿ��� ������ ���ڸ� ������ ��
		else {
			ans[++sp] = str[i];
			bool check = true;
			//���� ���ڿ��� ������ �˻�
			for (cp = sp - bsize + 1, j = 0; cp <= sp, j < bsize; cp++, j++)
				if (ans[cp] != boom[j])
					check = false;
			//���ٸ� ���� ����Ʈ�� ���� ���ڿ� ù��° �ε����� �̵�
			if (check) {
				sp = sp - bsize;
			}
		}
	}
	if (sp == -1)
		printf("FRULA\n");
	else {
		for (int i = 0; i <= sp; i++)
			printf("%c", ans[i]);
		printf("\n");
	}

	return 0;
}