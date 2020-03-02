// 백준 1963번 - 소수 경로
// bfs를 활용한 최단경로 찾기 문제. bfs를 공부한지 얼마 안돼서 정답률이 높음에도 불구하고 굉장히 해맸다.
#include <iostream>
#include <queue>
#include <string> 
using namespace std;

int visit[10000];
int prime[10000];
int T, start, goal;

// 모든 소수의 index를 1로 초기화
void init_prime() {
	for (int i = 1000; i < 10000; i++) {
		int check = 0;
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				check++;
		if (check == 0)
			prime[i] = 1;
	}
}

// 방문 배열 0으로 초기화
void init_visit() {
	for (int i = 0; i < 10000; i++)
		visit[i] = 0;
}

void bfs(int s) {
	queue<int> q;
	visit[s] = 1;
	q.push(s);
	int check2; // impossible인 경우와 (자신 -> 자신)의 경우를 구분해주기 위한 변수
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		if (pos == goal) {
			check2++; // 이 경우 visit[goal] == 0 이지만 check2 != 0 이기 때문에 불가능하지는 않다
			visit[pos] -= 1; // 처음에 visit[s] = 1로 시작하기 때문에 1 빼줘야한다
			break;
		}
		for (int i = 0; i < 4; i++) { // 네 자리 숫자를 다 변경해본다
			string num = to_string(pos);
			for (int j = 0; j < 10; j++) { // 0~9로 차례대로 변경해본다
				if (i == 0 && j == 0) // 천의 자리 수가 0이 되는 것을 방지
					continue;
				num[i] = j + '0';
				int num_int = atoi(num.c_str());
				if (prime[num_int] && !visit[num_int]) { // 탐색한게 소수이고 방문하지 않았으면
					q.push(num_int);
					visit[num_int] = visit[pos] + 1;
				}
			}
		}
	}
	if (visit[goal] == 0 && check2 == 0)
		cout << "impossible" << endl;
	else
		cout << visit[goal] << endl;
}

int main() {
	init_prime();
	cin >> T;
	for (int i = 0; i < T; i++) {
		init_visit();
		cin >> start >> goal;
		bfs(start);
	}

	return 0;
}
