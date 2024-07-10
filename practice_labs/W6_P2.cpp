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
    IntNode* findNode(int e) {
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
            cout << -1 << endl;
            return;
        }
        nodeY = new IntNode;
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
    }
    int depth(IntNode* v, int d) {
        if(isRoot(v)) {
            return d;
        } else {
            return depth(v->par, d + 1);
        }
    }
};
int main(void) {
    int n, m;
    cin >> n >> m;
    Tree tree;
    while(n--) {
        int x, y;
        cin >> x >> y;
        tree.insert(x, y);
    }
    while(m--) {
        int x, y;
        cin >> x >> y;
        IntNode* nodeX = tree.findNode(x);
        IntNode* nodeY = tree.findNode(y);
        if(nodeX == NULL || nodeY == NULL) {
            cout << "error" << endl;
            continue;
        } else {
            int d1 = tree.depth(nodeX, 0);
            int d2 = tree.depth(nodeY, 0);
            int result = (d1 >= d2) ? d1 - d2 : d2 - d1;
            cout << d1 << " " << d2 << " " << result << endl;
        }
    }
    return 0;
}