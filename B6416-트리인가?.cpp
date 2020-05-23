// 백준 6416번 - 트리인가? 
// 노드의 개수 = 간선의 개수 + 1, 아무 것도 없을 때도 트리임을 이용
// set을 사용하면 쉽게 풀 수 있다
// 한 쌍이 입력될때마다 간선은 하나씩 증가, 부모 노드는 중복될 수 있고 자식 노드는 unique하다. 이는 입력 과정에서 set이 알아서 처리해줌.
#include <iostream>
#include <set>
using namespace std;

int main() {
	
	int count = 0;
	int parent, child, branch;
	bool IsContinue = true;
	set<int> tree;

	while (IsContinue) {
		tree.clear();
		branch = 0;
		while (1) {
			cin >> parent >> child;
			if (parent == 0 && child == 0) {
				count++;
				if(tree.size() == 0 || branch+1 == tree.size())
					cout << "Case " << count << " is a tree." << endl;
				else
					cout << "Case " << count << " is not a tree." << endl;
				break;
			}
			if (parent < 0 && child < 0) {
				IsContinue = false;
				break;
			}
			tree.insert(parent), tree.insert(child);
			branch++;
		}
	}

	return 0;
}
