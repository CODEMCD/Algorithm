# 선택 정렬 (Selection Sort)

### 개념
![selsort](https://user-images.githubusercontent.com/34755287/38076427-86adf57a-3370-11e8-9b9e-4d4d80a5c227.jpg)

### 구현
~~~
void SelSort(int arr[], int n)  // n : 배열크기
{
	int i, j;
	int maxIdx;
	int temp;

	for(i = 0; i < n-1; i++)
	{
	         maxIdx = i;    // 정렬 순서상 가장 앞서는 데이터의 index

	         for(j = i + 1; j < n; j++)   // 최소값 탐색
	         {
	                if(arr[j] < arr[maxIdx])
	                        maxIdx = j;
	         }

	         /* 교환 */
	         temp = arr[i];
	         arr[i] = arr[maxIdx];
	         arr[maxIdx] = temp;
	}
}
~~~
- 시간 복잡도 : O(N^2)
