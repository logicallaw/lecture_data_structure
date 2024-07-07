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
    SLinkedList() : head{ NULL }, tail{ NULL } {}
    ~SLinkedList() {
        if(!empty()) {
            IntNode* curNode = head;
            while(curNode->next != tail){
                IntNode* old = curNode;
                curNode = curNode->next;
                delete old;
            }
            IntNode* old = curNode;
            curNode = curNode->next;
            delete old;
            delete curNode;
        }
    }
    bool empty() const { return (head == NULL); }
    void addFront(int x) {
        IntNode* newNode = new IntNode;
        if(empty()){
            tail = newNode;
        }
        newNode->ele = x;
        newNode->next = head;
        head = newNode;
    }
    void removeFront() {
        if(empty()){
            cout << "-1\n";
            return;
        }
        IntNode* old = head;
        head = head->next;
        int oldV = old->ele;
        delete old;
        if(empty()) {
            tail = NULL;
        }
        cout << oldV << endl;
    }
    void front() const {
        if(empty()){
            cout << "-1\n";
        } else {
            cout << head->ele << endl;
        }
    }
    void showList() const {
        if(empty()){
            cout << "-1\n";
            return;
        }
        IntNode* curNode = head;
        while(curNode->next != tail){
            cout << curNode->ele << " ";
            curNode = curNode->next;
        }
        cout << curNode->ele << " " << curNode->next->ele << endl;
    }
    void addBack(int x){
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        newNode->next = NULL;
        if(empty()){
            head = tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;
    }
    void removeBack() {
        if(empty()) {
            cout << "-1\n";
            return;
        }
        IntNode* curNode = head;
        if(curNode == tail){
            head = tail = NULL;
            delete curNode;
        } else {
            while(curNode->next != tail){
                curNode = curNode->next;
            }
            tail = curNode;
            delete tail->next;
            tail->next = head;
        }
    }
    void deleteElement(int d) {
        IntNode* curNode = head;
        int cnt = d;
        while(cnt--){
            curNode = curNode->next;
        }
        if(curNode == head) {
            head = head->next;
            tail->next = head;
            delete curNode;
        } else if (curNode == tail) {
            IntNode* tempNode = head;
            while(tempNode->next != tail){
                tempNode = tempNode->next;
            }
            tail = tempNode;
            delete tail->next;
            tail->next = head;
        } else {
            IntNode* tempNode = head;
            while(tempNode->next != curNode){
                tempNode = tempNode->next;
            }
            tempNode->next = curNode->next;
            delete curNode;
        }
    }
};
int main(void){
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
}