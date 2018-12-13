#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int calDistSqr(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void)
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		int ans = 0;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int cx, cy, r;
			scanf("%d %d %d", &cx, &cy, &r);

			/*
			�༺����̴� ���� ��������� �´�ų� �����Ͻ� �ʰ�,
			�༺��� �����̴� ��������� �´��� �ʴ´�.
			�� ������ �������� �༺�� ����/��Ż Ƚ���� 4���� ���� ������.
			(�Ÿ��� �Ǽ� ����� ���ϱ� ���� �������� ����Ѵ�.)
			*/
			//�������� �ش� �༺�� �߽ɻ��� �Ÿ�^2
			int distsc = calDistSqr(sx, sy, cx, cy);
			//�������� �ش� �༺�� �߽ɻ��� �Ÿ�^2
			int distec = calDistSqr(ex, ey, cx, cy);
			//�༺�� ������^2
			int rs = r * r;

			// 1) �������� ������ ��� �ش� �༺�� �ۿ� �ִ� ���
			if (rs < distsc && rs < distec)
				//�ش� �༺�踦 ���� �ʿ䰡 ����.
				ans += 0;
			// 2) �������� ������ ��� �༺�� �ȿ� �ִ� ���
			else if (rs > distsc && rs > distec)
				ans += 0;
			// 3) �������� �༺�� ��, �������� �༺�� �ȿ� �ִ� ���
			else if (rs > distsc && rs < distec)
				//���������� ���������� ������ �ش� �༺�� ��踦 �������Ѵ�.
				ans += 1;
			// 4) �������� �༺�� ��, �������� �༺�� �ۿ� �ִ� ���
			else if (rs < distsc && rs > distec)
				ans += 1;
		}

		printf("%d\n", ans);
	}

	return 0;
}