#include <iostream>
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
    int n = 0;
public:
    SLinkedList() : head{NULL}, tail{NULL}{}
    bool empty() const {return head == NULL;}
    void size() const { cout << n << endl; }
    void enqueue(int x) { //addBack
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        newNode->next = NULL;
        if(empty()){
            head = tail = newNode;
            n++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        n++;
    }
    void dequeue() { //removeFront
        if(empty()){
            cout << "Empty" << endl;
            return;
        }
        IntNode* old = head;
        int result = old->ele;
        head = head->next;
        delete old;
        if(empty()){
            tail = NULL;
        }
        n--;
        cout << result << endl;
    }
    void rear() const {
        if(empty()){
            cout << "Empty" << endl;
        } else {
            cout << tail->ele << endl;
        }
    }
    void frontNsum(int num){
        if(empty()){
            cout << "Empty" << endl;
        } else {
            if(num > n){
                cout << "error" << endl;
            } else {
                int sum = 0;
                IntNode* curNode = head;
                while(num--){
                    sum += curNode->ele;
                    curNode = curNode->next;
                }
                cout << sum << endl;
            }
        }
    }
};
int main(void){
    int t;
    cin >> t;
    SLinkedList s;
    while(t--){
        string userInput;
        cin >> userInput;
        if(userInput == "size") {
            s.size();
        } else if (userInput == "isEmpty"){
            if(s.empty()){
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
        } else if (userInput == "frontNsum") {
            int num;
            cin >> num;
            s.frontNsum(num);
        } else if (userInput == "rear") {
            s.rear();
        } else if (userInput =="enqueue"){
            int value;
            cin >> value;
            s.enqueue(value);
        } else if (userInput == "dequeue"){
            s.dequeue();
        }
    }
    return 0;
}