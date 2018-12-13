#include <vector>
#include <string>
using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";

	//참가인원에 비례하여 구해야할 숫자들의 최대 개수를 계산한다.
	int size = t * m + 1;
	string num;

	num.push_back('0');
	int number = 1;
	//숫자 1부터 구해야할 개수가 될때까지 숫자 하나하나를 배열에 추가한다.
	while (true) {
		int cur_size = num.size();
		//현재 크기가 최대 크기를 넘어서면 반복문을 빠져나간다.
		if (cur_size > size)
			break;

		int tmp[20];
		int cnt = 0;
		int tn = number;
		//해당 숫자를 주어진 진법으로 변환한다.
		while (true) {
			if (tn == 0) break;
			tmp[cnt++] = tn % n;
			tn /= n;
		}
		//숫자 하나하나를 배열에 추가한다.
		for (int i = cnt - 1; i >= 0; --i) {
			switch (tmp[i]) {
			case 10: num.push_back('A'); break;
			case 11: num.push_back('B'); break;
			case 12: num.push_back('C'); break;
			case 13: num.push_back('D'); break;
			case 14: num.push_back('E'); break;
			case 15: num.push_back('F'); break;
			default: num.push_back(tmp[i] + '0'); break;
			}
		}
		number++;
	}
	//튜브의 순서에 맞는 숫자를 계산한다.
	int cnt = 1;
	for (int i = p - 1; i < num.size(); i += m) {
		if (cnt > t) break;
		answer.push_back(num[i]);
		cnt++;
	}

	return answer;
}
