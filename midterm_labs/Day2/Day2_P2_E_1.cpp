#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int arraySize;
public:
    Array(int size) : array{new int[size]{} }, arraySize{ size } {
        for(int i{ 0 }; i < arraySize; i++) {
            int x;
            cin >> x;
            array[i] = x;
        }
    }
    ~Array() { delete[] array; }
    void printTotal() const {
        int korea = 0, japan = 0, china = 0;
        int p1 = 0, p2 = 0, p3 = 0;
        for(int i{ 0 }; i < arraySize; i++){
            if(i % 3 == 0 && array[i] != 0) {
                korea += array[i];
                p1++;
            }
            else if (i % 3 == 1 && array[i] != 0) {
                japan += array[i];
                p2++;
            } else if (i % 3 == 2 && array[i] != 0) {
                china += array[i];
                p3++;
            }
        }
        cout << korea << " " << japan << " " << china << endl;
    }
};
int main(void) {
    int n;
    cin >> n;
    while(n--){
        int size;
        cin >> size;
        Array arr(size);
        arr.printTotal();
    }
}