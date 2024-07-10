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
public:
    BST() : root { NULL }, n{ 0 } {}
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
    int getDegree(IntNode* v) {
        if (v->leftC != NULL && v->rightC != NULL) {
            return 2;
        }
        else if (v->leftC != NULL || v->rightC != NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int getDepth(IntNode* v) {
        int d = 0;
        while (v->par != NULL) {
            d++;
            v = v->par;
        }
        return d;
    }
//    void preOrder(IntNode* v) {
//        cout << v->ele << " ";
//        if (v->leftC != NULL) {
//            preOrder(v->leftC);
//        }
//        if (v->rightC != NULL) {
//            preOrder(v->rightC);
//        }
//    }
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
        int m;
        cin >> m;
        while (m--) { //내가 탐색할 노드
            int x;
            cin >> x;
            IntNode *nodeX = b.findNode(x, b.getRoot());
            if (nodeX != NULL) {
                cout << b.getDegree(nodeX) << " " << b.getDepth(nodeX) << endl;
            } else { //내가 찾고자하는 노드가 없을 때
                cout << 0 << endl;
            }
        }
    }
}

/*
2
7
15 10 5 12 11 14 17
3
12 10 20
6
92 80 24 18 38 87
6
24 87 92 18 80 38
*/