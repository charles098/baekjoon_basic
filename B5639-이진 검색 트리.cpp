// 백준 5639번 - 이진 검색 트리
// 자료구조 시간에 배운 이진트리 코드를 참고해서 풀었다
#include <iostream>
using namespace std;

typedef int ItemType;
struct TreeNode {
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

class TreeType {
public:
	TreeType();
	void InsertItem(ItemType item);
	void PostOrder();
private:
	TreeNode* root;
};

TreeType::TreeType() {
	root = NULL;
}

void Insert(TreeNode*& tree, ItemType item);

void TreeType::InsertItem(ItemType item) {
	Insert(root, item);
}

void Insert(TreeNode*& tree, ItemType item) {
	if (tree == NULL) {
		tree = new TreeNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if (item < tree->info)
		Insert(tree->left, item);
	else
		Insert(tree->right, item);
}

void Imp_PostOrder(TreeNode* tree) {
	if (tree != NULL) {
		Imp_PostOrder(tree->left);
		Imp_PostOrder(tree->right);
		cout << tree->info << endl;
	}
}
void TreeType::PostOrder() {
	Imp_PostOrder(root);
}

int main() {
	int value;
	TreeType tree;
	while (scanf("%d", &value) != EOF) {
		tree.InsertItem(value);
	}
	tree.PostOrder();

	return 0;
}
