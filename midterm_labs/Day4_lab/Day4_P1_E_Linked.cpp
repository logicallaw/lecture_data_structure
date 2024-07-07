#include <iostream>
#include <string>
using namespace std;
class Stack;
class IntNode{
public:
    int ele;
    IntNode* next;
    friend Stack;
};

class SlinkedList{
public:
    IntNode* head;
    IntNode* tail;
    SlinkedList(){
        head = tail = NULL;
    }
    bool empty() const { return (head == NULL); }
    int front() {
        return head->ele;
    }
    void addFront(int e){
        IntNode* newNode = new IntNode;
        if(empty()){
            head = tail = newNode;
        }
        newNode->ele = e;
        newNode->next = NULL;
        head = newNode;
    }
    int removeFront() {
        IntNode* tempNode = head;
        head = head->next;
        int result = tempNode->ele;
        delete tempNode;
        if(empty()){
            tail = NULL;
        }
        return result;
    }
};
class linkedStack{
private:
    int n;
    SlinkedList* stack;
public:
    linkedStack() : n{ -1 }, stack{ new SlinkedList } {}
    bool empty() const {
        return stack->empty();
    }
    void top() const {
        if(stack->empty()){
            cout << -1 << endl;
        } else {
            cout << stack->front() << endl;
        }
    }
    void push(int x){
        stack->addFront(x);
    }
};
int main(void){
    int n;
    cin >> n;
    linkedStack stk;
    while(n--) {
        string userInput;
        cin >> userInput;
        if (userInput == "empty") {
            if(stk.empty()){
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        else if (userInput == "top") {
            stk.top();
        }
        else if (userInput == "push") {
            int x;
            cin >> x;
            stk.push(x);
        }
    }
    return 0;
}