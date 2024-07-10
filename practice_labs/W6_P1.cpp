#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Tree;
class IntNode {
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
    bool isExternal(IntNode* v) const { return v->child.size() == 0; }
    IntNode* findNode(int e) {
        for(IntNode* node : nodes){
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
            cout << -1 << endl;
            return;
        }
        nodeY = new IntNode;
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
    }
    void deleteNode(int x){
        IntNode* nodeX = findNode(x);
        //nodeX가 트리에 존재하지 않으면
        if(nodeX == NULL) {
            cout << -1 << endl;
            return;
        }
        for(IntNode* c : nodeX->child) {
            c->par = nodeX->par;
            nodeX->par->child.push_back(c);
        }
        for(int i{ 0 }; i < nodeX->par->child.size(); i++) {
            if(nodeX->par->child[i] == nodeX) {
                nodeX->par->child.erase(nodeX->par->child.begin() + i);
                break;
            }
        }
        for(int i{ 0 }; i < nodes.size(); i++) {
            if(nodes[i] == nodeX) {
                nodes.erase(nodes.begin() + i);
                break;
            }
        }
    }
    void child(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL || nodeX->child.size() == 0){
            cout << -1 << endl;
            return;
        }
        for(IntNode* c : nodeX->child) {
            cout << c->ele << " ";
        }
        cout << endl;
    }
    void parent(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL) {
            cout << -1 << endl;
        } else {
            cout << nodeX->par->ele << endl;
        }
    }
    void min_maxChild(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL || nodeX->child.size() == 0) {
            cout << -1 << endl;
            return;
        }
        if(nodeX->child.size() == 1) {
            cout << nodeX->child[0]->ele << endl;
        } else {
            int min = nodeX->child[0]->ele;
            int max = min;
            for(IntNode* c : nodeX->child) {
                min = (min > c->ele) ? c->ele : min;
                max = (max < c->ele) ? c->ele : max;
            }
            cout << min + max << endl;
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    Tree tree;
    while(n--) {
        string userInput;
        cin >> userInput;
        if (userInput == "insert") {
            int x, y;
            cin >> x >> y;
            tree.insert(x, y);
        } else if (userInput == "delete") {
            int x;
            cin >> x;
            tree.deleteNode(x);
        } else if (userInput == "child") {
            int x;
            cin >> x;
            tree.child(x);
        } else if (userInput == "parent") {
            int x;
            cin >> x;
            tree.parent(x);
        } else if (userInput == "child") {
            int x;
            cin >> x;
            tree.child(x);
        } else if (userInput == "min_maxChild") {
            int x;
            cin >> x;
            tree.min_maxChild(x);
        }
    }
    return 0;
}