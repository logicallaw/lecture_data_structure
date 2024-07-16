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
class BST{
private:
    IntNode* root;
    int n;
    int height = 0;
public:
    BST() {
        root = NULL;
        n = 0;
    }
    ~BST() {
        if(isEmpty()) return;
        deleteNodes(root);
    }
    bool isEmpty() const { return n == 0; }
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
    IntNode* findNode(int k, IntNode* v) {
        if(v != NULL) {
            if(k < v->ele) {
                return findNode(k, v->leftC);
            } else if (k == v->ele) {
                return v;
            } else {
                return findNode(k, v->rightC);
            }
        } else {
            return NULL;
        }
    }
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
    void insert(int k) {
        if(isEmpty()) {
            root = new IntNode;
            root->par = NULL;
            root->ele = k;
            n++;
        } else {
            IntNode* parNode = search(k, root);
            if(parNode != NULL) {
                IntNode* newNode = new IntNode;
                newNode->par = parNode;
                newNode->ele = k;
                if(k < parNode->ele) {
                    parNode->leftC = newNode;
                } else {
                    parNode->rightC = newNode;
                }
                n++;
            } else {
                return;
            }
        }
    }
    void postOrder(IntNode* v, int cnt) {
        if(v->leftC != NULL) {
            postOrder(v->leftC, cnt + 1);
        }
        if(v->rightC != NULL) {
            postOrder(v->rightC, cnt + 1);
        }
        if(height < cnt) {
            height = cnt;
        }
    }
    int getHeight() {
        if(root != NULL) {
            postOrder(root, 0);
        }
        return height; }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        BST b;
        int n;
        cin >> n;
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