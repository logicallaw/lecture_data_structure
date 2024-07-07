#include <iostream>
#include <string>
using namespace std;
class Array{
private:
    int* array;
    int currentIndex;
public:
    Array() : array{ new int[10000]{} }, currentIndex{ 0 } {}
    ~Array() { delete[] array; }
    void at(int i) {
        if(array[i] == 0) {
            cout << 0 << endl;
        } else {
            cout << array[i] << endl;
        }
    }
    void set(int i, int x) {
        if(array[i] == 0) {
            cout << 0 << endl;
        } else {
            array[i] = x;
        }
    }
    void add(int i, int x) {
        if(array[0] == 0) {
            array[currentIndex++] = x;
        } else if (array[i] == 0) {
            array[currentIndex++] = x;
        } else {
            for(int idx{ currentIndex }; idx > i; idx--){
                array[idx] = array[idx - 1];
            }
            array[i] = x;
            currentIndex++;
        }
    }
    void remove(int i) {
        if(array[i] == 0) {
            cout << 0 << endl;
        } else {
            int old = array[i];
            for(int idx{ i }; idx < currentIndex - 1; idx++){
                array[idx] = array[idx + 1];
            }
            array[--currentIndex] = 0;
            cout << old << endl;
        }
    }
    void printArray() const {
        if (currentIndex == 0) {
            cout << 0 << endl;
        } else {
            for(int i{ 0 }; i < currentIndex; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};
int main(void) {
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
        } else if (userInput == "set") {
            int i, x;
            cin >> i >> x;
            arr.set(i, x);
        } else if (userInput == "add") {
            int i, x;
            cin >> i >> x;
            arr.add(i, x);
        } else if (userInput == "remove") {
            int i;
            cin >> i;
            arr.remove(i);
        } else if (userInput == "printArray") {
            arr.printArray();
        }
    }
    return 0;
}