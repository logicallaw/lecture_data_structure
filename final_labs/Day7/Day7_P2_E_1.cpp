#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Tree;
class IntNode{
private:
    IntNode* par;
    int ele;
    vector<IntNode*> child;
    friend class Tree;
};
class Tree{
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
        for(int i{ 0 }; i < nodes.size(); i++){
            delete nodes[i];
        }
    }
    bool isRoot(IntNode* v) const { return (v->par == NULL); }
    bool isExternal(IntNode* v) const { return (v->child.size() == 0); }
    IntNode* findNode(int e) {
        for (IntNode *node: nodes) {
            if (node->ele == e) {
                return node;
            }
        }
        return NULL;
    }
    void insert(int x, int y) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL) {
            cout << -1 << endl;
            return;
        }
        IntNode* nodeY = new IntNode;
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
    }
    void preOrder(IntNode* v) {
        cout << v->ele << " ";
        for(IntNode* w : v->child) {
            preOrder(w);
        }
    }
    void postOrder(IntNode* v) {
        for(IntNode* w : v->child) {
            postOrder(w);
        }
        cout << v->ele << " ";
    }
    IntNode* getRoot() const { return root; }
};
int main(void) {
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        Tree tree;
        while(m--){
            int x, y;
            cin >> x >> y;
            tree.insert(x, y);
        }
        IntNode* root = tree.getRoot();
        tree.preOrder(root);
        cout << endl;
        tree.postOrder(root);
        cout << endl;
    }
    return 0;
}