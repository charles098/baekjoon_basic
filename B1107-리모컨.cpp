// 백준 1107번 - 리모컨
// 제일 오래 걸린 문제..여러 가지 방법을 시도해보았지만 결국에는 모든 경우의 수를 전수조사 하는 방법을 택했다
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 사용 가능한 버튼으로 목표 채널에 도달할 수 있는지 검사하는 함수
// 도달 가능하면 true, 불가능하면 false 반환
bool check(vector<bool>& pos_b, int n) {
	string temp = to_string(n);
	for (int i = 0; i < temp.size(); i++) {
		if (pos_b[temp.at(i) - '0'] == false)
			return false;
	}
	return true;
}

int main() {
	int N, M, num, min;
	cin >> N >> M;
	vector<bool> pos_b(10, true); // 사용 가능 버튼 벡터
	
	for (int i = 0; i < M; i++) {
		cin >> num;
		pos_b[num] = false; // M개 숫자에 해당하는 인덱스 flase로
	}

	min = abs(N - 100); // 시작 최소값은 오직 +,-로만 움직였을때
						// 최소값이 이보다 클 수는 없다

	int temp;
	for (int i = 0; i < 1000001; i++) { // 0 ~ 1000000까지 전수조사
		if (check(pos_b, i)) {
			temp = abs(N - i) + to_string(i).size();
			// (윗줄) -> i번까지 버튼 조작 후 +,-로 조작해서 목표채널 도달
			min = min < temp ? min : temp; // 초기 설정한 min과 비교 후 초기화
		}
	}

	cout << min;

	return 0;
}
