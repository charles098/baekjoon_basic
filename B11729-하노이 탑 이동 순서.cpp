// 백준 11729번 - 하노이 탑 이동 순서
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

void move(int from, int to) {
	v.push_back({ from,to });
}

void hanoi(int n, int from, int by, int to, int& count) {
	if (n == 1) {
		move(from, to);
		count++;
	}
	else {
		hanoi(n - 1, from, to, by, count);
		move(from, to);
		count++;
		hanoi(n - 1, by, from, to, count);
	}
}

int main() {
	int N, count = 0; 
	cin >> N;

	hanoi(N, 1, 2, 3, count);
	
	printf("%d\n", count);
	for (pair<int, int> pair : v)
		printf("%d %d\n", pair.first, pair.second);

	return 0;
}
