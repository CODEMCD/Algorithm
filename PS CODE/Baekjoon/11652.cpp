#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000001
long long num[N];
/*
void swap(long long *arr, int idx1, int idx2)
{
	long long temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(long long *arr, int left, int right)
{
	long long pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot <= arr[high] && high >= (left + 1))
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}

void quicksort(long long *arr, int left, int right)
{
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}
*/
int main(void)
{
	int n, cnt, maxCnt;
	long long ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &num[i]);
	//quicksort(num, 0, n - 1);
	sort(num, num + n);

	cnt = 1;
	maxCnt = 1;
	ans = num[0];
	for (int i = 1; i < n; i++) {
		if (num[i] == num[i - 1]) {
			cnt++;
		}
		else
			cnt = 1;
		if (maxCnt < cnt) {
			maxCnt = cnt;
			ans = num[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}