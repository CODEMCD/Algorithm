#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//시간 문자열을 숫자로 변환
vector<int> timeChangeNum(vector<string> timetable) {
	vector<int> timeNum;
	//문자열 다룰때, 널값 들어갈 공간 늘 생각하기(특히 string이 아닌 char배열을 사용할때)
	for (int i = 0; i < timetable.size(); ++i) {
		int time;
		char hour[3], minute[3];
		hour[0] = timetable[i].at(0);
		hour[1] = timetable[i].at(1);
		hour[2] = '\0';
		minute[0] = timetable[i].at(3);
		minute[1] = timetable[i].at(4);
		minute[2] = '\0';
		time = atoi(hour) * 100 + atoi(minute);
		timeNum.push_back(time);
	}
	return timeNum;
}

//시간을 나타내는 숫자를 시간 문자열로 변환
string numChangeTime(int num) {
	int hour, minute;
	hour = num / 100;
	minute = num % 100;
	if (minute >= 60)
		minute -= 40;
	char tmp[6];
	if (hour < 10) {
		tmp[0] = '0';
		tmp[1] = hour + '0';
	}
	else {
		tmp[0] = (hour / 10) + '0';
		tmp[1] = (hour % 10) + '0';
	}
	if (minute < 10) {
		tmp[3] = '0';
		tmp[4] = minute + '0';
	}
	else {
		tmp[3] = (minute / 10) + '0';
		tmp[4] = (minute % 10) + '0';
	}
	tmp[2] = ':';
	tmp[5] = '\0';
	string time = tmp;
	return time;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> timeNum;
	timeNum = timeChangeNum(timetable);
	//일찍 도착하는 순서대로 정렬
	sort(timeNum.begin(), timeNum.end());

	//버스가 도착하는 시간을 모두 계산하여 저장한다.
	int bustable[10];
	bustable[0] = 900;
	for (int i = 1; i < n; ++i) {
		bustable[i] = bustable[i - 1] + t;
		if ((bustable[i] % 100) >= 60) {
			int hour, minute;
			hour = (bustable[i] / 100) + 1;
			minute = (bustable[i] % 100) % 60;
			bustable[i] = hour * 100 + minute;
		}
	}

	//하루가 지나서 버스를 타야하는 크루들을 모두 제거한다.
	int tnsize = timeNum.size();
	for (int i = tnsize - 1; i >= 0; --i) {
		if (timeNum[i] > bustable[n - 1])
			timeNum.pop_back();
	}
	//timeNum벡터 크기가 0이면 가장 마지막 버스 시간 반환
	if (timeNum.size() == 0)
		return numChangeTime(bustable[n - 1]);

	int next = 0, ans = 0;
	//모든 버스시간에 대해 계산한다.
	for (int i = 0; i < n; ++i) {
		int j;
		//현재 버스 시간에 태울수 있는 모든 크루들을 태운다.
		for (j = 0; j < m; ++j)
			if (next < timeNum.size() && bustable[i] >= timeNum[next])
				next++;
			else
				break;
		//현재 버스에 모든 크루가 타고도 자리가 남는다면 버스 시간에 맞춰서 온다
		if (j < m)
			ans = bustable[i] > timeNum[next - 1] ? bustable[i] : timeNum[next - 1];
		//현재 버스의 자리가 부족하다면 가장 마지막에 온 크루보다 1분 빨리 도착해야한다.
		else
			ans = timeNum[next - 1] - 1;
		if (next > timetable.size())
			break;
	}

	return answer = numChangeTime(ans);
}
