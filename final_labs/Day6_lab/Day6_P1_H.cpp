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
    Queue(int size) : N{ size }, array{ new int[size]{} } {
        f = 0;
        r = 0;
        n = 0;
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
    void dequeue() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        } else {
            int result = array[f];
            f = (f + 1) % N;
            n = n - 1;
            cout << result << endl;
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
};
int main(void) {
    int s;
    cin >> s;
    Queue q(s);
    int n;
    cin >> n;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (userInput == "size") {
            cout << q.size() << endl;
        } else if (userInput == "isEmpty") {
            if(q.isEmpty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "dequeue") {
            q.dequeue();
        } else if (userInput == "front") {
            q.front();
        } else if (userInput == "rear") {
            q.rear();
        }
    }
}