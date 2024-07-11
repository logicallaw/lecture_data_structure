#include <iostream>
#include <string>
using namespace std;
class HashTable;
class Node{
private:
    int k;
    string v;
    int cnt;
    friend class HashTable;
};
class HashTable{
private:
    Node** array;
    int N;
    int n;
public:
    HashTable() {
        N = 500000;
        array = new Node*[N];
        n = 0;
    }
    bool isEmpty() const { return n == 0; }
    bool isFull() const { return n == N; }
    int h(int k) {
        return k % N;
    }
    void add(int k, string v) {
        if(isFull()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++){
            int temp = (idx + i) % N;
            if(array[temp] == NULL) {
                Node* newNode = new Node;
                newNode->k = k;
                newNode->v = v;
                newNode->cnt = 0;
                array[temp] = newNode;
                n++;
                return;
            }
        }
    }
    void deleteNode(int k) {
        if(isEmpty()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++){
            int temp = (idx + i) % N;
            if(array[temp] != NULL && array[temp]->k == k) {
                Node* old = array[temp];
                array[temp] = NULL;
                delete old;
                n--;
                return;
            }
        }
    }
    void name(int k) {
        if(isEmpty()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++){
            int temp = (idx + i) % N;
            if(array[temp] != NULL && array[temp]->k == k) {
                cout << array[temp]->v << endl;
                return;
            }
        }
    }
    void number(string v) {
        if(isEmpty()) return;
        for(int i{ 0 }; i < N; i++) {
            if(array[i] != NULL && array[i]->v == v) {
                cout << array[i]->k << endl;
                return;
            }
        }
        cout << 0 << endl;
    }
    void present(string v) {
        if(isEmpty()) return;
        for(int i{ 0 }; i < N; i++) {
            if(array[i] != NULL && array[i]->v == v) {
                array[i]->cnt += 1;
                cout << array[i]->cnt << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
    void count(int k) {
        if(isFull()) return;
        int idx = h(k);
        for(int i{ 0 }; i < N; i++){
            int temp = (idx + i) % N;
            if(array[temp] != NULL && array[temp]->k == k) {
                cout << array[temp]->cnt << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
};
int main(void) {
    int t;
    cin >> t;
    HashTable h;
    while(t--) {
        string userInput;
        cin >> userInput;
        if(userInput == "add") {
            int x;
            string s;
            cin >> x >> s;
            h.add(x, s);
        } else if (userInput == "delete") {
            int x;
            cin >> x;
            h.deleteNode(x);
        } else if (userInput == "name") {
            int x;
            cin >> x;
            h.name(x);
        } else if (userInput == "number") {
            string s;
            cin >> s;
            h.number(s);
        } else if (userInput == "present") {
            string s;
            cin >> s;
            h.present(s);
        } else if (userInput == "count") {
            int x;
            cin >> x;
            h.count(x);
        }
    }
    return 0;
}
/* string s;
 * cin >> s;
 * int temp = 0;
 * for(int i{ 0 }; i < s.length(); s++) {
 *     int n = s[i] - 'a';
 *     for(int j{ 0 }; j < i; j++) {
 *         n *= 26;
 *     }
 *     temp += n;
 * }
 *
 */