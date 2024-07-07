#include <iostream>
#include <string>
using namespace std;
class SLinkedList;
class IntNode{
public:
    int ele;
    IntNode* next;
    friend SLinkedList;
};

class SLinkedList{
private:
    IntNode* head;
    IntNode* tail;
public:
    SLinkedList() : head { NULL }, tail{ NULL }{}
    ~SLinkedList(){
        if(head != NULL){
            delete head;
        }
        if(tail != NULL){
            delete tail;
        }
    }
    void addFront(int x){
        IntNode* newNode = new IntNode;
        if(isEmpty()){
            tail = newNode;
        }
        newNode->ele = x;
        newNode->next = head;
        head = newNode;
    }
    void removeFront(){
        if(isEmpty()){ //0개면 리턴
            cout << -1 << endl;
            return;
        }
        //1개이면
        IntNode* tempNode = head;
        head = head->next;
        cout << tempNode->ele << endl;
        delete tempNode;
        if(isEmpty()){
            tail = NULL;
        }
    }
    void front() const {
        if(isEmpty()){
            cout << -1 << endl;
            return;
        }
        cout << head->ele << endl;
    }
    void empty() const {
        if(head == NULL){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    bool isEmpty() const { return (head == NULL) ;}
    void showList() const {
        if(isEmpty()){
            cout << -1 << endl;
            return;
        }
        IntNode* temp = head;
        while(temp->next != NULL){
            cout << temp->ele << " ";
            temp = temp->next;
        }
        cout << temp->ele << endl;
    }
    void addBack(int x){
        IntNode* newNode = new IntNode;
        newNode->ele = x;
        if(isEmpty()){
            head = tail = newNode;
            newNode->next = NULL;
            return;
        } else {
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
};
int main(void){
    int n;
    cin >> n;
    SLinkedList Slist;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "addFront") {
            int x;
            cin >> x;
            Slist.addFront(x);
        } else if (userInput == "removeFront") {
            Slist.removeFront();
        } else if (userInput == "front"){
            Slist.front();
        } else if (userInput == "empty"){
            Slist.empty();
        } else if (userInput == "showList"){
            Slist.showList();
        } else if (userInput == "addBack"){
            int x;
            cin >> x;
            Slist.addBack(x);
        }
    }
    return 0;
}