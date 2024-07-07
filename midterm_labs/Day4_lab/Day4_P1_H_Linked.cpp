#include <iostream>
using namespace std;
class IntNode;
class SLinkedList;
class Stack;

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
    SLinkedList()  { head = tail = NULL; }
    bool empty() const { return (head == NULL); }
    int front() const {
        if(head != NULL) return head->ele;
        else return -1;
    }
    void addFront(int e) { //push
        IntNode* newNode = new IntNode;
        if(empty()){
            tail = newNode;
        }
        newNode->ele = e;
        newNode->next = head;
        head = newNode;
    }
    int removeFront() { //pop
        if(empty()){
            return -1;
        } else {
            int returnElement = head->ele;
            IntNode* tempNode = head;
            head = head -> next;
            delete tempNode;
            return returnElement;
        }
    }
    int size() {
        if(empty()) {
            return 0;
        } else {
            int n = 1;
            IntNode* tempNode = head;
            while (tempNode->next != NULL) {
                tempNode = tempNode->next;
                n++;
            }
            return n ;
        }
    }
};

class Stack{
public:
    SLinkedList* stk;
    Stack() {
        stk = new SLinkedList;
    }
    ~Stack() { delete stk; }
    void empty() const {
        if(stk->empty()){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    void top() {
        int temp = stk->front();
        if(temp == -1){
            cout << -1 << endl;
        } else {
            cout << temp << endl;
        }
    }
    void push(int x) {
        stk->addFront(x);
    }
    void pop() {
        int temp = stk->removeFront();
        if(temp == -1){
            cout << -1 << endl;
        } else {
            cout << temp << endl;
        }
    }
    void size() {
        int temp = stk->size();
        cout << temp << endl;
    }
};
int main(void){
    Stack s;
    int n;
    cin >> n;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "empty") {
            s.empty();
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