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
    Queue(int N) : N{ N }, queue{ new int[N]{} }, f{ 0 }, r{ 0 }, n{ 0 }{}
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
    void dequeue() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        } else {
            cout << queue[f] << endl;
            f = (f + 1) % N;
            n--;
        }
    }
    void rearNsum(int num) {
        if(isEmpty()){
            cout << "Empty" << endl;
        } else {
            if(num > n) {
                cout << "error" << endl;
            } else {
                int sum = 0;
                int idx = r;
                while(num--){
                    sum += queue[(idx - 1 + N) % N];
                    idx = (idx - 1 + N) % N;
                }
                cout << sum << endl;
            }
        }
    }
};
int main(void){
    int n, t;
    cin >> n >> t;
    Queue q(n);
    while(t--){
        string userInput;
        cin >> userInput;
        if(userInput == "size"){
            q.size();
        } else if (userInput == "isEmpty"){
            if(q.isEmpty()){
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
        } else if (userInput == "full") {
            if(q.full()){
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
        } else if (userInput == "rearNsum"){
            int num;
            cin >> num;
            q.rearNsum(num);
        } else if (userInput == "enqueue") {
            int value;
            cin >> value;
            q.enqueue(value);
        } else if (userInput == "dequeue"){
            q.dequeue();
        } else if (userInput == "front") {
            q.front();
        }
    }
}