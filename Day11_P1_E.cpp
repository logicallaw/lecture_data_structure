#include <iostream>
using namespace std;
class BST;
class IntNode {
private:
	IntNode* par;
	int key;
	IntNode* leftC = NULL;
	IntNode* rightC = NULL;
	bool isLeft() const { return leftC != NULL; }
	bool isRight() const { return rightC != NULL; }
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
	~BST() {
		treeDestructor(root);
	}
	void treeDestructor(IntNode* rootNode) {
		if (rootNode == NULL) {
			return;
		}
		if (rootNode->isLeft()) {
			treeDestructor(rootNode->leftC);
		}
		if (rootNode->isRight()) {
			treeDestructor(rootNode->rightC);
		}
		delete rootNode;
	}
	IntNode* treeSearch(int k, IntNode* v) { //insert를 위해 적절한 노드를 찾는다.
		if (v == NULL) {
			return NULL;
		}
		if (k < v->key) {
			if (v->isLeft()) {
				treeSearch(k, v->leftC);
			}
			else {
				return v;
			}
		}
		else if (k >= v->key) {
			if (v->isRight()) {
				treeSearch(k, v->rightC);
			}
			else {
				return v;
			}
		}
	}
	bool isExternal(IntNode* v) const { return !v->isLeft() && !v->isRight(); }

	IntNode* findNode(int k, IntNode* v) { //키가 동일한 첫번째 노드를 찾는다.
		if (v != NULL) {
			if (k < v->key) {
				findNode(k, v->leftC);
			}
			else if (k == v->key) {
				return v;
			}
			else {
				findNode(k, v->rightC);
			}
		}
		else {
			return NULL;
		}
	}
	bool isEmpty() const { return n == 0; }
	void insert(int x) {
		if (isEmpty()) {
			root = new IntNode;
			root->par = NULL;
			root->key = x;
			n++;
		}
		else {
			IntNode* curNode = treeSearch(x, root);
			if (curNode == NULL) {
				return;
			}
			IntNode* newNode = new IntNode;
			newNode->par = curNode;
			newNode->key = x;
			if (x < curNode->key) {
				curNode->leftC = newNode;
			}
			else { //x >= curNode->key
				curNode->rightC = newNode;
			}
			n++;
		}
	}
	int getDegree(IntNode* v) {
		if (v->isLeft() && v->isRight()) {
			return 2;
		}
		else if (v->isLeft() || v->isRight()) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int getDepth(IntNode* v) {
		int d = 0;
		while (v->par != NULL) {
			d++;
			v = v->par;
		}
		return d;
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
			int x;
			cin >> x;
			bst.insert(x);
		}
		int m;
		cin >> m;
		while (m--) { //내가 탐색할 노드
			int x;
			cin >> x;
			IntNode* root = bst.getRoot();
			IntNode* nodeX = bst.findNode(x, root);
			if (nodeX == NULL) {
				cout << 0 << endl;
			}
			else {
				cout << bst.getDegree(nodeX) << " " << bst.getDepth(nodeX) << endl;
			}
		}
	}
	//int n;
	//cin >> n;
	//BST b;
	//while (n--) {
	//	string userInput;
	//	cin >> userInput;
	//	if (userInput == "insert") {
	//		int x;
	//		cin >> x;
	//		b.insert(x);
	//	}
	//	else if (userInput == "print") {
	//		IntNode* rootNode = b.getRoot();
	//		if (rootNode != NULL) {
	//			b.preOrder(rootNode);
	//			cout << endl;
	//		}
	//	}
	//}
}
/*
20
insert 10
print
insert 20
print
insert 15
print
insert 5
print
insert 3
insert 6
print


*/
/*
*
2
7
15 10 5 12 11 14 17
3
12 10 20
6
92 80 24 18 38 87
6
24 87 92 18 80 38

*/