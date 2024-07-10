#include <iostream>
#include <string>
using namespace std;
class HashTable;
class Node{
private:
    int k;
    string v;
    friend class HashTable;
};
class HashTable{
private:
    int N;
    int M;
    int n;
    Node** array;
public:
    HashTable(int N, int M) : N{ N }, M{ M }, array { new Node*[N] } { n = 0; }
    bool isEmpty() const { return n == 0; }
    void put(int k, string v){
        Node* newNode = new Node;
        newNode->k = k;
        newNode->v = v;
        for(int j{ 0 }; j <= (N-1); j++){
            int idx = hash(k, j) % N;
            if(array[idx] == NULL) {
                array[idx] = newNode;
                cout << h(k) << " " << idx << endl;
                n++;
                return;
            }
        }
        cout << h(k) << " " << -1 << endl;
    }
    void find(int k) {
        for(int j{ 0 }; j <= (N-1); j++){
            int idx = hash(k, j) % N;
//            cout << "idx:" << idx << endl;
            if(array[idx] != NULL){
                if(array[idx]->k == k){
                    cout << array[idx]->v << endl;
                    return;
                }
            }
        }
        cout << "None" << endl;
    }
    void erase(int k) {
        for(int j{ 0 }; j <= (N-1); j++){
            int idx = hash(k, j) % N;
//            cout << "idx:" << idx << endl;
            if(array[idx] != NULL){
                if(array[idx]->k == k){
                    cout << array[idx]->v << endl;
                    Node* old = array[idx];
                    array[idx] = NULL;
                    delete old;
                    n--;
                    return;
                }
            }
        }
        cout << "None" << endl;
    }
    void vacant() const {
        cout << (N - n) << endl;
    }
    int h(int k) {
//        cout << k % N << ", ";
        return k % N;
    }
    int d(int k) {
//        cout << M - (k % M) << ", ";
        return M - (k % M);
    }
    int hash(int k, int j) {
//        cout << h(k) + j * d(k) << ", ";
        return h(k) + j * d(k);
    }
};
int main(void){
    int t, N, M;
    cin >> t >> N >> M;
    HashTable h(N, M);
    while(t--){
        string userInput;
        cin >> userInput;
        if (userInput == "put") {
            int k;
            string v;
            cin >> k >> v;
            h.put(k, v);
        } else if (userInput == "find") {
            int k;
            cin >> k;
            h.find(k);
        } else if (userInput == "erase") {
            int k;
            cin >> k;
            h.erase(k);
        } else if (userInput == "vacant") {
            h.vacant();
        }
    }
}