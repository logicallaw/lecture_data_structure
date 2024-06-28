#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array(int arraySize) : array{ new int[arraySize]{} }, arraySize{ arraySize } {}
    ~Array() { delete[] array; }
    void at(int i){
        cout << array[i] << "\n";
    }
    void add(int i, int z){
        for(int idx{ arraySize - 1}; idx > i; idx--){
            array[idx] = array[idx - 1];
        }
        array[i] = z;
        /* 1 2 3 4 5 6 7
         * 0 1 2 3 4 5 6
         * i = 2
         * n = 7
         * n - 2 = 5
         * i=2, n-2=5
         * idx{6} 3 > 2
         * array[6] = array[5]
         * array[3] = array[2]
         *
         */
    }
    void remove(int i){
        for(int idx{ i }; idx < arraySize - 1; idx++){
            array[idx] = array[idx + 1];
        }
        array[arraySize - 1] = 0;
        /* 1 2 3 4 5 6 7
         * 0 1 2 3 4 5 6
         * i = 2, n = 7
         * i+1=3, n-1=6
         * idx{2}  5 < 6
         * array[2] = array[3]
         * ...
         * array[5] = array[6]
         */
    }
    void set(int i, int z){
        array[i] = z;
    }
    void sum() const {
        int sum = 0;
        for(int i{ 0 }; i < arraySize; i++){
            sum += array[i];
        }
        cout << sum << "\n";
    }
    void print() const {
        for(int i{ 0 }; i < arraySize; i++){
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
        if(userInput == "at"){
            int i;
            cin >> i;
            arr.at(i);
        }
        else if (userInput == "add"){
            int i, z;
            cin >> i >> z;
            arr.add(i, z);
        }
        else if (userInput == "remove"){
            int i;
            cin >> i;
            arr.remove(i);
        }
        else if (userInput == "set"){
            int i, z;
            cin >> i >> z;
            arr.set(i, z);
        }
        else if(userInput == "sum"){
            arr.sum();
        }
        else if(userInput == "print"){
            arr.print();
        }
    }
    return 0;
}