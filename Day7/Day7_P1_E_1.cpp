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
        root->par = nullptr;
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
        IntNode* nodeY = new IntNode;
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
    }
    void printChild(int x) {
        IntNode* nodeX = findNode(x);
        for(IntNode* c : nodeX->child){
            cout << c->ele << " ";
        }
        cout << endl;
    }
};
int main(void) {
    int n;
    cin >> n;
    Tree tree;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "insert") {
            int x, y;
            cin >> x >> y;
            tree.insert(x, y);
        } else if (userInput == "printChild") {
            int x;
            cin >> x;
            tree.printChild(x);
        }
    }
    return 0;
}