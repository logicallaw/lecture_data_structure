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
        nodes.push_back(root);
        this->n = 0;
        height = 0;
    }
    void insert(int x, int y) {
        IntNode* nodeX = findNode(x);
        IntNode* nodeY = new IntNode;
        if(nodeX == NULL){
//            cout << -1 << endl;
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
    bool isExternal(IntNode* node) const { return node->child.size() == 0; }
    void preOrder(IntNode* v, int cnt) {
        cout << v->ele << " ";
        for(int i{ 0 }; i < v->child.size(); i++){
            preOrder(v->child[i], cnt + 1);
        }
        if(v->child.size() == 0){
            if(this->height < cnt) {
                height = cnt;
            }
        }
    }
    int getHeight(IntNode* v){
        int height = 0;
        if(v!=NULL){
            height = 1 + max();
        }
    }
    void postOrder(IntNode* v) {
        for(int i{ 0 }; i < v->child.size(); i++){
            postOrder(v->child[i]);
        }
        cout << v->ele << " ";
    }
    IntNode* getRoot() const { return root; }
    int getHeight() {
        return height;
    }
};
int main(void) {
    int n;
    cin >> n;
    while(n--){
        int cnt;
        cin >> cnt;
        Tree tree;
        while(cnt--){
            int x, y;
            cin >> x >> y;
            tree.insert(x, y);
        }
        IntNode* treeRoot = tree.getRoot();
        tree.preOrder(treeRoot, 0);
        cout << endl;
        tree.postOrder(treeRoot);
        cout << endl;
        int height = tree.getHeight();
        cout << height << endl;
    }
    return 0;
}