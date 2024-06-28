#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array(int arraySize) : array{ new int[arraySize]{} }, arraySize{ arraySize } {
        for(int i{ 0 }; i < arraySize; i++)
            array[i] = i;
    }
    ~Array() { delete[] array; }
    void shift(int i, int j){
        int temp = array[j];
        for(int idx{j}; idx > i; idx--){
            array[idx] = array[idx - 1];
        }
        array[i] = temp;
        /* 1 2 3 4 5 6
         * 0 1 2 3 4 5
         * i = 1, j = 4
         * idx{4} 2 > 1
         * array[4] = array[3]
         * array[3] = array[2]
         * array[2] = array[1]
         *
         */
    }
    void swap(int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    void print() const{
        for(int i{ 0 }; i < arraySize; i++) {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};
int main(void){
    int t, n;
    cin >> t >> n;
    Array arr(n);
    while(t--){
        string userInput;
        cin >> userInput;
        if(userInput == "shift"){
            int i, j;
            cin >> i >> j;
            arr.shift(i, j);
        }
        else if (userInput == "swap"){
            int i, j;
            cin >> i >> j;
            arr.swap(i, j);
        }
        else if (userInput == "print"){
            arr.print();
        }
    }
    return 0;
}