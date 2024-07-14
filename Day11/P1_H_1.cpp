#include <iostream>
using namespace std;
class BST;
class IntNode{
private:
    IntNode* par = NULL;
    int ele = -1;
    IntNode* leftC = NULL;
    IntNode* rightC = NULL;
    friend class BST;
};
class BST{
private:
    IntNode* root;
    int n;
    int height;
public:
    BST() : root {NULL}, n {0}, height{ 0 } {}
    ~BST() {
        deleteNodes(root);
    }
    void deleteNodes(IntNode* v) {
        if(v == NULL) return;
        if(v->leftC != NULL){
            deleteNodes(v->leftC);
        }
        if(v->rightC != NULL){
            deleteNodes(v->rightC);
        }
        delete v;
    }
    bool isEmpty() const { return n == 0; }
    IntNode* search(int k, IntNode* v) {
        if(v != NULL) {
            if(k < v->ele) {
                if(v->leftC != NULL) {
                    return search(k, v->leftC);
                } else {
                    return v;
                }
            } else {
                if(v->rightC != NULL) {
                    return search(k, v->rightC);
                } else {
                    return v;
                }
            }
        } else {
            return NULL;
        }
    }
    IntNode* findNode(int k, IntNode* v) {
        if(v != NULL) {
            if(k < v->ele) {
                return findNode(k, v->leftC);
            } else if (k == v->ele) {
                return v;
            } else {
                return findNode(k,v->rightC);
            }
        } else {
            return NULL;
        }
    }
    void insert(int k) {
        if(isEmpty()) {
            root = new IntNode;
            root->par = NULL;
            root->ele = k;
            n++;
        } else {
            IntNode* parNode = search(k, root);
            if(parNode == NULL) return;
            IntNode* newNode = new IntNode;
            newNode->par = parNode;
            newNode->ele = k;
            if(k < parNode->ele) {
                parNode->leftC = newNode;
            } else {
                parNode->rightC = newNode;
            }
            n++;
        }
    }
    IntNode* getRoot() const { return root; }
    int getDegree(IntNode* v) const {
        if(v->leftC != NULL && v->rightC != NULL) {
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
        while(curNode->par != NULL){
            cnt++;
            curNode = curNode->par;
        }
        return cnt;
    }
    int getHeight() {
        postOrder(root, 0);
        return height;
    }
    void postOrder(IntNode* v, int cnt) {
        if(v->leftC != NULL) {
            postOrder(v->leftC, cnt + 1);
        }
        if(v->rightC != NULL) {
            postOrder(v->rightC, cnt + 1);
        }
        if(height < cnt){
            height = cnt;
        }
    }
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
        cout << b.getHeight() << endl;
    }
}
/*
3
7
4 2 6 1 3 5 7
7
7 6 5 4 3 2 1
4
1 2 3 4
 */