#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	vector<pair<int, int>> v;
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), cmp);

	int count = 0;
	int temp = 0;
	for (auto it = v.begin(); it != v.end(); it++)
		if (it->first >= temp) {
			count++;
			temp = it->second;
		}

	cout << count;

	return 0;
}