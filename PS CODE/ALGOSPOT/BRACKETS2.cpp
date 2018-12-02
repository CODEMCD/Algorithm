#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define N 10001

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		char brak[N];
		scanf("%s", brak);
		int blen = strlen(brak);
		stack<char> check;
		for (int i = 0; i < blen; ++i) {
			if (brak[i] == '(' || brak[i] == '{' || brak[i] == '[')
				check.push(brak[i]);
			else {
				//스택에 값이 있을 때만 접근해야 한다.
				if (check.size() > 0) {
					char fit = check.top();
					if (brak[i] == ')' && fit == '(')
						check.pop();
					else if (brak[i] == '}' && fit == '{')
						check.pop();
					else if (brak[i] == ']' && fit == '[')
						check.pop();
				}
				//(,{,[ 의 개수보다 더 많은 ),},] 가 들온다면 무조건 맞지 않는 괄호 조합이다.
				else check.push('F');
			}
		}
		printf("%s\n", check.size() == 0 ? "YES" : "NO");
	}

	return 0;
}
