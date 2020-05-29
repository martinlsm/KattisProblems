#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
	public:
		Node() : parent(this), size(1) {}

		Node* getRoot() {
			if (this == parent) {
				return this;
			}
			return parent->getRoot();
		}

		void makeUnion(Node* other) {
			Node* root1 = this->getRoot();
			Node* root2 = other->getRoot();
			
			if (root2->size > root1->size) {
				root2->makeUnion(root1);
			} else {
				root2->parent = root1;
				root1->size += root2->size;
			}
		}

		int getSize() {
			if (parent == this) {
				return size;
			}
			return parent->getSize();
		}

	private:
		Node* parent;
		int size;
};

int main() {
	int numTests;
	unordered_map<string, Node> names;
	cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		int F;
		cin >> F;
		for (int j = 0; j < F; j++) {
			string n1, n2;
			cin >> n1 >> n2;
			if (names.count(n1) == 0) {
				names[n1];
			}
			if (names.count(n2) == 0) {
				names[n2];
			}

			if (names[n1].getRoot() != names[n2].getRoot()) {
				names[n1].makeUnion(&names[n2]);
			}

			cout << names[n1].getSize() << "\n";

		}
		names.clear();
	}
}
