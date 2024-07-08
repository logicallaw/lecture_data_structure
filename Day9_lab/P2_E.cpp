#include <iostream>
#include <vector>
using namespace std;
class Heap{
private:
    vector<int> v;
    int lastIndex;
public:
    Heap() {
        v.push_back(-1);
        lastIndex = 0;
    }
    int size() const { return lastIndex; }
    bool isEmpty() const { return (lastIndex == 0); }
    void insert(int x) {
        v.push_back(x);
        lastIndex++;
        upHeap();
    }
    void swap(int x, int y){
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }
    void upHeap() {
        int i = lastIndex;
        while(i != 1 && v[i / 2] > v[i]) {
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
    void unsortedPrint(int p) const {
        cout << v[p] << endl;
    }
    void sortedPrint(int p) {
        vector<int> sortedV;
        sortedV.push_back(-1);
        int count = lastIndex;
        for(int i{ 0 }; i < count; i++) {
            sortedV.push_back(removeMin());
        }
        cout << sortedV[p] << endl;
    }
    int removeMin() {
        if(isEmpty()){
            return -1;
        } else {
            int result = v[1];
            v[1] = v[lastIndex];
            v.pop_back();
            lastIndex--;
            downHeap(1);
            return result;
        }

    }
};
int main(void){
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        Heap h;
        while(n--){
            int x;
            cin >> x;
            h.insert(x);
        }
        h.unsortedPrint(p);
        h.sortedPrint(p);
    }
}