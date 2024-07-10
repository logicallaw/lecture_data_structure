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
	void deleteNode(int x) {
		IntNode* nodeX = findNode(x, root);
		if (nodeX == NULL) {
			return;
		}
		//단말 노드
		if (isExternal(nodeX)) {
			IntNode* p = nodeX->par;
			if (p->leftC == nodeX) {
				p->leftC = NULL;
			}
			else if (p->rightC == nodeX) {
				p->rightC = NULL;
			}
			delete nodeX;
		}
		//둘 중 하나가 있을 때
		else if (nodeX->isLeft() || nodeX->isRight()) {
			IntNode* p = nodeX->par;
			if (nodeX->isLeft()) {
				p->leftC = nodeX->leftC;
			}
			else {
				p->rightC = nodeX->rightC;
			}
			delete nodeX;
		}
		else {
			IntNode* s = sucessor(nodeX->rightC);
			IntNode* p = s->par;
			p->leftC = s->rightC;
		}
		n--;
	}
	IntNode* sucessor(IntNode* v) {
		IntNode* curNode = v;
		while (curNode->isLeft()) {
			curNode = curNode->leftC;
		}
		return curNode;
	}
	void preOrder(IntNode* v) {
		cout << v->key << " ";
		if (v->isLeft()) {
;			preOrder(v->leftC);
		}
		if (v->isRight()) {
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
			int x;
			cin >> x;
			bst.insert(x);
		}
		int m;
		cin >> m;
		while (m--) {
			int x;
			cin >> x;
			bst.deleteNode(x);
		}
		if (bst.isEmpty()) {
			cout << 0 << endl;
		}
		else {
			IntNode* root = bst.getRoot();
			bst.preOrder(root);
			cout << endl;
		}
	}
}
/*
*
2
7
18 7 26 3 12 22 30
3
18 22 12
6
92 80 24 18 38 87
3
80 24 18

*/