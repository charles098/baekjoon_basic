// 백준 2331번 - 반복수열
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> seq;
int visit[236197]; // 최대값
// 입력값이 9999, 5일때 최대값은 236196이고, 마지막 숫자를 추가해주기 위해 +1크기의 배열을 생성했다. 크기가 이보다 작으면 틀림.
int N, P, visited;

int cal(int a, int p) {
	string temp = to_string(a);
	int re = 0;
	for (int m = 0; m < temp.size(); m++)
		re += pow(temp[m] - '0',p);
	return re;
}

void dfs(int start) {
	if (visit[start]) {
		visited = start;
		return;
	}
	visit[start] = 1;
	seq.push_back(start);
	dfs(cal(start, P));
}

int main() {
	cin >> N >> P;
	dfs(N);
	
	int answer = 0;
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == visited)
			break;
		answer++;
	}

	cout << answer;

	return 0;
}
