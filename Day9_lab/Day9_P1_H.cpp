#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Heap{
private:
    vector<int> v;
    int lastIdx; //last index
public:
    Heap() {
        v.push_back(-1);
        lastIdx = 0;
    }
    int size() const { return lastIdx; }
    bool isEmpty() const { return lastIdx == 0; }
    void insert(int e) {
        v.push_back(e);
        lastIdx++;
        upHeap(); //The worst case : O(nlogn) time
    }
    void print() const {
        if(isEmpty()) {
            cout << -1 << endl;
        } else {
            for(int i{ 1 }; i <= size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    void upHeap() {
        int i = lastIdx;
        while(i != 1 && v[i / 2] > v[i]) {
            swap(i/2, i);
            i /= 2;
        }
    }
    void pop() {
        if(isEmpty()){
            cout << -1 << endl;
        } else {
            cout << v[1] << endl;
            v[1] = v[lastIdx];
            v.erase(v.begin() + lastIdx);
            lastIdx--;
            downHeap(1);
        }
    }
    void downHeap(int idx) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int child;
        if(left > size()) {
            return;
        } else if (left == size()) {
            child = left;
        } else {
           if(v[left] <= v[right]) {
               child = left;
           } else {
               child = right;
           }
        }
        if(v[idx] > v[child]) {
            swap(idx, child);
            downHeap(child);
        }
    }
    void swap(int x, int y) {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }
    void top() const {
        if(isEmpty()){
            cout << -1 << endl;
        } else {
            cout << v[1] << endl;
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
            cout << h.size() << endl;
        } else if (userInput == "isEmpty") {
            if(h.isEmpty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "print") {
            h.print();
        } else if (userInput == "pop") {
            h.pop();
        } else if (userInput == "top") {
            h.top();
        }
    }
    return 0;
}