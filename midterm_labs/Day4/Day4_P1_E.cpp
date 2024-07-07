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
public:
    Stack() : head { NULL }, tail { NULL } {}
    bool empty() const { return (head == NULL); }
    void push(int x){ //addBack
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        newNode->next = NULL;
        if(empty()){
            head = tail = newNode;
            return;
        }
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
        }
    }
    return 0;
}