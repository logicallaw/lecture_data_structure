#include <iostream>
#include <vector>
using namespace std;
class Tree;
class IntNode{
private:
    IntNode* par;
    int ele;
    int space;
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
        for(int i{ 0 }; i < nodes.size(); i++) {
            delete nodes[i];
        }
    }
    bool isRoot(IntNode* v) const { return v->par == NULL; }
    bool isExternal(IntNode* v) const { return v->child.size() == 0; }
    IntNode* findNode(int e) const {
        for(IntNode* node : nodes) {
            if(node->ele == e){
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
    void postOrder(IntNode* v) {
        for(IntNode* c : v->child) {
            postOrder(c);
        }
        visit(v);
    }
    void visit(IntNode* v) {
        if(isExternal(v)) {
            cout << depth(v, 0) << " ";
        } else {
            int min = v->child[0]->ele;
            for(IntNode* c : v->child) {
                min = (min > c->ele) ? c->ele : min;
            }
            cout << min << " ";
        }
    }
    int depth(IntNode* v, int d) {
        if(isRoot(v)) {
            return d;
        } else {
            return depth(v->par, d + 1);
        }
    }
    IntNode* getRoot() const { return root; }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        Tree tree;
        int n;
        cin >> n;
        n = n - 1;
        while(n--){
            int x, y;
            cin >> x >> y;
            tree.insert(x, y);
        }
        IntNode* root = tree.getRoot();
        tree.postOrder(root);
        cout << endl;
    }
}
