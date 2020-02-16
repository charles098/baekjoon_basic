#include <iostream>
using namespace std;

int n, quick[10000001];

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = a;
}
void quickSort(int start, int end)
{
	if (start >= end) return;
	int pivot = quick[(start + end) / 2];
	int left = start;
	int right = end;

	while (left <= right)
	{
		while (quick[left] < pivot) left++;
		while (quick[right] > pivot) right--;
		if (left <= right)
		{
			swap(quick[left], quick[right]);
			left++; right--;
		}
	}
	quickSort(start, right);
	quickSort(left, end);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &quick[i]);

	quickSort(0, n - 1);

	for (int j = 0; j < n; j++) // 출력
		printf("%d\n", quick[j]);

	return 0;
}

/*
void quickSort(int* data, int start, int end) {
	if (start >= end)
		return;

	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) { // 엇갈릴 때까지 반복
		while (data[i] <= data[pivot]) i++;
		while (data[j] >= data[pivot] && j > start) j--;
		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[i];
			data[i] = temp;
		}
		quickSort(data, start, j - 1);
		quickSort(data, j + 1, end);
	}
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
}
*/