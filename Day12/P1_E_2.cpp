#include <iostream>
#define MAX 353333
using namespace std;
class HashTable;
class Node{
private:
    int k = 0;
    friend class HashTable;
};
class HashTable{
private:
    Node** array;
    int N = MAX;
    int n = 0;
public:
    HashTable() {
        array = new Node*[MAX];
        for(int i{ 0 }; i < N; i++) {
            array[i] = NULL;
        }
    }
    ~HashTable() {
        for(int i{ 0 }; i < N; i++) {
            if(array[i] != NULL) {
                delete array[i];
            }
        }
        delete[] array;
    }
    bool isEmpty() const { return n == 0; }
    bool isFull() const { return n == N; }
    int h(int k) { return k % N; }
    void insert(int k) {
        if(isFull()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++) {
            int temp = (idx + i) % N;
            if(array[temp] == NULL) {
                Node* newNode = new Node;
                newNode->k = k;
                array[temp] = newNode;
                n++;
                return;
            }
        }
    }
    void find(int k) {
        if(isEmpty()) return;
        int idx = h(k);
        int probing = 0;
        for(int i{ 0 }; i < N; i++){
            probing++;
            int temp = (idx + i) % N;
            if(array[temp] == NULL){
                cout << 0 << " " << probing << endl;
                return;
            } else if (array[temp]->k == k) {
                cout << 1 << " " << probing << endl;
                return;
            }
        }
    }
};
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        HashTable h;
        while(n--) {
            int x;
            cin >> x;
            h.insert(x);
        }
        int m;
        cin >> m;
        while(m--) {
            int x;
            cin >> x;
            h.find(x);
        }
    }
}