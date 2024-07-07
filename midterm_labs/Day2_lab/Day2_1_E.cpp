#include <iostream>
#include <string>
using namespace std;
void swap(int* i1, int* i2);
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
    }
    return 0;
}

void swap(int* i1, int* i2){
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}