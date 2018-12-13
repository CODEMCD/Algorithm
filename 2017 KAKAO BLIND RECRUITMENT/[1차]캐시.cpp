#include <vector>
#include <string>
using namespace std;

//ĳ�� ũ�⿡ ���� ���� �ð��� ��ȯ�Ѵ�.
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	//ĳ�� ������ ������ ���� (���� �̸�, ĳ�ÿ� �ӹ��� �ð�) ��
	vector<pair<string, int>> cache(cacheSize);

	//��ҹ��� ������ ���� ������ ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�.(��ġ �񱳸� ����)
	for (int i = 0; i < cities.size(); ++i)
		for (int j = 0; j < cities[i].size(); ++j)
			if (cities[i][j] < 97)
				cities[i][j] += 32;

	//ĳ�� ũ�Ⱑ 0�̸� ��� miss�̹Ƿ� ���� ������ŭ miss �ð��� �ҿ�ȴ�.
	if (cacheSize == 0)
		return answer = cities.size() * 5;

	//���ø� ���������� ĳ�ÿ� ���� �� �ִ��� �Ǵ��Ѵ�.
	for (int i = 0; i < cities.size(); ++i) {
		//ĳ�ÿ� ���� �� �ִ����� �����ϴ� ����
		bool cacheFlag = false;
		//������ ĳ�� �ε���
		int insertIdx = 0;
		int clock = 0;

		//ĳ�ÿ� �ӹ��� �ִ� �ε������� �ð��� �ϳ��� ���� ��Ų��.
		for (int j = 0; j < cacheSize; ++j) {
			if (cache[j].second > 0)
				cache[j].second++;
		}

		//ĳ�ÿ� ������ ���ð� �ִ��� �˻��Ѵ�.
		for (int j = 0; j < cacheSize; ++j)
			if (cache[j].first == cities[i]) {
				insertIdx = j;
				cacheFlag = true;
				break;
			}

		//ĳ�ÿ� ������ ���ð� �ִٸ�, hit�ð���ŭ ������Ų ��
		//�ش� ���ø� �ֽ�ȭ �ϰ� ���� ���÷� �Ѿ��.
		if (cacheFlag) {
			cache[insertIdx].second = 1;
			answer += 1;
			continue;
		}

		//ĳ�ÿ� ���ٸ�, ó�� ���� ���� ���� ���� �ӹ����ִ� ���ø� ��ü�Ѵ�.
		for (int j = 0; j < cacheSize; ++j)
			if (cache[j].second == 0) {
				insertIdx = j;
				break;
			}
			else
				if (clock < cache[j].second) {
					insertIdx = j;
					clock = cache[j].second;
				}
		cache[insertIdx].first = cities[i];
		cache[insertIdx].second = 1;
		answer += 5;
	}

	return answer;
}