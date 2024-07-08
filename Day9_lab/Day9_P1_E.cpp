#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Heap{
private:
    vector<int> v;
    int n; //원소의 개수
    int lastIdx; //last index
public:
    Heap() {
        n = 0;
        v.push_back(-1);
        lastIdx = 0;
    }
    void size() const { cout << n << endl; }
    bool isEmpty() const { return n == 0; }
    void insert(int e) {
        v.push_back(e);
        n++;
        lastIdx++;
        upHeap(); //The worst case : O(nlogn) time
    }
    void print() const {
        if(isEmpty()) {
            cout << -1 << endl;
        } else {
            for(int i{ 1 }; i < v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    void upHeap() {
        int i = lastIdx;
        while(i != 1 && v[i / 2] > v[i]) {
            int temp = v[i / 2];
            v[i / 2] = v[i];
            v[i] = temp;
            i /= 2;
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    Heap h;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        } else if (userInput == "size") {
            h.size();
        } else if (userInput == "isEmpty") {
            if(h.isEmpty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "print") {
            h.print();
        }
    }
}