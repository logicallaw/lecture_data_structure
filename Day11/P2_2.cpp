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
            if(x < parNode->ele) {
                parNode->leftC = newNode;
            } else {
                parNode->rightC = newNode;
            }
            n++;
        }
    }
    void erase(int x) {
        IntNode* delNode = findNode(x, root);
        if(delNode == NULL) return;
        IntNode* parNode = delNode->par;
        IntNode* childNode;
        if(delNode->leftC == NULL && delNode->rightC == NULL) {
            childNode = NULL;
        } else if (delNode->leftC != NULL && delNode->rightC == NULL) {
            childNode = delNode->leftC;
        } else if (delNode->leftC == NULL && delNode->rightC != NULL) {
            childNode = delNode->rightC;
        } else {
            IntNode* ssNode = successor(delNode->rightC);
            delNode->ele = ssNode->ele;
            delNode = ssNode;
            parNode = delNode->par;
            childNode = delNode->rightC;
        }
        if(parNode == NULL) {
            root = childNode;
            if(childNode != NULL){
                childNode->par = NULL;
            }
        } else if (parNode->leftC == delNode) {
            parNode->leftC = childNode;
            if(childNode != NULL) {
                childNode->par = parNode;
            }
        } else {
            parNode->rightC = childNode;
            if(childNode != NULL) {
                childNode->par = parNode;
            }
        }
        delete delNode;
    }
    IntNode* successor(IntNode* v) {
        IntNode* curNode = v;
        while(curNode->leftC != NULL) {
            curNode = curNode->leftC;
        }
        return curNode;
    }
    void preOrder(IntNode* v) {
        cout << v->ele << " ";
        if(v->leftC != NULL) {
           preOrder(v->leftC);
        }
        if(v->rightC != NULL) {
            preOrder(v->rightC);
        }
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
            b.erase(x);
        }
        b.preOrder(b.getRoot());
    }
}
/*
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