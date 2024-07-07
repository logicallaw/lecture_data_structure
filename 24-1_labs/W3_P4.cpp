#include <iostream>
using namespace std;
class Stack{
private:
    char* stack;
    int currentIndex;
    int idxMax = 0;
public:
    Stack() : stack{ new char[100] }, currentIndex{ 0 } {}
    ~Stack() { delete[] stack; }
    bool empty() const { return (currentIndex == 0); }
    void push(char c) {
        stack[currentIndex++] = c;
        if(idxMax < currentIndex) {
            idxMax = currentIndex;
        }
    }
    char pop() {
        return stack[--currentIndex];
    }
    char top() {
        return stack[currentIndex - 1];
    }
    int getMax() {
        return idxMax;
    }
};
int main(void) {
    int n;
    cin >> n;
    while(n--){
        Stack stk;
        string userInput;
        cin >> userInput;
        for(size_t i{ 0 }; i < userInput.length(); i++) {
            char c = userInput[i];
            if(c >= '1' && c <= '9') {
                cout << c;
            } else if (c == '*') {
                while(!stk.empty() && (stk.top() == '*')) {
                    cout << stk.pop();
                }
                stk.push(c);
            } else if (c == '+' || c == '-') {
                while(!stk.empty()) {
                    cout << stk.pop();
                }
                stk.push(c);
            }
        }
        while(!stk.empty()){
            cout << stk.pop();
        }
        cout << " " << stk.getMax() << endl;
    }
}