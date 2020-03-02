// 백준 1525번 - 퍼즐
// 사실상 손도 못댄 문제.. 너무 어려워서 답을 보았지만 이해하는데 꽤나 시간이 걸렸다.
// 비트마스크의 개념을 처음 알았다 사실상 이게 문제의 핵심이다.
// 입력값을 2차원 배열로 생각하는 것이 아니라 하나의 수로 생각해서 경우를 따져봐야 하고, 행과 열은 /3 %3으로 나타낼 수 있다.
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

// 동서남북 이동
int move_x[] = { -1, 1, 0, 0 };
int move_y[] = { 0, 0, 1, -1 };

// 값 입력
void input(int& start) {
	int temp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			if (temp == 0)
				temp = 9;
			start = start * 10 + temp;
		}
	}
}

int main() {
	int start = 0;
	input(start);

	// bfs
	queue<int> q;
	map<int, int> m;
	m[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int pos = q.front();
		string pos_s = to_string(pos);
		q.pop();

		int nine = pos_s.find('9'); // 9의 위치
		int x = nine / 3; // 9의 행
		int y = nine % 3; // 9의 열

		for (int i = 0; i < 4; i++) {
			int xx = x + move_x[i];
			int yy = y + move_y[i];

			if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) { // 아동값이 범위를 넘어가지 않으면
				string tmp = pos_s;
				swap(tmp[nine], tmp[3 * xx + yy]); // swap
				if (m.count(atoi(tmp.c_str())) == 0) { // 방문하지 않은 값이면
					m[atoi(tmp.c_str())] = m[pos] + 1; // +1
					q.push(atoi(tmp.c_str())); // 큐에 추가
				}
			}
		}
	}

	if (m.count(123456789) == 0) // map의 key들 중에 123456789가 있으면
		cout << -1;
	else
		cout << m[123456789];
	return 0;
}
