// 백준 1476번 - 날짜 계산
#include <iostream>
using namespace std;

int main() {
	int e = 1, s = 1, m = 1, count = 1;

	int E, S, M;
	cin >> E >> S >> M;
	

	while (!(e == E && s == S && m == M)) {
		e++; s++; m++; count++;
		if (e == 16) e = 1; // 각각 범위 넘어가면 1로 초기화
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}

	cout << count;

	return 0;
}
