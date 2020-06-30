#include <iostream>
#include <utility>
#include <queue>
using namespace std;

enum class direction{right, down, up, left};

direction find_dir(direction dir, char c) {
	if (dir == direction::right) {
		if (c == 'L') return direction::up;
		else if(c == 'D') return direction::down;
	}
	if (dir == direction::down) {
		if (c == 'L') return direction::right;
		else if(c == 'D') return direction::left;
	}
	if (dir == direction::up) {
		if (c == 'L') return direction::left;
		else if(c == 'D') return direction::right;
	}
	if (dir == direction::left) {
		if (c == 'L') return direction::down;
		else if(c == 'D') return direction::up;
	}
}

int main() {
	int N, K, L, X, row, col;
	char C;
	int count = 0;
	pair<int, int> header = {0, 0};
	direction head_dir = direction::right;
	queue<pair<int, int>> snake;
	queue<pair<int, char>> turn;
	snake.push(header);
	
 	cin >> N;

	// N*N 크기의 동적 배열 생성
	int** list = new int*[N];
	for (int i = 0; i < N; i++)
		list[i] = new int[N];

	// 모두 0으로 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			list[i][j] = 0;

	list[header.first][header.second] = -1; // 초기 뱀 위치

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> row >> col;
		list[row - 1][col - 1] = 1; // 사과 위치 지정
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		turn.push({ X,C });
	}

	pair<int, char> temp = turn.front();
	X = temp.first;
	C = temp.second; 
	turn.pop();

	while (1) {
		// turn의 초에 도달하면 turn 초기화
		if (count == X) {
			head_dir = find_dir(head_dir, C);
			if (!turn.empty()) {
				temp = turn.front();
				X = temp.first;
				C = temp.second;
				turn.pop();
			}
		}

		// 머리 움직이기
		if (head_dir == direction::right) header.second += 1;
		else if (head_dir == direction::left) header.second -= 1;
		else if (head_dir == direction::up) header.first -= 1;
		else if (head_dir == direction::down) header.first += 1;

		if (!(0 <= header.first && header.first < N)) // 범위 초과
			break;
		if (!(0 <= header.second && header.second < N)) // 범위 초과
			break;
		else if (list[header.first][header.second] == -1) // 머리가 몸통 무는 경우
			break;

		// 사과가 아니면 꼬리칸 당기기
		if (list[header.first][header.second] == 0) {
			pair<int, int> temp2 = snake.front();
			list[temp2.first][temp2.second] = 0;
			snake.pop();
		}
		
		list[header.first][header.second] = -1;
		snake.push(header);
		count++;
	}

	// ++ 해주는 이유는 위에서 탈출하는 경우 마지막 count++가 실행되지 않기 떄문.
	cout << ++count;

	// 할당 해제
	for (int i = 0; i < N; i++)
		delete[] list[i];
	delete[] list;

	return 0;
}