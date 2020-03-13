// 백준 11651번 - 좌표 정렬하기2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sor(pair<int, int> a, pair<int,int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int N, a, b;
	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	sort(v.begin(), v.end(), sor);

	for (pair<int, int> elem : v)
		cout << elem.first << " " << elem.second << '\n';
	return 0;
}
