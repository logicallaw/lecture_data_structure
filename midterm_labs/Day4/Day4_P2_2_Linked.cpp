#include <iostream>
#include <string>
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
    SLinkedList() : head {NULL}, tail {NULL} {}
    ~SLinkedList() {
        if (!empty()) {
            IntNode *curNode = head;
            while (curNode->next != tail) {
                IntNode *old = curNode;
                curNode = curNode->next;
                delete old;
            }
            delete curNode;
            delete tail;
        }
    }
    bool empty() const {return (head == NULL); }
    void push(int x) {
        IntNode* newNode = new IntNode;
        if(empty()){
            tail = newNode;
        }
        newNode->ele = x;
        newNode->next = head;
        head = newNode;
        n++;
    }
    int pop() {
        if(empty()){
            return 0;
        }
        IntNode* old = head;
        int result = old->ele;
        head = head->next;
        delete old;
        n--;
        if(empty()) {
            tail = NULL;
        }
        return result;
    }
};
int main(void){
    int n;
    cin >> n;
    while(n--){
        SLinkedList stk;
        string userInput;
        cin >> userInput;
        for(int i = 0; i < userInput.length(); i++){
            char temp = userInput[i];
            if(temp == '+' || temp == '-' || temp == '*'){
                if(temp == '+') {
                    int x, y;
                    y = stk.pop();
                    x = stk.pop();
                    int r = x + y;
                    stk.push(r);
                } else if (temp == '-'){
                    int x, y;
                    y = stk.pop();
                    x = stk.pop();
                    int r = x - y;
                    stk.push(r);
                } else {
                    int x, y;
                    y = stk.pop();
                    x = stk.pop();
                    int r = x * y;
                    stk.push(r);
                }
            } else {
                stk.push(temp - '0');
            }
        }
        cout << stk.pop() << endl;
    }
    return 0;
}