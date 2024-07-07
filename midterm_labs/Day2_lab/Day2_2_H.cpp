#include <iostream>
#include <string>
#include <cmath>
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
        int p1 = 0, p2 = 0, p3 = 0;
        for(int i{ 0 }; i < currentIndex; i++){
            if(i % 3 == 0 && array[i] != 0){
                korea += array[i];
                p1++;
            } else if (i % 3 == 1 && array[i] != 0){
                japan += array[i];
                p2++;
            }
            else if (i % 3 == 2 && array[i] != 0) {
                china += array[i];
                p3++;
            }
        }
        cout << korea << " " << japan << " " << china << endl;
        int avg1 = (p1 != 0) ? floor(static_cast<double>(korea) / p1) : 0;
        int avg2 = (p2 != 0) ? floor(static_cast<double>(japan) / p2) : 0;
        int avg3 = (p3 != 0) ? floor(static_cast<double>(china) / p3) : 0;
        cout << avg1 << " " << avg2 << " " << avg3 << endl;
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