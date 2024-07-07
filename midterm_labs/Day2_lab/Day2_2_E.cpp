#include <iostream>
#include <string>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
    int currentIndex;
public:
    Array(int arraySize) : array{ new int[arraySize]{} }, currentIndex{ 0 } {}
    ~Array() { delete[] array; }
    void add(int x){
        array[currentIndex++] = x;
    }
    void print() const{
        int korea = 0, japan = 0, china = 0;
        for(int i{ 0 }; i < currentIndex; i++){
            if(i % 3 == 0){
                korea += array[i];
            } else if (i % 3 == 1){
                japan += array[i];
            }
            else if (i % 3 == 2) {
                china += array[i];
            }
        }
        cout << korea << " " << japan << " " << china << "\n";
    }
};

int main(void){
    int m;
    cin >> m;
    while(m--){
        int n;
        cin >> n;
        Array arr(n);
        while(n--){
            int x;
            cin >> x;
            arr.add(x);
        }
        arr.print();
    }
    return 0;
}