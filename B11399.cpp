#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* list = new int[N];

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list, list + N);

	int answer = 0;
	int index = 0;
	for (int i = N; i != 0; i--) {
		answer += list[index] * i;
		index++;
	}

	cout << answer;

	delete[] list;
	return 0;
}