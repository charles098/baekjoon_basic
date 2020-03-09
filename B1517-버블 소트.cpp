// 백준 1517번 - 버블 소트
// 제목은 속임수다. 버블 소트 알고리즘을 쓰면 시간초과가 나온다. 병합 정렬을 이용해야 풀 수 있는 문제다
// 알고리즘은 병합 정렬과 완전하게 동일하고 다른 점이라고는 "// 이 부분만 추가" 라고 주석처리해놓은 행 뿐이다.
// 병합 정렬은 두 개의 묶음이 정렬된 상태에서 앞에부터 하나씩 빼서 정렬하는 방식이다. 
// 따라서 swap을 해줘야 하는 경우는 뒤 묶음에서 뺄때만 해당된다. 단, 앞 묶음에서 다 빠졌다면 해당되지 않는다.
// 즉 앞 묶음이 다 빠지지 않은 상태에서 뒤 묶음이 빠질때만 swap이 일어난다고 볼 수 있다.
// 두 묶음은 다 정렬된 상태이므로 항상 middle + 1부터 swap이 일어난다고 볼 수 있다. 
// 앞 묶음의 i와 바뀔때까지 swap해주면 되므로 middle + 1 - i만큼 swap이 일어난다.

#include <iostream>
using namespace std;

int N;
int sorted[500000], arr[500000];
long long sp = 0;

void merge(int a[], int m, int middle, int n) {
	int i = m; 
	int j = middle + 1; 
	int k = m; 
	long long cnt = 0;
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k++] = a[i++];
		}
		else {
			sp += middle + 1 - i; // 이 부분만 추가
			sorted[k++] = a[j++];
		}
	}
	// 앞 묶음이 먼저 다 채워짐
	if (i > middle)
		for (int t = j; t <= n; t++)
			sorted[k++] = a[t]; 
	// 뒤 묶음이 먼저 다 채워짐
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k++] = a[t];
		}
	}

	for (int t = m; t <= n; t++)
		a[t] = sorted[t];
}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	mergeSort(arr, 0, N - 1);
	
	cout << sp;

	return 0;
}
