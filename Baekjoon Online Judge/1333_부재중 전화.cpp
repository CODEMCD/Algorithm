#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 5000001
char listen[N];

int main(void)
{
	int n, l, d;
	scanf("%d %d %d", &n, &l, &d);
	int cnt = 1;
	int len = n * l + (5 * (n - 1)); //�ٹ� �� ����
	for (int i = 0; i < len; i++) {
		if (i == (l * cnt + 5 * (cnt - 1))) {  //�޽� ���� �ð�
			int j = i;
			listen[j] = 'B';
			listen[j + 1] = 'B';
			listen[j + 2] = 'B';
			listen[j + 3] = 'B';
			listen[j + 4] = 'B';
			i += 4;
			cnt++;
		}
		else
			listen[i] = 'L';
	}
	//��ȭ�� �︮�� �ð�: 0��, D*1��, D*2��, D*3��, ...
	cnt = 1;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (i == d * cnt) {
			//��ȭ�� �︮�� �ð��� �޽� �ð��� ��
			if (listen[i] == 'B') {
				ans = i;
				break;
			}
			else
				cnt++;
		}
	}
	if (!ans)
		printf("%d\n", d * cnt);
	else
		printf("%d\n", ans);

	return 0;
}