#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 51
const int FAIL = 1234;

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char vps[N];
		int check[N];
		scanf("%s", vps);
		int len = strlen(vps);
		if (vps[0] == ')') {
			printf("NO\n");
			continue;
		}
		else
			check[0] = 1;
		for (int i = 1; i < len; i++) {
			if (vps[i] == ')' && !check[i - 1]) {
				check[len - 1] = FAIL;
				break;
			}
			if (vps[i] == '(')
				check[i] = check[i - 1] + 1;
			else if (vps[i] == ')')
				check[i] = check[i - 1] - 1;
			else  //(���ڿ�) YES��, ������ �����
				check[i] = check[i - 1];
		}
		if (!check[len - 1])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

/* �׽�Ʈ ���̽�
())(()
*/