#include <iostream>
#include <string>
using namespace std;
class HashTable;
class Node{
    int k;
    string v;
    friend class HashTable;
};
class HashTable{
private:
    Node** array;
    int N;
    int n;
public:
    HashTable(int N) : array{ new Node*[N] }, N{ N }, n{ 0 } {}
    ~HashTable() {
        delete[] array;
    }
    int h(int k) {
        return k % N;
    }
    bool isEmpty() const { return n==0; }
    bool isFull() const { return n == N; }
    void put(int k, string v) {
        if(isFull()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++) {
            int tempIdx = (idx + i) % N;
            if(array[tempIdx] == NULL) {
                Node* newNode = new Node;
                newNode->k = k;
                newNode->v = v;
                array[tempIdx] = newNode;
                cout << h(k) << " " << tempIdx << endl;
                n++;
                return;
            }
        }
        cout << -1 << endl;
    }
    void erase(int k) {
        if(isEmpty()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++) {
            int tempIdx = (idx + i) % N;
            if(array[tempIdx] != NULL && array[tempIdx]->k == k) {
                cout << array[tempIdx]->v << endl;
                Node* old = array[tempIdx];
                array[tempIdx] = NULL;
                delete old;
                n--;
                return;
            }
        }
        cout << "None" << endl;
    }
    void find(int k) {
        if(isEmpty()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++) {
            int tempIdx = (idx + i) % N;
            if(array[tempIdx] != NULL && array[tempIdx]->k == k) {
                cout << array[tempIdx]->v << endl;
                return;
            }
        }
        cout << "None" << endl;
    }
    void vacant() const { cout << N - n << endl; }
};
int main(void){
    int t, N;
    cin >> t >> N;
    HashTable h(N);
    while(t--) {
        string userInput;
        cin >> userInput;
        if(userInput == "put"){
            int k;
            string v;
            cin >> k >> v;
            h.put(k, v);
        } else if (userInput == "erase") {
            int k;
            cin >> k;
            h.erase(k);
        } else if (userInput == "find") {
            int k;
            cin >> k;
            h.find(k);
        } else if (userInput == "vacant") {
            h.vacant();
        }
    }
    return 0;
}