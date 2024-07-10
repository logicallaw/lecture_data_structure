#include <iostream>
#include <string>
using namespace std;
class BST;
class IntNode {
private:
	IntNode* par;
	int key;
	IntNode* leftC = NULL;
	IntNode* rightC = NULL;
	friend class BST;
};
class BST {
private:
	IntNode* root;
	int n;
public:
	BST() {
		root = NULL;
		n = 0;
	}
	bool isExternal(IntNode* v) const { return v->leftC == NULL && v->rightC == NULL; }
	bool isEmpty() const { return root == NULL; }
	IntNode* treeSearch(int k, IntNode* v) {
			if (k < v->key) {
				if (v->leftC != NULL) {
					treeSearch(k, v->leftC);
				}
				else {
					return v;
				}
			}
			else if (k == v->key) {
				return v;
			}
			else {
				if (v->rightC != NULL) {
					treeSearch(k, v->rightC);
				}
				else {
					return v;
				}
			}
	}
	void insert(int x) {
		if (isEmpty()) { //0개
			root = new IntNode;
			root->par = NULL;
			root->key = x;
			n++;
			return;
		}
		else {
			IntNode* curNode = treeSearch(x, root);
			if (curNode != NULL) {
				IntNode* newNode = new IntNode;
				newNode->par = curNode;
				newNode->key = x;
				if (x < curNode->key) {
					curNode->leftC = newNode;
				}
				else {
					curNode->rightC = newNode;
				}
			}
		}
	}
	void deleteNode(int x) {

	}
	void max(int k) {

	}
	void preOrder(IntNode* v) {
		cout << v->key << " ";
		if (v->leftC != NULL) {
			preOrder(v->leftC);
		}
		if (v->rightC != NULL) {
			preOrder(v->rightC);
		}
	}
	IntNode* getRoot() const { return root; }
};
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		BST bst;
		int n;
		cin >> n;
		while (n--) {
			string userInput;
			cin >> userInput;
			if (userInput == "insert") {
				int x;
				cin >> x;
				bst.insert(x);
			}
			else if (userInput == "delete") {
				int x;
				cin >> x;
				bst.deleteNode(x);
			}
			else if (userInput == "max") {
				int k;
				cin >> k;
				bst.max(k);
			}
			else if (userInput == "print") {
				IntNode* root = bst.getRoot();
				if (root != NULL) {
					bst.preOrder(root);
					cout << endl;
				}
			}
		}
	}
}
/*
5
20
insert 18
print
insert 7
print
insert 26
print

insert 3
insert 12
insert 


*/