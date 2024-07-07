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
    void preOrder(IntNode* v) {
        visit(v);
        for(IntNode* w : v->child){
            preOrder(w);
        }
    }
    IntNode* getRoot() const { return root; }
    void visit(IntNode* v) {
        int max = v->ele;
        IntNode* curNode = v;
        while(curNode->par != NULL) {
            curNode = curNode->par;
            max = (max < curNode->ele) ? curNode->ele : max;
        }
        cout << max << " ";
    }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Tree tree;
        while(n--) {
            int x, y;
            cin >> x >> y;
            tree.insert(x, y);
        }
        IntNode* root = tree.getRoot();
        tree.preOrder(root);
        cout << endl;
    }
}