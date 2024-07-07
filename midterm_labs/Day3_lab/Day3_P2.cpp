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
    bool isEmpty() const { return (head == NULL) ;}
    void deleteElement(int i){
        int cnt = i;
        IntNode* tempNode = head;
        while(cnt--){
            tempNode = tempNode->next;
        }
        if(tempNode == head){
            head = tempNode->next;
            tail->next = head;
            delete tempNode;
            return;
        }
        else if(tempNode == tail){
            IntNode* preNode = head;
            while(preNode->next != tail){
                preNode = preNode->next;
            }
            tail = preNode;
            tail->next = head;
            delete tempNode;
            return;
        }
        else {
            IntNode* preNode = head;
            while(preNode->next != tempNode){
                preNode = preNode->next;
            }
            preNode->next = tempNode->next;
            delete tempNode;
            return;
        }
    }
    void showList() const {
        if(isEmpty()){
            cout << -1 << endl;
            return;
        }
        IntNode* temp = head;
        while(temp->next != tail){
            cout << temp->ele << " ";
            temp = temp->next;
        }
        cout << temp->ele << " ";
        temp = temp->next;
        cout << temp->ele << endl;

    }
    void setCircle(){
        tail->next = head;
    }

};
int main(void){
    int n;
    cin >> n;
    while(n--){
        SLinkedList Slist;
        int count = 10;
        while(count--) {
            //입력
            int inputEle;
            cin >> inputEle;
            Slist.addBack(inputEle);
        }
        Slist.setCircle();

        count = 3;
        while(count--){
            string userInput;
            int i;
            cin >> userInput >> i;
            Slist.deleteElement(i);
        }
        Slist.showList();
    }
}