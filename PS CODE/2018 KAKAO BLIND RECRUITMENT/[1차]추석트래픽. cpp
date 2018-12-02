#include <vector>
#include <string>
using namespace std;

//각 로그의 시작 시간과 끝 시간을 저장할 클래스
class TimeSection {
public :
	long long start_time;
	long long end_time;
};

int solution(vector<string> lines) {
	int answer = 0;
	//클래스 벡터
	vector<TimeSection> tsv;

	int lsize = lines.size();

	for (int i = 0; i < lsize; ++i) {
		//시간 문자열을 숫자로 표현
		long long hour = (lines[i][11] - '0') * 10 + lines[i][12] - '0';  //시
		long long min = (lines[i][14] - '0') * 10 + lines[i][15] - '0';   //분
		long long sec = (lines[i][17] - '0') * 10 + lines[i][18] - '0';   //초
		long long msec = (lines[i][20] - '0') * 100 + (lines[i][21] - '0') * 10 +
			lines[i][22] - '0';  //밀리초

		//시작 시간과 끝 시간이 포함되므로 시작 시간을 계산하려면 처리시간의
		//마지막 단위인 0.001을 더해주어야 한다.
		long long dsec = (lines[i][24] - '0') * 1000 - 1;  //처리시간의 초부분
		//처리시간이 밀리초 단위까지 존재하는 경우
		if (lines[i][25] != 's') {
			int idx = 26;
			int subConst = 100;

			while (true) {
				if (lines[i][idx] == 's') break;
				dsec += (lines[i][idx] - '0') * subConst;
				idx++;
				subConst /= 10;
			}
		}

		TimeSection newTS;
		//시분초를 하나의 숫자로 표현(초단위로 계산)
		newTS.end_time = hour * 3600000 + min * 60000 + sec * 1000 + msec;
		newTS.start_time = newTS.end_time - dsec;
		tsv.push_back(newTS);
	}

	//각각의 시간 구간의 끝 시간에서 1초를 설정하여 이 범위에 구간이 몇개 포함되는지 계산한다.
	for (int i = 0; i < lsize; ++i) {
		//한 시간 구간의 끝 시간
		long long et = tsv[i].end_time;
		//1초 후의 시간
		long long eet = et + 999;
		int cnt = 0;
		for (int j = 0; j < lsize; ++j)
			//한 구간의 시작 시간이 해당 구간의 1초 후의 시간보다 늦거나
			//한 구간의 끝 시간이 해당 구간의 끝 시간보다 이르다면
			//범위에 포함되지 않는다.
			if (tsv[j].start_time > eet || tsv[j].end_time < et);
			else
				cnt++;
		answer = answer > cnt ? answer : cnt;
	}

	return answer;
}
