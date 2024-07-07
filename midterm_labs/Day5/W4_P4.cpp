#include <iostream>
using namespace std;
class Queue{
private:
    int* queue;
    int f;
    int r;
    int n;
    int N;
public:
    Queue(int N) : N{ N }, queue{ new int[N]{} }, f{ 0 }, r{ 0 }, n{ 0 }{
        for(int i{ 0 }; i < N; i++){
            int x;
            cin >> x;
            enqueue(x);
        }
    }
    ~Queue() {
        delete[] queue;
    }
    bool isEmpty() const { return n == 0;}
    void size() const { cout << n << endl; }
    bool full() const { return (n == N);}
    void front() const{
        if(isEmpty()){ cout << "Empty" << endl; }
        else {
            cout << queue[f] << endl;
        }
    }
    void enqueue(int value){
        if(full()){
            cout << "Full" << endl;
        } else {
            queue[r] = value;
            r = (r + 1) % N;
            n++;
        }
    }
    int dequeue() {
        if(isEmpty()) {
            return -1;
        } else {
            int result = queue[f];
            f = (f + 1) % N;
            n--;
            return result;
        }
    }
    void replaceFront(int value){
        if(isEmpty()){
            return;
        } else {
            queue[f] += value;
        }
    }
};
int main(void) {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Queue q1(n);
        Queue q2(n);

        int r1 = 0, r2 = 0;
        for(int i{ 0 }; i < (n - 1); i++){
            int x = q1.dequeue();
            int y = q2.dequeue();
            cout << "Round" << i + 1 << " ";
            if(x > y) {
                r1++;
                q2.replaceFront(x - y);
                cout << x << ">" << y << " " << r1 << ":" << r2 << endl;
            } else if (x == y) {
                cout << x << "=" << y << " " << r1 << ":" << r2 << endl;
            } else { //x < y
                r2++;
                q1.replaceFront(y - x);
                cout << x << "<" << y << " " << r1 << ":" << r2 << endl;
            }
        }
        int x = q1.dequeue();
        int y = q2.dequeue();
        if(x > y) {
            r1++;
            cout << "Round" << n << " " << x << ">" << y << " " << r1 << ":" << r2 << endl;
        } else if (x == y){
            cout << "Round" << n << " " << x << "=" << y << " " << r1 << ":" << r2 << endl;
        } else {
            r2++;
            cout << "Round" << n << " " << x << "<" << y << " " << r1 << ":" << r2 << endl;
        }
        if(r1 > r2) {
            cout << "Winner P1" << endl;
        } else if (r1 == r2){
            if(x > y) {
                cout << "Winner P1" << endl;
            } else if (x == y){
                cout << "Draw" << endl;
            } else {
                cout << "Winner P2" << endl;
            }
        } else {
            cout << "Winner P2" << endl;
        }
    }
}