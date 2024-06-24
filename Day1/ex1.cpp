#include <iostream>
using namespace std;
typedef string Elem;
class StringLinkedList;
class StringNode{
private:
    Elem elem;
    StringNode* next;
    friend StringLinkedList;
};
class StringLinkedList{
private:
    StringNode* head;
    StringNode* tail;
public:
    StringLinkedList() : head { NULL }, tail{ NULL } {}
    ~StringLinkedList() { head = NULL; tail = NULL; }
    bool empty() const{ return (head == NULL); }
    Elem front() const { return head->elem; }
    void addFront(const Elem& e) {
        StringNode* v = new StringNode;
        if(empty()){
            tail = v;
        }
        v->elem = e;
        v->next = head;
        head = v;
    }
    void removeFront() {
        if(empty()) return;
        StringNode* old = head;
        head = old->next;
        delete old;
        if(empty()){
            tail = NULL;
        }
    }
    void addBack(const Elem& e){
        StringNode* v = new StringNode;
        v->elem = e;
        v->next = NULL;
        if(empty()){
            head = tail = v;
        } else {
            tail->next = v;
            tail = v;
        }
    }
    void removeBack(){
        if(empty()) {
            return;
        }
        StringNode* current = head;
        if(current == tail){
            head = tail = NULL;
        } else {
            while(current->next != tail){
                current = current -> next;
            }
            tail = current;
            delete tail->next;
            tail -> next = NULL;
        }
    }
};
