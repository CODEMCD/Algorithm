#include <vector>
#include <string>
using namespace std;

//캐시 크기에 따른 실행 시간을 반환한다.
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	//캐시 정보를 저장할 벡터 (도시 이름, 캐시에 머무른 시간) 쌍
	vector<pair<string, int>> cache(cacheSize);

	//대소문자 구분이 없기 때문에 모든 대문자를 소문자로 변경한다.(동치 비교를 위함)
	for (int i = 0; i < cities.size(); ++i)
		for (int j = 0; j < cities[i].size(); ++j)
			if (cities[i][j] < 97)
				cities[i][j] += 32;

	//캐시 크기가 0이면 모두 miss이므로 도시 개수만큼 miss 시간이 소요된다.
	if (cacheSize == 0)
		return answer = cities.size() * 5;

	//도시를 순차적으로 캐시에 넣을 수 있는지 판단한다.
	for (int i = 0; i < cities.size(); ++i) {
		//캐시에 넣을 수 있는지를 저장하는 변수
		bool cacheFlag = false;
		//삽입할 캐시 인덱스
		int insertIdx = 0;
		int clock = 0;

		//캐시에 머물러 있는 인덱스들의 시간을 하나씩 증가 시킨다.
		for (int j = 0; j < cacheSize; ++j) {
			if (cache[j].second > 0)
				cache[j].second++;
		}

		//캐시에 동일한 도시가 있는지 검사한다.
		for (int j = 0; j < cacheSize; ++j)
			if (cache[j].first == cities[i]) {
				insertIdx = j;
				cacheFlag = true;
				break;
			}

		//캐시에 동일한 도시가 있다면, hit시간만큼 증가시킨 뒤
		//해당 도시를 최신화 하고 다음 도시로 넘어간다.
		if (cacheFlag) {
			cache[insertIdx].second = 1;
			answer += 1;
			continue;
		}

		//캐시에 없다면, 처음 들어가는 경우와 가장 오래 머물러있는 도시를 교체한다.
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