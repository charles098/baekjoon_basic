// 백준 10819번 - 차이를 최대로
// next_permutation 함수를 처음 써보았다. 쓰기 전에 엄청 쩔쩔맸었는데 알고 나니 너무나도 쉬운 문제..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	int answer = 0;
	do {
		int result = 0;
		for (int i = 0; i < N - 1; i++) 
			result += abs(vec[i] - vec[i + 1]);
		answer = max(answer, result);
	} while (next_permutation(vec.begin(), vec.end())); // 모든 경우의 수 돌려보기

	cout << answer;

	return 0;
}
