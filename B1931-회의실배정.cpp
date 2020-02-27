// 백준 1931번 - 회의실 배정
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second)
		return a.first < b.first; // 회의 끝나는 시간이 같으면 시작시간 기준 오름차순 정렬
	else
		return a.second < b.second; // 그 외에는 회의 끝나는 시간 기준 오름차순 정렬
}

int main() {
	vector<pair<int, int>> v;
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y)); // pair 입력
	}

	sort(v.begin(), v.end(), cmp); // cmp대로 정렬

	int count = 0;
	int temp = 0; // 임이의 끝나는 시간 0으로 지정
	for (auto it = v.begin(); it != v.end(); it++)
		if (it->first >= temp) { // 회의 시작시간이 temp보다 크거나 같으면 시행
			count++; 
			temp = it->second; // temp 초기화
		}

	cout << count;

	return 0;
}
