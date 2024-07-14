#include <iostream>
#define MAX 353333
using namespace std;
class HashTable;
class Node{
private:
    int ele;
    bool isDeleted = false;
    friend class HashTable;
};
class HashTable{
private:
    Node** array;
    int N;
    int n;
public:
    HashTable() {
        N = MAX;
        n = 0;
        array = new Node*[N];
        for(int i{ 0 }; i < N; i++) {
            array[i] = NULL;
        }
    }
    ~HashTable() {
        if(isEmpty()) return;
        for(int i{ 0 }; i < N; i++) {
            if(array[i] != NULL){
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
        for(int i{ 0 }; i < N; i++){
            int temp = (idx + i) % N;
            if(array[temp] == NULL || array[temp]->isDeleted) {
                Node* newNode = new Node;
                newNode->ele = k;
                if(array[temp] == NULL) {
                    array[temp] = newNode;
                } else {
                    Node* old = array[temp];
                    array[temp] = newNode;
                    delete old;
                }
                n++;
                return;
            }
        }
    }
    void erase(int k) {
        if(isEmpty()) return;
        int idx = h(k);
        int probing = 0;
        for(int i{ 0 }; i < N; i++) {
            probing++;
            int temp = (idx + i) % N;
            if(array[temp] == NULL) {
                cout << 0 << " " << probing << endl;
                return;
            } else if (array[temp]->ele == k && !array[temp]->isDeleted) {
                cout << 1 << " " << probing << endl;
                array[temp]->isDeleted = true;
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
            } else if (array[temp]->ele == k && !array[temp]->isDeleted) {
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
        HashTable h;
        int n;
        cin >> n;
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
    return 0;
}