#include <iostream>
using namespace std;
class BST;
class IntNode{
private:
    IntNode* par;
    int ele;
    IntNode* leftC = NULL;
    IntNode* rightC = NULL;
    friend class BST;
};
class BST {
private:
    IntNode* root;
    int n;
public:
    BST() : root{ NULL }, n{ 0 } {}
    ~BST() {
        deleteNodes(root);
    }
    void deleteNodes(IntNode* v) {
        if(v == NULL) return;
        if(v->leftC != NULL) {
            deleteNodes(v->leftC);
        }
        if(v->rightC != NULL) {
            deleteNodes(v->rightC);
        }
        delete v;
    }
    bool isEmpty() const { return n == 0; }
    IntNode* findNode(int k, IntNode* v) { //실제 키 값이 동일한 노드를 찾는다.
        if(v == NULL) return NULL;
        if(k < v->ele) {
            return findNode(k, v->leftC);
        } else if (k == v->ele) {
            return v;
        } else {
            return findNode(k, v->rightC);
        }
    }
    IntNode* search(int k, IntNode* v) {
        if(v == NULL) return NULL;
        if(k < v->ele) {
            if(v->leftC != NULL) {
                return search(k, v->leftC);
            } else {
                return v;
            }
        } else { // k >= v->ele
            if(v->rightC != NULL) {
                return search(k, v->rightC);
            } else {
                return v;
            }
        }
    }
    void insert(int x) {
        if(isEmpty()) {
            root = new IntNode;
            root->par = NULL;
            root->ele = x;
            n++;
        } else {
            //부모를 찾는다.
            IntNode* parNode = search(x, root);
            if(parNode == NULL) return; //부모가 없으면 종료한다.
            IntNode* newNode = new IntNode;
            newNode->par = parNode;
            newNode->ele = x;
//            if(parNode->leftC == NULL) {
//                parNode->leftC = newNode;
//            } else {
//                parNode->rightC = newNode;
//            }
            if(x < parNode->ele) {
                parNode->leftC = newNode;
            } else {
                parNode->rightC = newNode;
            }
            n++;
        }
    }
    int getDegree(IntNode* v) {
        if (v->leftC != NULL && v->rightC != NULL) {
            return 2;
        } else if (v->leftC != NULL || v->rightC != NULL) {
            return 1;
        } else {
            return 0;
        }
    }
    int getDepth(IntNode* v) {
        IntNode* curNode = v;
        int cnt = 0;
        while(curNode->par != NULL) {
            curNode = curNode->par;
            cnt++;
        }
        return cnt;
    }
    IntNode* getRoot() const { return root; }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        BST b;
        while(n--) {
            int x;
            cin >> x;
            b.insert(x);
        }
        int m;
        cin >> m;
        while(m--) {
            int x;
            cin >> x;
            IntNode* nodeX = b.findNode(x, b.getRoot());
            if(nodeX != NULL) {
                cout << b.getDegree(nodeX) << " " << b.getDepth(nodeX) << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}
/*
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