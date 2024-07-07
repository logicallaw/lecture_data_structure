#include <iostream>
using namespace std;
class Stack{
private:
    int* stack;
    int n;
public:
    Stack() : stack{ new int[10000]{} }, n{ -1 } {}
    ~Stack() { delete[] stack; }
    bool empty() const { return (n == -1); }
    void top() const {
        if(empty()) {
            cout << "-1\n";
        } else {
            cout << stack[n] << endl;
        }
    }
    void push(int x) {
        stack[++n] = x;
    }
};
int main(void) {
    int n;
    cin >> n;
    Stack stk;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "empty") {
            if(stk.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        else if (userInput == "top") {
            stk.top();
        } else if (userInput == "push") {
            int x;
            cin >> x;
            stk.push(x);
        }
    }
    return 0;
}