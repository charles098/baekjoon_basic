// 백준 11399번 - ATM
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* list = new int[N]; // list 생성

	for (int i = 0; i < N; i++)
		cin >> list[i]; // 값 입력

	sort(list, list + N); // 오름차순 정렬

	int answer = 0; // 최종 정답
	int index = 0; // 배열 인덱스
	for (int i = N; i != 0; i--) {
		answer += list[index] * i; // 0번째 값은 N번 더하고, 1번째 값은 N-1번 더하고 ... 반복
		index++;
	}

	cout << answer;

	delete[] list;
	return 0;
}
