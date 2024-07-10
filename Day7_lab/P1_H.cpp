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
            cout << -1 << endl;
            return;
        }
        nodeY = new IntNode;
        nodeY->par = nodeX;
        nodeY->ele = y;
        nodeX->child.push_back(nodeY);
        nodes.push_back(nodeY);
        n++;
    }
    void printChild(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL) {
            cout << -1 << endl;
        } else if (nodeX->child.size() == 0) {
            cout << 0 << endl;
        } else {
            for(IntNode* c : nodeX->child){
                cout << c->ele << " ";
            }
            cout << endl;
        }
    }
    void printDepth(int x) {
        IntNode* nodeX = findNode(x);
        if(nodeX == NULL) {
            cout << -1 << endl;
            return;
        }
        int cnt = 0;
        while(nodeX->par != NULL) {
            cnt++;
            nodeX = nodeX->par;
        }
        cout << cnt << endl;
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
    Tree t;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "insert") {
            int x, y;
            cin >> x >> y;
            t.insert(x,y);
        } else if (userInput == "printChild") {
            int x;
            cin >> x;
            t.printChild(x);
        } else if (userInput == "printDepth") {
            int x;
            cin >> x;
            t.printDepth(x);
        }
    }
}