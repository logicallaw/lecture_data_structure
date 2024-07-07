#include <iostream>
#include <string>
using namespace std;
class Stack{
private:
    int* stack;
    int n;
public:
    Stack() : stack{ new int[10000] }, n{ -1 } {}
    ~Stack() { delete[] stack; }
    bool empty() const { return (n == -1); }
    void push(int x) {
        stack[++n] = x;
    }
    int pop() {
        if(empty()){
            return 0;
        } else {
            return stack[n--];
        }
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