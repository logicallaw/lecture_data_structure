#include <iostream>
#include <string>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
    int currentIndex;
public:
    Array(int arraySize = 10000) : array{ new int[arraySize]{} }, currentIndex{ 0 } {}
    ~Array() { delete[] array; }
    void at(int i){
        if(array[i] == 0){
            cout << "0\n";
        }
        else {
            cout << array[i] << "\n";
        }
    }
    void set(int i, int x){
        if(array[i] == 0){
            cout << "0\n";
        }
        else {
            array[i] = x;
        }
    }
    void add(int i, int x){
        if(array[0] == 0){
            array[0] = x;
            return;
        }
        if(i > currentIndex) {
            array[++currentIndex] = x;
        } else {
            int currentIndex_Tmp = currentIndex;
            for(int idx{ currentIndex_Tmp }; idx >= i; idx--){
                array[idx + 1] = array[idx];
            }
            currentIndex++;
            array[i] = x;
        }
    }
    void remove(int i){
        if(i > currentIndex){
            cout << "0\n";
            return;
        }
        if(array[0] == 0) {
            cout << "0\n";
            return;
        }
        cout << array[i] << endl;
        for(int idx{ i }; idx < currentIndex; idx++){
            array[idx] = array[idx + 1];
        }
        array[currentIndex--] = 0;
    }
    void printArray() const {
        for(int i{ 0 }; i <= currentIndex; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(void){
    Array arr;
    int n;
    cin >> n;
    while(n--){
        string userInput;
        cin >> userInput;
        if(userInput == "at"){
            int i;
            cin >> i;
            arr.at(i);
        }
        else if (userInput == "set"){
            int i, x;
            cin >> i >> x;
            arr.set(i, x);
        }
        else if (userInput == "add"){
            int i, x;
            cin >> i >> x;
            arr.add(i, x);
        }
        else if (userInput == "remove"){
            int i;
            cin >> i;
            arr.remove(i);
        }
        else if (userInput == "printArray"){
            arr.printArray();
        }
    }
    return 0;
}