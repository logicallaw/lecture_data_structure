#include <iostream>
#include <vector>
using namespace std;
class Tree;
class IntNode{
private:
    IntNode* par;
    int ele;
    vector<IntNode*> child;
    friend class Tree;
};
class Tree {
private:
    IntNode* root;
    vector<IntNode*> nodes;
public:
    Tree() {
        root = new IntNode;
        root->par = NULL;
        root->ele = 1;
        nodes.push_back(root);
    }
    ~Tree() {
        for(int i{ 0 }; i < nodes.size(); i++) {
            delete nodes[i];
        }
    }
    bool isRoot(IntNode* v) const { return v->par == NULL; }
    bool isExternal(IntNode* v) const { return v->child.size() == 0; }
    IntNode* findNode(int x) {
        for(IntNode* node : nodes) {
            if(node->ele == x) {
                return node;
            }
        }
        return NULL;
    }
    void insert(int x, int y) {
        IntNode* nodeX = findNode(x);
        IntNode* nodeY = findNode(y);
        if(nodeY != NULL || nodeX == NULL) {
            return;
        }
        nodeY = new IntNode;
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
    }
//    int folderTotal(IntNode* v) {
//        if(isRoot(v)) {
//            return 0;
//        } else {
//            v = v->par;
//            return folderTotal(v) + v->ele;
//        }
//    }
    int folderTotal(IntNode* v) {
        IntNode* curNode = v;
        int total = 0;
        while(curNode->par != NULL) {
            curNode = curNode->par;
            total += curNode->ele;
        }
        return total;
    }
};
int main(void) {
    int n, m;
    cin >> n >> m;
    Tree tree;
    int cnt = n - 1;
    while(cnt--) {
        int x, y;
        cin >> x >> y;
        tree.insert(x, y);
    }
    while(m--) {
        int x;
        cin >> x;
        IntNode* nodeX = tree.findNode(x);
        if(tree.isExternal(nodeX)) {
            cout << "D ";
        } else {
            cout << "F ";
        }
        cout << tree.folderTotal(nodeX) << endl;
    }
}