#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define N 1000001

int main(void)
{
	//1) 결과 문자열을 저장할 배열
	char ans[N] = {};
	string str;
	string boom;

	cin >> str;
	cin >> boom;

	int bsize = (int)boom.size();
	//스택포인트(sp)는 결과 문자열이 남아있는지를 검사하기위해 -1로 초기화
	int sp = -1, cp = 0, j;

	//스택
	for (int i = 0; i < (int)str.size(); i++) {
		//2) 폭발 문자열의 마지막 문자가 아닐 때
		if (str[i] != boom[bsize - 1])
			ans[++sp] = str[i];
		//3) 폭발 문자열의 마지막 문자를 만났을 때
		else {
			ans[++sp] = str[i];
			bool check = true;
			//폭발 문자열과 같은지 검사
			for (cp = sp - bsize + 1, j = 0; cp <= sp, j < bsize; cp++, j++)
				if (ans[cp] != boom[j])
					check = false;
			//같다면 스택 포인트를 폭발 문자열 첫번째 인덱스로 이동
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