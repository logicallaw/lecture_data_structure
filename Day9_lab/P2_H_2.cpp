#include <iostream>
#include <vector>
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
            }
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
    int removeMin() {
        int result = v[1];
        v[1] = v[lastIndex];
        v.erase(v.begin() + lastIndex);
        lastIndex--;
        downHeap(1);
        return result;
    }
    void unsortedPrint(int p) {
        if(p <= lastIndex) {
            cout << v[p] << endl;
        }
    }
    void sortedPrint(int p) {
        vector<int> tempV;
        tempV.push_back(-1);
        int cnt = lastIndex;
        for(int i{ 0 }; i < cnt; i++) {
            tempV.push_back(removeMin());
        }
        if(p <= (tempV.size() - 1)) {
            cout << tempV[p] << endl;
        }
    }
};
class MaxHeap{
private:
    vector<int> v;
    int lastIndex;
public:
    MaxHeap() {
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
        while(i != 1 && v[i/2] < v[i]) {
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
            if(v[left] >= v[right]) {
                child = left;
            } else {
                child = right;
            }
        }
        if(v[idx] < v[child]) {
            swap(idx, child);
            downHeap(child);
        }
    }
    void insert(int e) {
        v.push_back(e);
        lastIndex++;
        upHeap();
    }
    int removeMax() {
        int result = v[1];
        v[1] = v[lastIndex];
        lastIndex--;
        downHeap(1);
        return result;
    }
    void unsortedPrint(int p) {
        if(p <= lastIndex) {
            cout << v[p] << endl;
        }
    }
    void sortedPrint(int p) {
        vector<int> tempV;
        tempV.push_back(-1);
        int cnt = lastIndex;
        for(int i{ 0 }; i < cnt; i++) {
            tempV.push_back(removeMax());
        }
        if(p <= (tempV.size() - 1)) {
            cout << tempV[p] << endl;
        }
    }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        MinHeap h1;
        MaxHeap h2;
        while(n--) {
            int x;
            cin >> x;
            h1.insert(x);
            h2.insert(x);
        }
        h1.unsortedPrint(p);
        h1.sortedPrint(p);
        h2.unsortedPrint(p);
        h2.sortedPrint(p);
    }
    return 0;
}
