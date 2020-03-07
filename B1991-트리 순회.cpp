
// 백준 1991번 - 트리 순회
// 구조체, 트리, 세 가지 순회 개념을 처음 알아서 이 문제를 풀면서 배웠다. 코드는 블로그를 참고했다.
#include <iostream>
using namespace std;

typedef struct node {
	char leftChild;
	char rightChild;
}node;

node arr[27];

// 전위 순회
void preorder(char root) { 
	if (root == '.')
		return;
	else {
		cout << root;
		preorder(arr[root].leftChild);
		preorder(arr[root].rightChild);
	}
}

// 중위 순회
void inorder(char root) {
	if (root == '.')
		return;
	else {
		inorder(arr[root].leftChild);
		cout << root;
		inorder(arr[root].rightChild);
	}
}

// 후위 순회
void postorder(char root) {
	if (root == '.')
		return;
	else {
		postorder(arr[root].leftChild);
		postorder(arr[root].rightChild);
		cout << root;
	}
}

int main() {
	int n;
	char root, left, right;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> root >> left >> right;
		arr[root].leftChild = left;
		arr[root].rightChild = right;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}
