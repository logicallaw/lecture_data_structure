#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array(int n) : array{ new int[n] {} }, arraySize{ n }{
    }
    void at(int i){
        cout << array[i] << endl;
    }
    void add(int i, int z){
        for(int idx{ arraySize - 1 }; idx > i; idx--){
            array[idx] = array[idx - 1];
        }
        array[i] = z;
    }
    void remove(int i){
        for(int idx{ i }; idx < (arraySize - 1); idx++){
            array[idx] = array[idx + 1];
        }
        array[arraySize - 1] = 0;
    }
    void set(int i, int z){
        array[i] = z;
    }
    void count(int z) const {
        int count = 0;
        for(int i{ 0 }; i < arraySize; i++){
            if(array[i] == z){
                count++;
            }
        }
        cout << count << endl;
    }
    void print() const {
        for(int i{ 0 }; i < arraySize; i++){
            cout << array[i] << " ";
        }
        cout << endl;
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
        else if (userInput == "count")
        {
            int z;
            cin >> z;
            arr.count(z);
        }
        else if (userInput == "print"){
            arr.print();
        }

    }
}