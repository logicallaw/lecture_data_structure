#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MinHeap{
private:
    vector<int> v;
    int lastIndex;
public:
    MinHeap() {
        v.push_back(-1);
        lastIndex = 0;
    }
    int size() const { return lastIndex; }
    bool isEmpty() const { return lastIndex == 0; }
    void swap(int x, int y) {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }
    void upHeap() {
        int i = lastIndex;
        while(i != 1 && v[i/2] > v[i]) {
            swap(i/2, i);
            i /= 2;
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
            };
        }
        if(v[idx] > v[child]) {
            swap(idx, child);
            downHeap(child);
        }
    }
    void insert(int e) {
        v.push_back(e);
        lastIndex++;
        upHeap();
    }
    void pop() {
        if(isEmpty()) {
            cout << -1 << endl;
        } else {
            int result = v[1];
            v[1] = v[lastIndex];
            v.erase(v.begin() + lastIndex);
            lastIndex--;
            downHeap(1);
            cout << result << endl;
        }
    }
    void top() const {
        if(isEmpty()) {
            cout << -1 << endl;
        } else {
            cout << v[1] << endl;
        }
    }
    void print() const {
        if(isEmpty()) {
            cout << -1 << endl;
        } else {
            for(int idx{ 1 }; idx <= lastIndex; idx++) {
                cout << v[idx] << " ";
            }
            cout << endl;
        }
    }
};
int main(void) {
    int n;
    cin >> n;
    MinHeap h;
    while(n--) {
        string userInput;
        cin >> userInput;
        if(userInput == "insert") {
            int e;
            cin >> e;
            h.insert(e);
        } else if (userInput == "size") {
            cout << h.size() << endl;
        } else if (userInput == "isEmpty") {
            if(h.isEmpty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (userInput == "pop") {
            h.pop();
        } else if (userInput == "top") {
            h.top();
        } else if (userInput == "print") {
            h.print();
        }
    }
}