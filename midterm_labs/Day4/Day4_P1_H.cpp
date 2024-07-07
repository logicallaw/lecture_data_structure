#include <iostream>
using namespace std;
class Stack;
class IntNode {
private:
    int ele;
    IntNode* next;
    friend class Stack;
};
class Stack{
private:
    IntNode* head;
    IntNode* tail;
    int n;
public:
    Stack() : head { NULL }, tail { NULL }, n{ 0 } {}
    bool empty() const { return (head == NULL); }
    void push(int x){ //addBack
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        newNode->next = NULL;
        if(empty()){
            head = tail = newNode;
            n++;
            return;
        }
        n++;
        tail->next = newNode;
        tail = newNode;
    }
    void top() const {
        if(empty()){
            cout << -1 << endl;
        } else {
            cout << tail->ele << endl;
        }
    }
    // 1 2 3 4 5
    void pop() { //removeBack
        if(empty()){
            cout << -1 << endl;
            return;
        }
        IntNode* curNode = head;
        if(curNode == tail) {
            head = tail = NULL;
            cout << curNode->ele << endl;
            delete curNode;
        } else {
            while(curNode->next != tail) {
                curNode = curNode->next;
            }
            // 1 2 3 4 5
            // h     t
            IntNode* old = tail;
            cout << tail->ele << endl;
            tail = curNode;
            curNode->next = NULL;
            delete old;
        }
        n = n - 1;
    }
    void size() const { cout << n << endl; }
};
int main(void) {
    int n;
    cin >> n;
    Stack s;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "empty") {
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
        } else if (userInput == "pop") {
            s.pop();
        } else if (userInput == "size") {
            s.size();
        }
    }
    return 0;
}