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

bool in(vector<int> v, int value) { // 사용 가능 숫자인지 확인용 함수
	for (int i : v) 
		if (i == value)
			return true;
	return false;
}

int main() {
	string N;
	int M, num;
	cin >> N >> M;

	vector<int> erase_b; // 지우는 버튼
	for (int i = 0; i < M; i++) {
		cin >> num;
		erase_b.push_back(num);
	}
	
	vector<int> pos_b; // 사용 가능한 버튼
	for (int i = 0; i < 10; i++) 
		if (!in(erase_b, i))
			pos_b.push_back(i);
	
	const int START = 100;
	int just_ud; // 오직 +,-로만 N까지 도달
	int click_ud = 0; // 리모콘 사용 + 쁠마로 N까지 도달
	string click_num = ""; // 버튼으로 눌렀을 때의 새로운 채널

	just_ud = abs(atoi(N.c_str()) - START);
	int comp; // N의 한 자리수
	for (int i = 0; i < N.length(); i++) {
		comp = N.at(i) - '0';
		if (in(pos_b, comp)) // N의 앞자리부터 사용 가능한 버튼이면 선택
			click_num += (comp + '0');
		else {
			int up = comp++; int down = comp--;
			while (1) {
				if (up > 9 && down < 0) // 버튼 둘 다 범위를 넘어가면 멈춤
					break;
				if (in(pos_b, up)) { // 하나씩 더해가는게 사용 가능하면 멈춤
					click_num += (up + '0');
					break;
				}
				if (in(pos_b, down)) { // 하나씩 빼가는게 사용 가능하면 멈춤
					click_num += (down + '0');
					break;
				}
				up++;
				down--;
			}
		}
	}

	click_ud = N.length(); // 숫자 길이만큼 버튼 눌렀으니 더해준다
	int click_num_i = atoi(click_num.c_str()); // 버튼으로 누른 숫자를 int형으로 변환

	int answer = 0;

	if (click_num_i == atoi(N.c_str())) // 버튼 누른게 원하는 채널과 같으면
		answer = click_ud >= just_ud ? just_ud : click_ud;
	else { // 버튼 누른게 원하는 채널과 다르면
		click_ud += abs(click_num_i - atoi(N.c_str()));
		answer = click_ud >= just_ud ? just_ud : click_ud;
	}

	cout << endl << answer;

	return 0;
}
*/