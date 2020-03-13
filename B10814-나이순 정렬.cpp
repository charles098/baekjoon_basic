// 백준 10814번 - 나이순 정렬
// stable_sort라는 것을 처음 알았다. 처음에는 sort를 써서 '틀렸습니다'가 뜨길래 구글링을 해보니깐 stable_sort라는게 따로 있었다.
// sort와의 차이점은 정렬후 동일값의 원소 순서를 보장해준다는 것이다. sort는 그렇지 않다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool sor(pair<int, string> a, pair<int,string> b) {
	return a.first < b.first;
}

int main() {
	int N, a;
	string b;
	cin >> N;
	vector<pair<int, string>> v;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	stable_sort(v.begin(), v.end(), sor);

	for (pair<int, string> elem : v)
		cout << elem.first << " " << elem.second << '\n';

	return 0;
}
