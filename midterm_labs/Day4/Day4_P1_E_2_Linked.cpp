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
    SLinkedList() : head {NULL}, tail {NULL} {}
    ~SLinkedList() {
        if (!empty()) {
            IntNode *curNode = head;
            while (curNode->next != tail) {
                IntNode *old = curNode;
                curNode = curNode->next;
                delete old;
            }
            delete curNode;
            delete tail;
        }
    }
    bool empty() const {return (head == NULL); }
    void top() const {
        if(empty()){
            cout << -1 << endl;
        } else {
            cout << head->ele << endl;
        }
    }
    void push(int x) {
        IntNode* newNode = new IntNode;
        if(empty()){
            tail = newNode;
        }
        newNode->ele = x;
        newNode->next = head;
        head = newNode;
    }
};
int main(void) {
    int n;
    cin >> n;
    SLinkedList s;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "empty"){
            if(s.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "top") {
            s.top();
        } else if (userInput == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
    }
    return 0;
}