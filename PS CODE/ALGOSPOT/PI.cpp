#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <limits.h>
using namespace std;
#define N 10001
#define min(a, b) ((a) < (b) ? (a) : (b))
string arr;
const int INF = 987654321;
int cache[N];

//1) arr[s]���� size��ŭ ũ���� ���̵��� ��ȯ
int checkLevel(int s, int size)
{
	if (size == 3) {
		int s1, s2, s3;
		s1 = arr[s]; s2 = arr[s + 1]; s3 = arr[s + 2];
		if (s1 == s2 && s2 == s3)
			return 1;
		int d1, d2;
		d1 = s2 - s1; d2 = s3 - s2;
		if (d1 == d2) {
			if (d1 == 1 || d1 == -1)
				return 2;
			else
				return 5;
		}
		if (s1 == s3)
			return 4;
	}
	else if (size == 4) {
		int s1, s2, s3, s4;
		s1 = arr[s]; s2 = arr[s + 1]; s3 = arr[s + 2]; s4 = arr[s + 3];
		if (s1 == s2 && s2 == s3 && s3 == s4)
			return 1;
		int d1, d2, d3;
		d1 = s2 - s1; d2 = s3 - s2; d3 = s4 - s3;
		if (d1 == d2 && d2 == d3) {
			if (d1 == 1 || d1 == -1)
				return 2;
			else
				return 5;
		}
		if (s1 == s3 && s2 == s4)
			return 4;
	}
	else if (size == 5) {
		int s1, s2, s3, s4, s5;
		s1 = arr[s]; s2 = arr[s + 1]; s3 = arr[s + 2]; 
		s4 = arr[s + 3]; s5 = arr[s + 4];
		if (s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5)
			return 1;
		int d1, d2, d3, d4;
		d1 = s2 - s1; d2 = s3 - s2; d3 = s4 - s3; d4 = s5 - s4;
		if (d1 == d2 && d2 == d3 && d3 == d4) {
			if (d1 == 1 || d1 == -1)
				return 2;
			else
				return 5;
		}
		if ((s1 == s3 && s3 == s5) && s2 == s4)
			return 4;
	}
	return 10;
}

//2) arr[a,b]������ ���̵��� ��ȯ�Ѵ�.
int classify(int a, int b)
{
	//���� ������ �����´�.
	string M = arr.substr(a, b - a + 1);
	//ù ���ڸ����� �̷���� ���ڿ��� �������� ���̵� 1
	if (M == string(M.size(), M[0])) return 1;
	//������������ �˻��Ѵ�.
	bool progressive = true;
	for (int i = 0; i < (int)M.size() - 1; i++)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	//���������̰� ������ 1 or -1 �̸� ���̵� 2
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	//�� ���� ������ �����ϴ��� Ȯ���Ѵ�.
	bool alternating = true;
	for (int i = 0; i < (int)M.size(); i++)
		if (M[i] != M[i % 2])
			alternating = false;
	if (alternating) return 4;  //�� ���� ������ �����ϸ� ���̵� 4
	if (progressive) return 5;  //������ 1 �ƴ� ���������̸� ���̵� 5
	return 10;                  //�� �ܴ� ��� ���̵� 10
}

//���� arr[begin...]�� �ܿ�� ��� �� ���̵��� �ּ� ���� ����Ѵ�.
int memorize(int begin)
{
	//���� ���: ������ ���� �������� ���
	if (begin == arr.size()) return 0;
	//�޸������̼�
	int &ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (int L = 3; L <= 5; ++L) {
		if (begin + L <= (int)arr.size())
			ret = min(ret, memorize(begin + L) + checkLevel(begin, L));              //��� 1)
			//ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));  //��� 2)
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(cache, -1, sizeof(cache));
		arr.clear();
		cin >> arr;
		printf("%d\n", memorize(0));
	}

	return 0;
}