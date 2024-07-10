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
    int n;
    int height;
public:
    Tree() {
        root = new IntNode;
        root->par = NULL;
        root->ele = 1;
        n = 1;
        height = 0;
        nodes.push_back(root);
    }
    ~Tree() {
        for(int i{ 0 }; i < nodes.size(); i++) {
            delete nodes[i];
        }
    }
    bool isEmpty() const { return n == 0; }
    IntNode* findNode(int e) {
        for(IntNode* node : nodes) {
            if(node->ele == e) {
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
        n++;
    }
    IntNode* getRoot() const { return root; }
    void preOrder(IntNode* v) {
        cout << v->ele << " ";
        for(IntNode* c : v->child){
            preOrder(c);
        }
    }
    void postOrder(IntNode* v, int d) {
        for(IntNode* c : v->child) {
            postOrder(c, d + 1);
        }
        cout << v->ele << " ";
        if(height < d) {
            height = d;
        }
    }
    void printHeight() const {
        cout << height << endl;
    }
};
int main(void) {
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        Tree t;
        while(m--) {
            int x, y;
            cin >> x >> y;
            t.insert(x, y);
        }
        IntNode* rootNode = t.getRoot();
        t.preOrder(rootNode);
        cout << endl;
        t.postOrder(rootNode, 0);
        cout << endl;
        t.printHeight();
    }
}