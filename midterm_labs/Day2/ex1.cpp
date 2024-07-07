#include <iostream>
#include <string>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array() : array{ new int[10000]{} }, arraySize{ 0 } {}
    ~Array() { delete[] array; }
    void at(int i){
        if(array[i] == 0){
            cout << 0 << endl;
        } else {
            cout << array[i] << endl;
        }
    }
    void set(int i, int x){
        if(array[i] == 0){
            cout << 0 << endl;
        } else {
            array[i] = x;
        }
    }
    void add(int i, int x){
        if(array[0] == 0){
            array[0] = x;
            return;
        }
        if(i > arraySize){
            array[++arraySize] = x;
        } else {
            for(int idx{arraySize + 1}; idx > i; idx--){
                array[idx] = array[idx - 1];
            }
            arraySize++;
            array[i] = x;
        }
    }

};
int main(void){
    int n;
    cin >> n;
    Array arr;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "at") {
            int i;
            cin >> i;
            arr.at(i);
        } else if (userInput == "set"){
            int i, x;
            cin >> i >> x;
            arr.set(i, x);
        } else if (userInput == "add") {
            int i, x;
            cin >> i >> x;
            arr.add(i, x);
        }
    }
}