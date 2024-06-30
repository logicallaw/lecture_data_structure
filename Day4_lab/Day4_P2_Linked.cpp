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
    int pop() {
        return stk->removeFront();
    }
    void size() {
        int temp = stk->size();
        cout << temp << endl;
    }
};
int main(void){
    int n;
    cin >> n;
    while(n--){
        Stack stk;
        string userInput;
        cin >> userInput;
        for(int i = 0; i < userInput.length(); i++){
            char temp = userInput[i];
            if(temp == '+' || temp == '-' || temp == '*'){
                if (temp == '+'){
                    int y = stk.pop();
                    int x = stk.pop();
                    int result = x + y;
                    stk.push(result);
                } else if (temp == '-') {
                    int y = stk.pop();
                    int x = stk.pop();
                    int result = x - y;
                    stk.push(result);
                } else {
                    int y = stk.pop();
                    int x = stk.pop();
                    int result = x * y;
                    stk.push(result);
                }
            } else {
                stk.push(temp - '0');
            }
        }
        cout << stk.pop() << endl;
    }
}