# 퀵 정렬 (Quick Sort)

### 개념
![qsort](https://user-images.githubusercontent.com/34755287/38076760-8d922f54-3371-11e8-839a-c1048b602523.JPG)
- low의 오른쪽 방향 이동 : pivot보다 정렬의 우선순위가 낮은 데이터를 만날 때까지 (오름차순 기준, pivot보다 큰 값을 만날때까지)
- low의 왼쪽 방향 이동 : pivot보다 정렬의 우선순위가 높은 데이터를 만날 때까지 (오름차순 기준, pivot보다 작은 값을 만날때까지)
1) 위 low와 high 모두 조건이 만족 되면 서로 값을 교환한다.
2) 계속 진행하여 low와 high의 위치가 서로 바뀌면 high와 pivot의 위치를 교환한다.
3) pivot값은 정렬이 완료된다.
4) left가 right보다 커질 때까지 1) ~ 3) 과정을 반복한다.

### 구현
~~~
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽! 
	int low = left+1;
	int high = right;

	while(low <= high)    // 교차되지 않을 때까지 반복
	{	
	        while(pivot >= arr[low] && low <= right)
	                 low++;

	        while(pivot <= arr[high] && high >= (left+1))
	                 high--;

	        if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
	                 Swap(arr, low, high);   // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
	        int pivot = Partition(arr, left, right);    // 둘로 나눠서 
	        QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
	        QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
	}
}
~~~
- 평균 시간 복잡도 : O(NlogN)
- 최악 시간 복잡도 : O(N^2)
- 최악의 경우는 pivot이 최대값이나 최소값을 선택할 때 이다. 이를 방지하기 위해서는 pivot을 선택하는 방식이 중요한데, 최대한 랜덤하게 선택하는 것이 좋다. (위의 구현은 가장 왼쪽이 pivot이라는 설정이다.)
- 최악의 경우가 있음에도 불구하고, 퀵정렬은 다른 정렬보다 평균적으로 가장 빠르다. 왜냐 하면, 데이터 이동횟수가 상대적으로 적고 별도의 메모리 공간을 요구하지 않는다. 또한 pivot을 설정하는 방식을 랜덤으로 설정한다면 최악의 경우가 나타날 확률은 거의 없기 때문이다.
