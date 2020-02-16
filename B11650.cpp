#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
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

	for (auto it = v.begin(); it != v.end(); it++)
		cout << it->first << " " << it->second << '\n';


	return 0;
}