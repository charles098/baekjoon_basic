#include <iostream>
#include <vector>
using namespace std;

int main() {

	do {
		cout << 1;
	} while (0);

	return 0;
}



/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool in(vector<int> v, int value) { // ��� ���� �������� Ȯ�ο� �Լ�
	for (int i : v) 
		if (i == value)
			return true;
	return false;
}

int main() {
	string N;
	int M, num;
	cin >> N >> M;

	vector<int> erase_b; // ����� ��ư
	for (int i = 0; i < M; i++) {
		cin >> num;
		erase_b.push_back(num);
	}
	
	vector<int> pos_b; // ��� ������ ��ư
	for (int i = 0; i < 10; i++) 
		if (!in(erase_b, i))
			pos_b.push_back(i);
	
	const int START = 100;
	int just_ud; // ���� +,-�θ� N���� ����
	int click_ud = 0; // ������ ��� + �ܸ��� N���� ����
	string click_num = ""; // ��ư���� ������ ���� ���ο� ä��

	just_ud = abs(atoi(N.c_str()) - START);
	int comp; // N�� �� �ڸ���
	for (int i = 0; i < N.length(); i++) {
		comp = N.at(i) - '0';
		if (in(pos_b, comp)) // N�� ���ڸ����� ��� ������ ��ư�̸� ����
			click_num += (comp + '0');
		else {
			int up = comp++; int down = comp--;
			while (1) {
				if (up > 9 && down < 0) // ��ư �� �� ������ �Ѿ�� ����
					break;
				if (in(pos_b, up)) { // �ϳ��� ���ذ��°� ��� �����ϸ� ����
					click_num += (up + '0');
					break;
				}
				if (in(pos_b, down)) { // �ϳ��� �����°� ��� �����ϸ� ����
					click_num += (down + '0');
					break;
				}
				up++;
				down--;
			}
		}
	}

	click_ud = N.length(); // ���� ���̸�ŭ ��ư �������� �����ش�
	int click_num_i = atoi(click_num.c_str()); // ��ư���� ���� ���ڸ� int������ ��ȯ

	int answer = 0;

	if (click_num_i == atoi(N.c_str())) // ��ư ������ ���ϴ� ä�ΰ� ������
		answer = click_ud >= just_ud ? just_ud : click_ud;
	else { // ��ư ������ ���ϴ� ä�ΰ� �ٸ���
		click_ud += abs(click_num_i - atoi(N.c_str()));
		answer = click_ud >= just_ud ? just_ud : click_ud;
	}

	cout << endl << answer;

	return 0;
}
*/