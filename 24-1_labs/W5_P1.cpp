#include <iostream>
#include <string>
using namespace std;
class DLinkedList;
class IntNode{
private:
    IntNode* prev;
    int ele;
    IntNode* next;
    friend class DLinkedList;
};
class DLinkedList {
private:
    IntNode* header;
    IntNode* trailer;
    int n;
public:
    DLinkedList() {
        header = new IntNode;
        header->prev = NULL;
        header->ele = -1;
        header->next = NULL;
        trailer = new IntNode;
        trailer->prev = NULL;
        trailer->ele = -1;
        trailer->next = NULL;
        n = 0;
    }
    bool empty() const { return n == 0; }
    int size() const { return n; }
    void insert(int i, int x) {
        if(i < 0 || i > size()) { //0 -1
            cout << "out_of_range" << endl;
            return;
        }
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        if(empty()){ //0개 일 때, header와 trailer를 newNode를 가리키도록 Update한다.
            header->next = newNode; newNode->prev = header;
            newNode->next = trailer; trailer->prev = newNode;
            n++;
        } else { //1개 이상일 때, i번째 노드를 찾고, 전 노드와 새노드, i번째 노드를 이어준다.
            IntNode* curNode = header->next;
            int cnt = i;
            while(cnt--) {
                curNode = curNode->next;
            }
            IntNode* u = curNode->prev;
            u->next = newNode; newNode->prev = u;
            newNode->next = curNode; curNode->prev = newNode;
            n++;
        }
    }
    void erase(int i) {
        if(i < 0 || i > (size() - 1)) {
            cout << "out_of_range" << endl;
            return;
        }
        if(size() == 1) { //1개일 때, header와 trailer를 모두 NULL을 가리키도록 한다.
            IntNode* old = header->next;
            header->next = NULL;
            trailer->prev = NULL;
            delete old;
            n--;
        } else { //2개 이상일 때, i번째 노드를 찾고 전과 후를 이어준다.
            IntNode* curNode = header->next;
            int cnt = i;
            while(cnt--){
                curNode = curNode->next;
            }
            IntNode* u = curNode->prev;
            IntNode* w = curNode->next;
            u->next = w; w->prev = u;
            delete curNode;
            n--;
        }
    }
    void find(int x) const { //자연수 처음으로 x인 노드의 인덱스 출력
        if(empty()) { //0개일때
            cout << "not_found" << endl;
            return;
        }
        //1개 이상일때
        IntNode* curNode = header->next;
        int idx = 0;
        bool isFound = false;
        while(curNode->next != trailer) {
            if(curNode->ele == x) {
                isFound = true;
                break;
            } else {
                idx++;
                curNode = curNode->next;
            }
        }
        if(!isFound){
            if(curNode->ele == x) { //마지막 노드 비교
                cout << idx << endl;
            } else {
                cout << "not_found" << endl;
            }
        } else {
            cout << idx << endl;
        }
    }
    void print(int m) const {
        if(empty()){
            cout << "empty" << endl;
            return;
        } else {
            if(m == 0) { //순방향
                IntNode* curNode = header->next;
                while(curNode->next != trailer) {
                    cout << curNode->ele << " ";
                    curNode = curNode->next;
                }
                cout << curNode->ele << endl;
            } else { //역방향
                IntNode* curNode = trailer->prev;
                while(curNode->prev != header) {
                    cout << curNode->ele << " ";
                    curNode = curNode->prev;
                }
                cout << curNode->ele << endl;
            }
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    DLinkedList d;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "insert") {
            int i, x;
            cin >> i >> x;
            d.insert(i, x);
        } else if (userInput == "erase") {
            int i;
            cin >> i;
            d.erase(i);
        } else if (userInput == "empty") {
            cout << ((d.empty()) ? "true" : "false") << endl;
        } else if (userInput == "find") {
            int x;
            cin >> x;
            d.find(x);
        } else if (userInput == "print") {
            int m;
            cin >> m;
            d.print(m);
        }
    }
    return 0;
}