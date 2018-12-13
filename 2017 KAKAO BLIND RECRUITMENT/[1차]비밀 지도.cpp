#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define N 20

//�������� �������� ��ȯ�Ѵ�.
vector<int> changeBi(int arr, int n) {
	vector<int> binary(N);
	for (int i = n - 1; i >= 0; --i) {
		binary[i] = arr % 2;
		arr /= 2;
	}
	return binary;
}

//��1�� ��2�� ���� ��ü ������ ��ȯ�Ѵ�.
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; ++i) {
		//��1 �� ���� ������ ����
		vector<int> bi1(N);
		//��2 �� ���� ������ ����
		vector<int> bi2(N);
		char sum[20];
		//�������� �������� �ٲ۴�.
		//0: ����, 1: ��
		bi1 = changeBi(arr1[i], n);
		bi2 = changeBi(arr2[i], n);
		//��1,2 �� �ϳ��� ���̸�, ��ü ���� ��
		//��1,2 �� ��� �����̸�, ��ü���� ����
		for (int j = 0; j < n; ++j) {
			if (!bi1[j] && !bi2[j])
				sum[j] = ' ';
			else
				sum[j] = '#';
		}
		sum[n] = '\0';
		string res;
		res = sum;
		//���� �迭�� ����
		answer.push_back(res);
	}

	return answer;
}

int main(void)
{
	return 0;
}