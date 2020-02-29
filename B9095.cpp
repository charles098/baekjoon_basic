#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int list[10][10];
	int N;
	cin >> N;

	int* city = new int[N];

	for (int i = 0; i < N; i++)
		city[i] = i;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> list[i][j];
	
	int answer = 10000000;

	do{
		int result = 0, check = 0;
		for (int i = 0; i < N - 1; i++) {
			if (list[city[i]][city[i + 1]] == 0) {
				check++;
				break;
			}
			else
				result += list[city[i]][city[i + 1]];
		}
		if (check == 0 && list[city[N - 1]][city[0]] != 0) {
			result += list[city[N - 1]][city[0]];
			answer = min(answer, result);
		}
	} while (next_permutation(city, city + N));

	cout << answer;

	delete[] city;

	return 0;
}