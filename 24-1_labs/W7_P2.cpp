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
    void setSpace(int x, int y) {
        IntNode* nodeX = findNode(x);
        nodeX->space = y;
    }
    int getTotalSpace(IntNode* v) {
        if(isExternal(v)){
            return v->space;
        } else {
            int sum = v->space;
            for(IntNode* c : v->child){
                sum += getTotalSpace(c);
            }
            return sum;
        }
    }
    IntNode* getRoot() const { return root; }
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
    cnt = n;
    while(n--) {
        int u, w;
        cin >> u >> w;
        tree.setSpace(u, w);
    }
    while(m--) {
        int x;
        cin >> x;
        IntNode* nodeX = tree.findNode(x);
        cout << tree.getTotalSpace(nodeX) << endl;
    }
}