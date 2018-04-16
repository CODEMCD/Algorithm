# 병합 정렬 (Merge Sort)

### 개념
![msort](https://user-images.githubusercontent.com/34755287/38076565-f2d6cbfa-3370-11e8-90ad-a969b7907dad.jpg)
- 분할 정복 알고리즘 디자인 기법을 활용한 정렬 방법이다.
- 재귀적으로 구현한다.

### 구현
~~~
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right)
	{
	           if(arr[fIdx] <= arr[rIdx])
	                   sortArr[sIdx]   = arr[fIdx++];
	           else
	                   sortArr[sIdx]   = arr[rIdx++];

	           sIdx++;
	}

	if(fIdx > mid)
	{
	           for(i=rIdx; i<=right; i++, sIdx++)
	                   sortArr[sIdx]   = arr[i];
	}
	else
	{
	           for(i=fIdx; i<=mid; i++, sIdx++)
            	          sortArr[sIdx]   = arr[i]
	}

	for(i=left; i<=right; i++)
	        arr[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right)
	{
	         // 중간 지점을 계산한다.
	         mid   = (left+right) / 2;

	         // 둘로 나눠서 각각을 정렬한다.
	         MergeSort(arr, left, mid);
	         MergeSort(arr, mid+1, right);

	         // 정렬된 두 배열을 병합한다.
	         MergeTwoArea(arr, left, mid, right);
	}
}
~~~
- 시간 복잡도 : O(NlogN)
- 공간 복잡도 : 임시 메모리가 필요하기 때문에 다른 정렬에 비해 크다.
