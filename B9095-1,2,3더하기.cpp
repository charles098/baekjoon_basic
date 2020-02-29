// 백준 9095번 - 1, 2, 3 더하기
// 입력 숫자가 10 이하라서 그냥 손으로 계산 후 벡터에 넣어버렸다
// 사실 d[n] = d[i - 1] + d[i - 2] + d[i - 3] 이런 규칙이 있기는 하다
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, num;
	vector<int> a;
	vector<int> b{ 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274 };
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> num;
		a.push_back(b[num]);
	}

	for (int elem : a)
		cout << elem << endl;

	return 0;
}
