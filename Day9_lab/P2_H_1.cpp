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
        while(i != 1 && v[i/2] > v[i]){
            swap(i/2, i);
            i /= 2;
        }
    }
    void downHeap(int idx) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int child;
        if(left > size()){ //left 노드에 도달한 경우
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
        if(v[idx] > v[child]){ //부모가 자식보다 키 값이 더 큰 경우
            swap(idx, child);
            downHeap(child);
        }
    }
    void insert(int x) {
        v.push_back(x);
        lastIndex++;
        upHeap();
    }
    int removeMin() { //오름차순 정렬시 제거하면서 리턴받아 사용
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
        printEle(v);
    }
    void sortedPrint(int p) {
        vector<int> sortedV;
        sortedV.push_back(-1);
        int cnt = lastIndex;
        for(int i{ 0 }; i < cnt; i++) {
            sortedV.push_back(removeMin());
        }
        if(p <= (sortedV.size() - 1)) {
            cout << sortedV[p] << endl;
        }
        printEle(sortedV);
    }
    void printEle(vector<int> tempV) {
        for(int i{ 1 }; i <= (tempV.size() - 1); i++) {
            cout << tempV[i] << " ";
        }
        cout << endl;
    }
};
class MaxHeap {
private:
    vector<int> v;
    int lastIndex;
public:
    MaxHeap() {
        v.push_back(-1);
        lastIndex = 0;
    }
    bool isEmpty() const { return lastIndex == 0; }
    int size() const { return lastIndex; }
    void swap(int x, int y) {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }
    void upHeap() {
        int i = lastIndex;
        while(i != 1 && v[i/2] < v[i]) { //자식이 부모보다 더 크면
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
    void insert(int x) {
        v.push_back(x);
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
        printEle(v);
    }
    void sortedPrint(int p) {
        vector<int> sortedV;
        sortedV.push_back(-1);
        int cnt = lastIndex;
        for(int i{ 0 }; i < cnt; i++) {
            sortedV.push_back(removeMax());
        }
        if(p <= (sortedV.size() - 1)) {
            cout << sortedV[p] << endl;
        }
        printEle(sortedV);
    }
    void printEle(vector<int> tempV) const {
        for(int i{ 1 }; i <= (tempV.size() - 1); i++) {
            cout << tempV[i] << " ";
        }
        cout << endl;
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
}