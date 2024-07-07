#include <iostream>
#include <string>
using namespace std;
class Stack{
private:
    int n;
    int* stack;
public:
    Stack() : stack{new int[10000] }, n{ -1 } {}
    ~Stack() { delete[] stack; }
    bool empty() const { return (n== -1); }
    void top() const {
        if(empty()) {
            cout << -1 << endl;
            return;
        } else {
            cout << stack[n] << endl;
        }
    }
    void push(int x) {
        stack[++n] = x;
    }
    void pop() {
        if(empty()){
            cout << -1 << endl;
        } else {
            n--;
            cout << stack[n + 1] << endl;
        }
    }
    void size() const {
        cout << n + 1 << endl;
    }
};
int main(void){
    int n;
    cin >> n;
    Stack stk;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "empty"){
            if(stk.empty()){
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else if (userInput == "top"){
            stk.top();
        }
        else if (userInput == "push"){
            int x;
            cin >> x;
            stk.push(x);
        }
        else if (userInput == "pop"){
            stk.pop();
        }
        else if (userInput == "size"){
            stk.size();
        }
    }
    return 0;
}