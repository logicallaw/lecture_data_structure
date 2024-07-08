#include <iostream>
#include <string>
using namespace std;
class Queue{
private:
    int* array;
    int N;
    int f;
    int r;
    int n;
public:
    Queue(int size) : N{ size }, array{ new int[size] } {
        f = 0;
        r = 0;
        n = 0;
        for(int i{ 0 }; i < size; i++){
            int x;
            cin >> x;
            enqueue(x);
        }
    }
    ~Queue() { delete[] array; }
    bool isEmpty() const { return n == 0; }
    void enqueue(int x) {
        if(n == N) {
            cout << "Full" << endl;
        } else {
            array[r] = x;
            r = (r + 1) % N;
            n = n + 1;
        }
    }
    int size() const { return n; }
    int dequeue() {
        if(isEmpty()) {
            return -1;
        } else {
            int result = array[f];
            f = (f + 1) % N;
            n = n - 1;
            return result;
        }
    }
    void front() const {
        if(isEmpty()) {
            cout << "Empty" << endl;
        } else {
            cout << array[f] << endl;
        }
    }
    void rear() const {
        if (isEmpty()) {
            cout << "Empty" << endl;
        } else {
            cout << array[(r - 1 + N) % N] << endl;
        }
    }
    void replaceFront(int d) {
        array[f] += d;
    }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Queue q1(n);
        Queue q2(n);
        int r1 = 0;
        int r2 = 0;
        while(n--){
            int x = q1.dequeue();
            int y = q2.dequeue();
            if(x > y) {
                r1++;
            } else if (x < y) {
                r2++;
            }
        }
        if(r1 > r2) {
            cout << 1 << endl;
        } else if (r1 == r2) {
            cout << 0 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}