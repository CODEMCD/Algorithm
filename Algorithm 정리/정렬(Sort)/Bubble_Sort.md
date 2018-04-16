# 버블 정렬 (Bubble Sort)
### 개념
![bubblesort](https://user-images.githubusercontent.com/34755287/38076305-2fe708f8-3370-11e8-8226-910b73e5af3d.jpg)

### 구현
~~~
//오름차순
for (int i = 0; i < N - 1; i++) {
	for (int j = i + 1; j < N; j++) {
	        if (arr[i] > arr[j]) {
	                int tmp = arr[j];
	                arr[j] = arr[i];
                        arr[i] = tmp;
	        }
	}
}
~~~
- 시간 복잡도 : O(N^2)
