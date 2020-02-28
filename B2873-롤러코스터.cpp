// 백준 2873번 - 롤러코스터
// 어려워서 '여우와 팽귄의 블로그'를 참고했다
// 체스판의 개념을 알면 비교적 간단하게 풀 수 있다
// 좌상 칸을 흰색이라 가정하고 검은칸 중에 제일 최소값을 찾는게 핵심이다!
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1000][1000];

// 반복작업 방지를 위해 append함수 만들어줌
void append(string& s, char c, int end) {
	for (int i = 0; i < end; i++)
		s += c;
}

int main() {
	int row, col;
	cin >> row >> col; // 행, 열 입력

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j]; // 값 입력

	if (row % 2 == 1) { // 행이 홀수일 경우
		string result = "";
		while (row != 1) {
			append(result, 'R', col - 1);
			append(result, 'D', 1);
			append(result, 'L', col - 1);
			append(result, 'D', 1);
			row -= 2;
		}
		append(result, 'R', col - 1);
		cout << result;
	}
	else if (col % 2 == 1) { // 열이 홀수일 경우
		string result = "";
		while (col != 1) {
			append(result, 'D', row - 1);
			append(result, 'R', 1);
			append(result, 'U', row - 1);
			append(result, 'R', 1);
			col -= 2;
		}
		append(result, 'D', row - 1);
		cout << result;
	}
	else { // 행, 열 둘 다 짝수일 경우
		string result = "", rev = "";
		//최소값 찾기
		int x = 0, y = 1;
		int min = arr[0][1];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if ((i + j) % 2 == 1 && min > arr[i][j]) {
					min = arr[i][j];
					x = i, y = j;
				}
			}
		}
		// 초기값 설정 - 좌상, 우하
		int s_row = 0, s_col = 0, e_row = row - 1, e_col = col - 1;
		// 최소값 기준 아래위 두 행씩 제거
		while (e_row - s_row > 1) {
			if (s_row + 1 < x) { // 조건 걸리면 위에 두 행 제거
				append(result, 'R', col - 1);
				append(result, 'D', 1);
				append(result, 'L', col - 1);
				append(result, 'D', 1);
				s_row += 2;
			}
			if (e_row - 1 > x) { // 조건 걸리면 아래 두 행 제거
				append(rev, 'R', col - 1);
				append(rev, 'D', 1);
				append(rev, 'L', col - 1);
				append(rev, 'D', 1);
				e_row -= 2;
			}
		}
		// 최소값 기준 좌우 두 열씩 제거
		while (e_col - s_col > 1) { 
			if (s_col + 1 < y) { // 조건에 걸리면 왼쪽 두 열 제거
				append(result, 'D', 1);
				append(result, 'R', 1);
				append(result, 'U', 1);
				append(result, 'R', 1);
				s_col += 2;
			}
			if (e_col - 1 > y) { // 조건에 걸리면 오른쪽 두 열 제거
				append(rev, 'D', 1);
				append(rev, 'R', 1);
				append(rev, 'U', 1);
				append(rev, 'R', 1);
				e_col -= 2;
			}
		}
		if (x == e_row) { // 최소값이 아래쪽에 있으면 RD 추가
			append(result, 'R', 1);
			append(result, 'D', 1);
		}
		else if (x == s_row) { // 최소값이 위쪽에 있으면 DR 추가
			append(result, 'D', 1);
			append(result, 'R', 1);
		}
		reverse(rev.begin(), rev.end()); // rev 뒤집기
		result += rev;
		cout << result;
	}

	return 0;
}
