#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000001
int num[N];

void swap(int *arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int *arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > arr[low])
			low++;
		while (pivot < arr[high])
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}

void quicksort(int *arr, int left, int right)
{
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}

int main(void)
{	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	quicksort(num, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", num[i]);

	return 0;
}