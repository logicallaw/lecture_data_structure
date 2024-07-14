#include <iostream>
using namespace std;
class BST;
class IntNode {
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
                if (v->rightC != NULL) {
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
    IntNode* successor(IntNode* v) {
        IntNode* curNode = v;
        while(curNode->leftC != NULL) {
            curNode = curNode->leftC;
        }
        return curNode;
    }
    void erase(int k) {
        IntNode* delNode = findNode(k, root);
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
            if(childNode != NULL) {
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
        BST b;
        int n;
        cin >> n;
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
        cout << endl;
    }
    return 0;
}