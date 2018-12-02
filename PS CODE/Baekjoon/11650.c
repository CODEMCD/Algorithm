#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100001

typedef struct _point
{
	int xpos;
	int ypos;
} Point;
Point ppos[N];

void swap(Point *arr, int idx1, int idx2)
{
	Point temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partitionX(Point *arr, int left, int right)
{
	int pivot = arr[left].xpos;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot >= arr[low].xpos && low <= right)
			low++;
		while (pivot <= arr[high].xpos && high >= (left + 1))
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}

void quicksortX(Point *arr, int left, int right)
{
	if (left <= right) {
		int pivot = partitionX(arr, left, right);
		quicksortX(arr, left, pivot - 1);
		quicksortX(arr, pivot + 1, right);
	}
}

int partitionY(Point *arr, int left, int right)
{
	int pivot = arr[left].ypos;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot >= arr[low].ypos && low <= right)
			low++;
		while (pivot <= arr[high].ypos && high >= (left + 1))
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}

void quicksortY(Point *arr, int left, int right)
{
	if (left <= right) {
		int pivot = partitionY(arr, left, right);
		quicksortY(arr, left, pivot - 1);
		quicksortY(arr, pivot + 1, right);
	}
}

int main(void)
{
	int n, start, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &ppos[i].xpos, &ppos[i].ypos);

	quicksortX(ppos, 0, n - 1);
	for (int i = 0; i < n; i++) {
		start = 0; end = 0;
		if (ppos[i].xpos == ppos[i + 1].xpos) {
			start = i; end = i;
			for (int j = i + 1; j < n; j++) {
				if (ppos[i].xpos == ppos[j].xpos)
					end++;
				else
					break;
			}
			quicksortY(ppos, start, end);
			i = end;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", ppos[i].xpos, ppos[i].ypos);

	return 0;
}