#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//3���� ��Ʈ ������ �־����� ��, ������ ����Ͽ� ��ȯ�Ѵ�.
int solution(string dartResult) {
	int answer = 0;
	//score[]: �� ��Ʈ ���� ���
	int score[3], idx = 0;
	for (int i = 0; i < dartResult.size(); ++i) {
		//��Ʈ ������ 10���� ���
		if (dartResult.at(i) == '1' && dartResult.at(i + 1) == '0') {
			score[idx] = 10;
			i++;
		}
		//�� �� ���(���ڸ���)
		else
			score[idx] = dartResult.at(i) - 48;

		//Single, Double, Triple ���� ���
		i++;
		if (dartResult.at(i) == 'D')
			score[idx] *= score[idx];
		else if (dartResult.at(i) == 'T')
			score[idx] *= (score[idx] * score[idx]);

		//��Ÿ��(*), ������(#) ���� ���
		i++;
		if (i < dartResult.size() && dartResult.at(i) == '#')
			score[idx] *= -1;
		else if (i < dartResult.size() && dartResult.at(i) == '*') {
			if (idx == 0) score[idx] *= 2;
			else {
				score[idx - 1] *= 2;
				score[idx] *= 2;
			}
		}
		else
			i--;
		idx++;
	}

	//3���� ��Ʈ ������ ��� ���Ѵ�.
	return answer = score[0] + score[1] + score[2];
}

int main(void)
{
	string info; cin >> info;
	int ans = solution(info);
	printf("%d\n", ans);

	return 0;
}