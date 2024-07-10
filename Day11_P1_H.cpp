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
	int height;
public:
	BST() {
		root = NULL;
		n = 0;
		height = 0;
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
	void postOrder(IntNode* v, int cnt) {
		if (v->isLeft()) {
			postOrder(v->leftC, cnt + 1);
		}
		if (v->isRight()) {
			postOrder(v->rightC, cnt + 1);
		}
		if (height < cnt) {
			height = cnt;
		}
	}
	void printHeight() {
		postOrder(root, 0);
		cout << height << endl;
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
		bst.printHeight();
	}
}
/*
*
3
7
4 2 6 1 3 5 7
7
7 6 5 4 3 2 1
4
1 2 3 4

*/