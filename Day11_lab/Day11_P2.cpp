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
    //오른쪽 child의 노드를 받아 왼쪽 leaf 끝까지 탐색해 리턴한다.
    IntNode* successor(IntNode* v){
        IntNode* curNode = v;
        while(curNode->leftC != NULL) {
            curNode = curNode->leftC;
        }
        return curNode;
    }
    void deleteNode(int x){
        IntNode* delNode = findNode(x, root); //삭제할 노드 탐색
        if(delNode == NULL) return; //삭제할 노드가 없다면 NULL 리턴
        IntNode* parNode = delNode->par;
        IntNode* childNode;
        if(delNode->leftC == NULL && delNode->rightC == NULL) { //자식이 모두 NULL인 경우
            childNode = NULL;
        } else if (delNode->leftC == NULL && delNode->rightC != NULL) { //오른쪽 자식만 존재하는 경우
            childNode = delNode->rightC;
        } else if (delNode->leftC != NULL && delNode->rightC == NULL) { //왼쪽 자식만 존재하는 경우
            childNode = delNode->leftC;
        } else { //자식이 둘다 존재하는 경우
            childNode = successor(delNode->rightC); //SUCCESSOR 탐색
            delNode->ele = childNode->ele; //덮어쓰기
            delNode = childNode; //SUCCESSOR를 삭제할 노드로 변경
            parNode = delNode->par; //SUCCESSOR의 부모로 수정
            childNode = delNode->rightC;
        }
        if(parNode == NULL){ //부모가 NULL이면 자식이 부모가 된다.
            root = childNode;
            if(root != NULL) { //자식의 부모 연결
                root->par = NULL;
            }
        } else if (delNode == parNode->leftC){
            parNode->leftC = childNode; //부모의 자식 연결
            if(childNode != NULL) { //자식의 부모 연결
                childNode->par = parNode;
            }
        } else {
            parNode->rightC = childNode; //부모의 자식 연결
            if(childNode != NULL){ //자식의 부모 연결
                childNode->par = parNode;
            }
        }
        delete delNode;
    }
    void preOrder(IntNode* v) {
        cout << v->ele << " ";
        if (v->leftC) {
            preOrder(v->leftC);
        }
        if (v->rightC) {
            preOrder(v->rightC);
        }
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
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            b.deleteNode(x);
        }
        if (b.isEmpty()) {
            cout << 0 << endl;
        }
        else {
            b.preOrder(b.getRoot());
            cout << endl;
        }
    }
}

/*
2
7
18 7 26 3 12 22 30
3
18 22 12
6
92 80 24 18 38 87
3
80 24 18
*/