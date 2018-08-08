# Binary Search / Lower Bound / Upper Bound

## 개요
- Binary Search: 원하는 값 K를 찾는 과정
- Lower Bound: **원하는 값 K 이상인 값**이 처음 나오는 위치를 찾는 과정
- Upper Bound: **원하는 값 K 초과인 값**이 처음 나오는 위치를 찾는 과정

## Lower Bound 알고리즘 과정
- arr[] = { 1, 3, 5, 7, 9, 11 }, target = 8 일때, Louwer Bound를 구하라.

![lb1](https://user-images.githubusercontent.com/34755287/43621351-e9a45a8e-9711-11e8-8dff-08bb8344244f.JPG)

- 시작 인덱스 = 0, 끝 인덱스 = 5, 중간 인덱스 = 2 이다.
  - 중간 인덱스 2의 값은 5이고, 이 값은 타겟인 8보다 작기 때문에 ```시작 인덱스 = 중간 인덱스 + 1```로 설정하고 다음 반복문으로 간다.

![lb2](https://user-images.githubusercontent.com/34755287/43621352-e9d10732-9711-11e8-87d3-2d40876bf51f.JPG)

- 시작 인덱스 = 3, 끝 인덱스 = 5, 중간 인덱스 = 4 이다.
  - 9는 타겟인 8보다 크기 때문에 ```끝 인덱스 = 중간 인덱스```로 설정하고 다음 반복문으로 간다.
  
![lb3](https://user-images.githubusercontent.com/34755287/43621354-e9fca306-9711-11e8-918e-4bf7b9584a28.JPG)

- 시작 인덱스 = 3, 끝 인덱스 = 4, 중간 인덱스 = 3 이다.
  - 7은 타겟 8보다 작기 때문에 ```시작 인덱스 = 중간 인덱스 + 1```로 설정한다.
  
![lb4](https://user-images.githubusercontent.com/34755287/43621355-ea290e96-9711-11e8-96b4-8b69c15574bc.JPG)

- 시작 인덱스 = 4, 끝 인덱스 = 4, 중간 인덱스 = 4 이다.
  - 시작 인덱스와 끝 인덱스가 같기 때문에 반복문에 들어가지 않으며, 끝 인덱스를 Lower Bound가 찾는 인덱스로 반환한다.

- Bound의 반환 값은 인덱스가 0부터 시작하므로 +1을 해서 몇 번째인지 바로 반환할 수도 있고, 반환받은 값에서 +1을해도 상관없다.
  
## 구현 코드

- Binary Search

___예제 코드___
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int binarySearch(int *arr, int size, int target)
{
	int first = 0;
	int last = size - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (arr[mid] == target)
			return mid;
		if (mid > target)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return -1;
}

int main()
{
	int arr[6] = { 1, 3, 5, 7, 9, 11 };
	int target = 8;
	int find;

	//Binary Search
	find = binarySearch(arr, sizeof(arr), target);
	printf("Binary Search, target: 8 => INDEX: %d, VALUE: %d\n", find, find == -1 ? -1 : arr[find]);

	return 0;
}
```

___결과___
```
Binary Search, target: 8 => INDEX: -1, VALUE: -1
```

- Lower Bound

___예제 코드___
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int lowerBound(int *arr, int size, int target)
{
	int start = 0;
	int end = size - 1;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (arr[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main()
{
	int arr[6] = { 1, 3, 5, 7, 9, 11 };
	int target = 8;
	int find;
  
	//Lower Bound
	find = lowerBound(arr, sizeof(arr), target);
	printf("Lower Bound, target: 8 => INDEX: %d, VALUE: %d\n", find, arr[find]);

	return 0;
}
```

___결과___
```
Lower Bound, target: 8 => INDEX: 4, VALUE: 9
```

- Upper Bound

___예제 코드___
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int upperBound(int *arr, int size, int target)
{
	int start = 0;
	int end = size - 1;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (arr[mid] <= target)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main()
{
	int arr[6] = { 1, 3, 5, 7, 9, 11 };
	int target = 8;
	int find;

	//Upper Bound
	find = upperBound(arr, sizeof(arr), target);
	printf("Upper Bound, target: 8 => INDEX: %d, VALUE: %d\n", find, arr[find]);

	return 0;
}
```

___결과___
```
Upper Bound, target: 8 => INDEX: 4, VALUE: 9
```
