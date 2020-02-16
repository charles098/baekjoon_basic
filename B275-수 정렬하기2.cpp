// 백준 2751번 - 수 정렬하기2
// 퀵정렬 문제로 유투브 영상을 보면서 이해힜다.
// 아래 위 둘 다 같은 방법이지만 위에 방법이 더 속도가 빠르다.
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

	for (int j = 0; j < n; j++) // Ãâ·Â
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

	while (i <= j) { // ¾ù°¥¸± ¶§±îÁö ¹Ýº¹
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
