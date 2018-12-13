#include <vector>
#include <string>
using namespace std;

//두 문자열의 자카드 유사도 값을 반환한다.
int solution(string str1, string str2) {
	int answer = 0;
	int size1 = str1.size();
	int size2 = str2.size();
	//두 문자열이 공백이면 1을 반환한다.
	if (size1 == 0 && size2 == 0)
		return 1 * 65536;

	//대소문자는 구분하지 않기 때문에, 대문자이면 모두 소문자로 바꾼다.
	for (int i = 0; i < size1; ++i)
		if (str1[i] >= 65 && str1[i] <= 90)
			str1[i] += 32;
	for (int i = 0; i < size2; ++i)
		if (str2[i] >= 65 && str2[i] <= 90)
			str2[i] += 32;

	//두 문자열의 다중집합을 만든다.
	vector<string> set1, set2;
	for (int i = 0; i < size1 - 1; ++i)
		//두 글자 모두 영문자인 경우에만 원소로 만든다.
		if ((str1[i] >= 97 && str1[i] <= 122) && 
			(str1[i + 1] >= 97 && str1[i + 1] <= 122)) {
			char tmp[3];
			tmp[0] = str1.at(i);
			tmp[1] = str1.at(i + 1);
			tmp[2] = '\0';
			string ele;
			ele = tmp;
			set1.push_back(ele);
		}
	for (int i = 0; i < size2 - 1; ++i)
		if ((str2[i] >= 97 && str2[i] <= 122) &&
			(str2[i + 1] >= 97 && str2[i + 1] <= 122)) {
			char tmp[3];
			tmp[0] = str2.at(i);
			tmp[1] = str2.at(i + 1);
			tmp[2] = '\0';
			string ele;
			ele = tmp;
			set2.push_back(ele);
		}
	//inter: 교집합 개수, uni: 합집합 개수
	int inter = 0, uni = 0;
	//집합 원소를 검사했는지 판단
	vector<bool> check1(set1.size());
	vector<bool> check2(set2.size());
	//집합1 계산
	for (int i = 0; i < set1.size(); ++i) {
		string ch = set1[i];
		int cnt1 = 0;
		int cnt2 = 0;
		//한 원소가 집합1에서 같은 것이 몇개 있는지 계산한다.
		for (int j = 0; j < set1.size(); ++j)
			if (ch == set1[j] && !check1[j]) {
				check1[j] = true;
				cnt1++;
			}
		//한 원소가 집합2에서 같은 것이 몇개 있는지 계산한다.
		for (int j = 0; j < set2.size(); ++j)
			if (ch == set2[j] && !check2[j]) {
				check2[j] = true;
				cnt2++;
			}
		//같은 원소가 더 적은 수를 교집합 개수로 한다.
		inter += (cnt1 < cnt2 ? cnt1 : cnt2);
		//같은 원소가 더 많은 수를 합집합 개수로 한다.
		uni += (cnt1 > cnt2 ? cnt1 : cnt2);
	}
	//집합2에서 아직 검사되지 않은 원소를 검사한다.
	for (int i = 0; i < set2.size(); ++i) {
		string ch = set2[i];
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 0; j < set1.size(); ++j)
			if (ch == set1[j] && !check1[j]) {
				check1[j] = true;
				cnt1++;
			}
		for (int j = 0; j < set2.size(); ++j)
			if (ch == set2[j] && !check2[j]) {
				check2[j] = true;
				cnt2++;
			}
		inter += (cnt1 < cnt2 ? cnt1 : cnt2);
		uni += (cnt1 > cnt2 ? cnt1 : cnt2);
	}
	//합집합이 없으면 1반환
	if (uni == 0)
		return 1 * 65536;
	//자카드 유사도 계산
	double cal = ((double)inter / uni) * 65536;
	return answer = (int)cal;
}
