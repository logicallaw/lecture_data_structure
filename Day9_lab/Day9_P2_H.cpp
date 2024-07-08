#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MinArrayHeap
{
public:
    int N;
    vector<int> v;

    MinArrayHeap()
    {
        v.push_back(-1);
        this->N = 0;
    }

    int parent(int idx)
    {
        return idx / 2;
    }

    int leftchild(int idx)
    {
        return idx * 2;
    }

    int rightchild(int idx)
    {
        return idx * 2 + 1;
    }

    bool isEmpty()
    {
        return N == 0;
    }

    void upheap(int idx)
    {
        while (idx > 1 && v[parent(idx)] > v[idx])
        {
            swap(v[parent(idx)], v[idx]);
            idx = parent(idx);
        }
    }

    void insert(int e)
    {
        v.push_back(e);
        N++;
        upheap(N);
    }

    void downheap(int idx)
    {
        while (leftchild(idx) <= N)
        {
            int left = leftchild(idx);
            int right = rightchild(idx);
            int smaller = left;

            if (right <= N && v[right] < v[left])
                smaller = right;

            if (v[idx] <= v[smaller])
                break;

            swap(v[idx], v[smaller]);
            idx = smaller;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int root = v[1];
        v[1] = v[N];
        v.pop_back();
        N--;
        if (!isEmpty())
            downheap(1);
        return root;
    }

    void OutputHeap(int p)
    {
        cout << v.at(p) << endl;
    }

    void Outputsort(int p)
    {
        for (int i = 0; i < p - 1; i++)
        {
            pop();
        }
        cout << pop() << endl;
    }

    void init()
    {
        v.clear();
        vector<int>().swap(v);
    }
};

class MaxArrayHeap
{
public:
    int N;
    vector<int> v;

    MaxArrayHeap()
    {
        v.push_back(-1);
        this->N = 0;
    }

    int parent(int idx)
    {
        return idx / 2;
    }

    int leftchild(int idx)
    {
        return idx * 2;
    }

    int rightchild(int idx)
    {
        return idx * 2 + 1;
    }

    bool isEmpty()
    {
        return N == 0;
    }

    void upheap(int idx)
    {
        while (idx > 1 && v[parent(idx)] < v[idx])
        {
            swap(v[parent(idx)], v[idx]);
            idx = parent(idx);
        }
    }

    void insert(int e)
    {
        v.push_back(e);
        N++;
        upheap(N);
    }

    void downheap(int idx)
    {
        while (leftchild(idx) <= N)
        {
            int left = leftchild(idx);
            int right = rightchild(idx);
            int larger = left;

            if (right <= N && v[right] > v[left])
                larger = right;

            if (v[idx] >= v[larger])
                break;

            swap(v[idx], v[larger]);
            idx = larger;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int root = v[1];
        v[1] = v[N];
        v.pop_back();
        N--;
        if (!isEmpty())
            downheap(1);
        return root;
    }

    void OutputHeap(int p)
    {
        cout << v.at(p) << endl;
    }

    void Outputsort(int p)
    {
        for (int i = 0; i < p - 1; i++)
        {
            pop();
        }
        cout << pop() << endl;
    }

    void init()
    {
        v.clear();
        vector<int>().swap(v);
    }
};

int main()
{
    int T, num, e, p;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        MinArrayHeap minHeap;
        MaxArrayHeap maxHeap;
        cin >> num >> p;
        for (int j = 0; j < num; j++)
        {
            cin >> e;
            minHeap.insert(e);
            maxHeap.insert(e);
        }
        minHeap.OutputHeap(p);
        minHeap.Outputsort(p);
        maxHeap.OutputHeap(p);
        maxHeap.Outputsort(p);
    }
    return 0;
}

/*
1
6 4
8 4 6 2 3 10
*/
