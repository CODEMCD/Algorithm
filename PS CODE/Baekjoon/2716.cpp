#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define N 151
string str;

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();
	while (n--) {
		str.clear();
		getline(cin, str);
		int len = str.length();
		//printf("%d\n", len);
		if (str[0] == 0) {
			printf("1\n");
			continue;
		}
		int level = 0;
		int max = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == '[') {
				level++;
				if (max < level)
					max = level;
			}
			else if (str[i] == ']')
				level--;
		}
		printf("%d\n", (int)pow(2, max));
	}

	return 0;
}