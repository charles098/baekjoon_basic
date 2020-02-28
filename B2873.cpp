#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1000][1000];

// �ݺ��۾� ������ ���� append�Լ� �������
void append(string& s, char c, int end) {
	for (int i = 0; i < end; i++)
		s += c;
}

int main() {
	int row, col;
	cin >> row >> col; // ��, �� �Է�

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j]; // �� �Է�

	if (row % 2 == 1) { // ���� Ȧ���� ���
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
	else if (col % 2 == 1) { // ���� Ȧ���� ���
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
	else { // ��, �� �� �� ¦���� ���
		string result = "", rev = "";
		//�ּҰ� ã��
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
		// �ʱⰪ ���� - �»�, ����
		int s_row = 0, s_col = 0, e_row = row - 1, e_col = col - 1;
		// �ּҰ� ���� �Ʒ��� �� �྿ ����
		while (e_row - s_row > 1) {
			if (s_row + 1 < x) { // ���� �ɸ��� ���� �� �� ����
				append(result, 'R', col - 1);
				append(result, 'D', 1);
				append(result, 'L', col - 1);
				append(result, 'D', 1);
				s_row += 2;
			}
			if (e_row - 1 > x) { // ���� �ɸ��� �Ʒ� �� �� ����
				append(rev, 'R', col - 1);
				append(rev, 'D', 1);
				append(rev, 'L', col - 1);
				append(rev, 'D', 1);
				e_row -= 2;
			}
		}
		// �ּҰ� ���� �¿� �� ���� ����
		while (e_col - s_col > 1) { 
			if (s_col + 1 < y) { // ���ǿ� �ɸ��� ���� �� �� ����
				append(result, 'D', 1);
				append(result, 'R', 1);
				append(result, 'U', 1);
				append(result, 'R', 1);
				s_col += 2;
			}
			if (e_col - 1 > y) { // ���ǿ� �ɸ��� ������ �� �� ����
				append(rev, 'D', 1);
				append(rev, 'R', 1);
				append(rev, 'U', 1);
				append(rev, 'R', 1);
				e_col -= 2;
			}
		}
		if (x == e_row) { // �ּҰ��� �Ʒ��ʿ� ������ RD �߰�
			append(result, 'R', 1);
			append(result, 'D', 1);
		}
		else if (x == s_row) { // �ּҰ��� ���ʿ� ������ DR �߰�
			append(result, 'D', 1);
			append(result, 'R', 1);
		}
		reverse(rev.begin(), rev.end()); // rev ������
		result += rev;
		cout << result;
	}

	return 0;
}