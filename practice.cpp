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