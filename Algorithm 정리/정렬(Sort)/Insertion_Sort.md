# 삽입 정렬 (Insertion Sort)

### 개념
![insertsort](https://user-images.githubusercontent.com/34755287/38076494-be36814c-3370-11e8-937f-631e3ffda42e.jpg)
- 정렬이 완료된 영역의 다음에 위치한 데이터가 그 다음 정렬대상이다. (위 그림에서 파란색 영역이 정렬이 완료된 영역)
- 데이터를 한 칸씩 뒤로 밀면서 삽입할 위치를 찾는 것이 효율적이다.

### 구현
~~~
void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i = 1; i < n; i++)
	{
	        insData = arr[i];   // 정렬 대상을 insData에 저장

	        for(j = i - 1; j >= 0 ; j--)
	        {
	               if(arr[j] > insData) 
	                       arr[j+1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기
	               else
	                       break;   // 삽입 위치 찾았으니 탈출!
	        }

	        arr[j+1] = insData;  // 찾은 위치에 정렬 대상 삽입!
	}
}
~~~
- 시간 복잡도 : O(N^2)
