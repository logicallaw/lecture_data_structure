#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void upHeap(int index) {
        while (index > 1 && heap[index] < heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }

    void downHeap(int index) {
        int size = heap.size() - 1;
        while (2 * index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int smaller = left;
            if (right <= size && heap[right] < heap[left]) {
                smaller = right;
            }
            if (heap[index] <= heap[smaller]) break;
            swap(heap[index], heap[smaller]);
            index = smaller;
        }
    }

public:
    MinHeap() {
        heap.push_back(-1);  // 인덱스를 1부터 시작하기 위해 더미 값 추가
    }

    void insert(int value) {
        heap.push_back(value);
        upHeap(heap.size() - 1);
    }

    int removeMin() {
        int min = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
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
    }
    return 0;
}