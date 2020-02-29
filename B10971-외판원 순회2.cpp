// 백준 10971번 - 외판원 순회2
// 외판원이 갈 수 있는 모든 경우의 수를 다 세어 보았다. 완전탐색
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int list[10][10];
	int N;
	cin >> N;

	int* city = new int[N];

	for (int i = 0; i < N; i++) // next_permutation을 위해 오름차순 입력
		city[i] = i;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> list[i][j];
	
	int answer = 10000000; // 값이 백만을 넘어갈 수 없어서 이렇게 설정

	do{
		int result = 0, check = 0;
		for (int i = 0; i < N - 1; i++) {
			if (list[city[i]][city[i + 1]] == 0) { // 길이 막혀있는 경우는 계산해주면 안됨
				check++; // 체크 변수를 통해 길이 막혔는지 확인
				break;
			}
			else
				result += list[city[i]][city[i + 1]];
		}
		if (check == 0 && list[city[N - 1]][city[0]] != 0) { // 길이 안막히고 마지막에 다시 돌아가는 길도 안막히는 경우만 해줌
			result += list[city[N - 1]][city[0]];
			answer = min(answer, result);
		}
	} while (next_permutation(city, city + N));

	cout << answer;

	delete[] city;

	return 0;
}
