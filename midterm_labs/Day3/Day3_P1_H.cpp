#include <iostream>
#include <string>
using namespace std;
class SLinkedList;
class IntNode{
private:
    int ele;
    IntNode* next;
    friend class SLinkedList;
};
class SLinkedList{
private:
    IntNode* head;
    IntNode* tail;
public:
    SLinkedList() : head { NULL }, tail{ NULL } {}
    bool empty() const { return (head == NULL); }
    void addFront(int x) {
        IntNode* newNode = new IntNode;
        if(empty()) {
            tail = newNode;
        }
        newNode->ele = x;
        newNode->next = head;
        head = newNode;
    }
    void front() const {
        if(empty()){
            cout << -1 << endl;
        } else {
            cout << head->ele << endl;
        }
    }
    void removeFront() {
        if(empty()) {
            cout << -1 << endl;
            return;
        }
        IntNode* old = head;
        head = head->next;
        int result = old->ele;
        delete old;
        cout << result << endl;
        if(empty()){
            tail = NULL;
        }
    }
    void showList() const {
        if(empty()){
            cout << -1 << endl;
            return;
        }
        IntNode* curNode = head;
        if(curNode == tail) {
            cout << curNode->ele << endl;
        } else {
            while(curNode->next != tail) {
                cout << curNode->ele << " ";
                curNode = curNode->next;
            }
            cout << curNode->ele << " " << tail->ele << endl;
        }
    }
    void addBack(int x) {
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        newNode->next = NULL;
        if(empty()) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void deleteElement(int d){
        int cnt = d;
        IntNode* curNode = head;
        while(cnt--){
            curNode = curNode->next;
        }
        // 1 2 3 4 5 6
        // h     i   t

        if(curNode == head){
            IntNode* old = head;
            head = head->next;
            tail->next = head;
            delete old;
        } else if (curNode == tail) {
            IntNode* preNode = head;
            while(preNode->next != tail) {
                preNode = preNode->next;
            }
            tail = preNode;
            delete preNode->next;
            tail->next = head;
        } else {
            IntNode* preNode = head;
            while(preNode->next != curNode) {
                preNode = preNode->next;
            }
            preNode->next = curNode->next;
            delete curNode;
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    while(n--){
        SLinkedList s;
        int cnt = 10;
        while(cnt--){
            int x;
            cin >> x;
            s.addBack(x);
        }
        cnt = 3;
        while(cnt--){
            string userInput;
            int d;
            cin >> userInput >> d;
            s.deleteElement(d);
        }
        s.showList();
    }
    return 0;
}