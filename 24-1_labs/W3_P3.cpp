#include <iostream>
using namespace std;
class Stack;
class IntNode{
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
    Stack() : head { NULL }, tail{ NULL }, n{ 0 } {}
    ~Stack() {}
    bool empty() const { return (head == NULL); }
    void size() const { cout << n << endl; }
    int top() const {
        if(empty()) {
            cout << -1 << endl;
        } else {
            cout << head->ele << endl;
        }
    }
    void push(int x) {
        IntNode* newNode = new IntNode;
        if(empty()) {
            tail = newNode;
        }
        newNode->ele = x;
        newNode->next = head;
        head = newNode;
        n++;
    }
    void pop(int s) {
        if(s >= n) {
            if(empty()) {
                cout << -1 << endl;
                return;
            }
            IntNode* curNode = head;
            if(curNode == tail) {
                head = tail = NULL;
                cout << curNode->ele << endl;
                n--;
                delete curNode;
            } else {
                while(curNode->next != tail) {
                    IntNode* old = curNode;
                    cout << curNode->ele << " ";
                    curNode = curNode->next;
                    n--;
                    delete old;
                }
                IntNode* old = tail;
                cout << curNode->ele << " ";
                cout << tail->ele << endl;
                delete curNode;
                delete old;
                head = tail = NULL;
                n-=2;
            }
        } else {
            if(s == 1){
                IntNode* curNode = head;
                cout << curNode->ele << endl;
                head = tail = NULL;
                delete curNode;
                n--;
            } else if (s >= 2) {
                int cnt = s;
                IntNode* curNode = head;
                while(cnt--){
                    IntNode* old = curNode;
                    cout << curNode->ele << " ";
                    curNode = curNode->next;
                    head = curNode;
                    delete old;
                    n--;
                }
                cout << endl;
            }
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    Stack stk;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "size"){
            stk.size();
        } else if (userInput == "empty") {
            if(stk.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "top") {
            stk.top();
        } else if (userInput == "push") {
            int x;
            cin >> x;
            stk.push(x);
        } else if (userInput == "pop"){
            int s;
            cin >> s;
            stk.pop(s);
        }
    }
    return 0;
}