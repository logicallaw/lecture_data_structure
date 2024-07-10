#include <iostream>
using namespace std;
class BST;
class IntNode {
private:
    IntNode* par;
    int ele = -1;
    IntNode* leftC = NULL;
    IntNode* rightC = NULL;
    friend class BST;
};
class BST {
private:
    IntNode* root;
    int n;
    int height;
public:
    BST() : root { NULL }, n { 0 }, height { 0 } {}
    ~BST() {
        deleteNodes(root);
    }
    //동적메모리 해제(postOrder로 수행)
    void deleteNodes(IntNode* v){
        if(v == NULL){
            return;
        }
        if(v->leftC != NULL){
            deleteNodes(v->leftC);
        }
        if(v->rightC != NULL){
            deleteNodes(v->rightC);
        }
        delete v;
    }
    bool isEmpty() const { return n == 0; }
    IntNode* getRoot() const { return root; }
    //키가 동일한 노드를 찾아 리턴한다.
    //키가 동일한 노드가 없다면 다 NULL이 리턴된다.
    //입력된 key의 노드를 찾아 리턴하는 메서드
    IntNode* findNode(int k, IntNode* v){
        if(v != NULL){
            if(k < v->ele) {
                return findNode(k, v->leftC);
            } else if (k == v->ele){
                return v;
            } else {
                return findNode(k, v->rightC);
            }
        } else {
            return NULL;
        }
    }
    //insert를 위한 삽입할 위치의 부모 노드를 리턴하는 함수
    IntNode* search(int k, IntNode* v){
        if(v == NULL){
            return NULL;
        }
        if(k < v->ele){
            if(v->leftC != NULL) {
                return search(k, v->leftC);
            } else {
                return v;
            }
        } else {
            if(v->rightC != NULL){
                return search(k, v->rightC);
            } else {
                return v;
            }
        }
    }
    void insert(int x){
        //루트 노드를 설정해준다.
        if(isEmpty()){
            root = new IntNode;
            root->par = NULL;
            root->ele = x;
            n++;
        } else {
            IntNode* curNode = search(x, root);
            if(curNode != NULL) {
                //새로운 노드를 부모와 연결
                IntNode* newNode = new IntNode;
                newNode->par = curNode;
                newNode->ele = x;
                //새로운 노드를 부모의 자식으로 연결
                if(x < curNode->ele){
                    curNode->leftC = newNode;
                } else { // x >= curNode->ele
                    curNode->rightC = newNode;
                }
                n++;
            }
        }
    }
    void postOrder(IntNode* v, int cnt) {
        if (v->leftC != NULL) {
            postOrder(v->leftC, cnt + 1);
        }
        if (v->rightC != NULL) {
            postOrder(v->rightC, cnt + 1);
        }
        if (height < cnt) {
            height = cnt;
        }
    }
    void printHeight() {
        postOrder(root, 0);
        cout << height << endl;
    }
};
int main(void) {
    int t;
    cin >> t;
    while (t--) {
        BST b;
        int n;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            b.insert(x);
        }
        b.printHeight();
    }
}

/*
3
7
4 2 6 1 3 5 7
7
7 6 5 4 3 2 1
4
1 2 3 4
*/