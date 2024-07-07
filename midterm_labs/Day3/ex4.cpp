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
            int result = tail->next->ele;
            delete tail->next;
            tail->next = NULL;
            cout << result << endl;
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    SLinkedList s;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "addFront") {
            int x;
            cin >> x;
            s.addFront(x);
        } else if (userInput == "removeFront") {
            s.removeFront();
        } else if (userInput == "front") {
            s.front();
        } else if (userInput == "empty") {
            if(s.empty()){
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "showList"){
            s.showList();
        } else if (userInput == "addBack"){
            int x;
            cin >> x;
            s.addBack(x);
        } else if (userInput == "removeBack"){
            s.removeBack();
        }
    }
}