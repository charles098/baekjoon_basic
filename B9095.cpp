#include <iostream>
using namespace std;

int function(int num) {
	int* d = new int[num + 1];
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= num; i++) 
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	
	int temp = d[num];
	delete[] d;
	return temp;
}

int main() {

	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << function(num) << endl;
	}

	return 0;
}