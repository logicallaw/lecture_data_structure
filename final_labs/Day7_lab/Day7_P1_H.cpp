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
public:
    Tree() {
        root = new IntNode;
        root->par = NULL;
        root->ele = 1;
        nodes.push_back(root);
        this->n = 0;
    }
    void insert(int x, int y) {
        IntNode* nodeX = findNode(x);
        IntNode* nodeY = new IntNode;
        if(nodeX == NULL){
            cout << -1 << endl;
            return;
        }
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
    }
    void printChild(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL){
            cout << -1 << endl;
            return;
        }
        if(nodeX->child.size() == 0){
            cout << 0 << endl;
            return;
        }
        for(IntNode* child : nodeX->child){
            cout << child->ele << " ";
        }
        cout << endl;
    }
    IntNode* findNode(int x){
        for(IntNode* node : nodes){
            if(node->ele == x){
                return node;
            }
        }
        return NULL;
    }
    void printDepth(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL){
            cout << -1 << endl;
        } else {
            int cnt = 0;
            while(nodeX->par != NULL){
                cnt++;
                nodeX = nodeX->par;
            }
            cout << cnt << endl;
        }
    }

};
int main(void) {
    int n;
    cin >> n;
    Tree tree;
    while(n--){
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
        } else if (userInput == "printDepth"){
            int x;
            cin >> x;
            tree.printDepth(x);
        }
    }
    return 0;
}