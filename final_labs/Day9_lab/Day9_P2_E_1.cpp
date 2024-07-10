#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    int lastIndex;
public:
    MinHeap() {
        heap.push_back(-1);  // 인덱스를 1부터 시작하기 위해 더미 값 추가
        lastIndex = 1;
    }
    void upHeap(int index) {
        while (index > 1 && heap[index] < heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index /= 2;
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
            if(heap[left] <= heap[right]) {
                child = left;
            } else {
                child = right;
            }
        }
        if(heap[idx] > heap[child]) {
            swap(idx, child);
            downHeap(child);
        }
    }
    void insert(int x) {
        heap.push_back(x);
        lastIndex++;
        upHeap(lastIndex);
    }

    int removeMin() {
        int min = heap[1];
        heap[1] = heap[lastIndex];
        heap.erase(heap.begin() + lastIndex);
        lastIndex--;
        downHeap(1);
        return min;
    }

    int get(int index) const {
        return heap[index];
    }

    int size() const {
        return heap.size() - 1;  // 0번 인덱스는 더미 값이므로 제외
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, p;
        cin >> N >> p;
        MinHeap heap;
        vector<int> elements(N);

        for (int i = 0; i < N; ++i) {
            cin >> elements[i];
            heap.insert(elements[i]);
        }

        // 힙에서 p번째 요소 출력
        cout << heap.get(p) << endl;
        // 힙 정렬 후 p번째 요소 출력
        for (int i = 0; i < N; ++i) {
            elements[i] = heap.removeMin();
        }
        cout << elements[p - 1] << endl;
        cout << "HI" << endl;
    }
    return 0;
}
/*
1
6 4
8 4 6 2 3 10
 */