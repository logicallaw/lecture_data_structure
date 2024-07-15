#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Vertex{
public:
    int ele;
};
class Edge{
public:
    string str;
};
class Graph{
private:
    Edge*** matrix;
    vector<Vertex*> v;
    int N = 2001;
    int n = 0;
    int m = 0;
public:
    Graph() {
        matrix = new Edge**[N];
        for(int i{ 0 }; i < N; i++) {
            matrix[i] = new Edge*[N];
            for(int j{ 0 }; j < N; j++) {
                matrix[i][j] = NULL;
            }
            v.push_back(NULL);
        }
    }
    void insert(int l) {
        if(v[l] == NULL) {
            Vertex* newV = new Vertex;
            newV->ele = l;
            v[l] = newV;
            n++;
        }
    }
    Vertex* findVertex(int x) {
        if(v[x] != NULL) {
            return v[x];
        } else {
            return NULL;
        }
    }
    void insertEdge(int s, int d) {
        Vertex* vS = findVertex(s);
        Vertex* vD = findVertex(d);
        if(vS == NULL || vD == NULL) {
            cout << -1 << endl;
            return;
        }
        if(matrix[s][d] != NULL) {
            cout << -1 << endl;
            return;
        }
        Edge* newE = new Edge;
        newE->str = "";
        matrix[s][d] = newE;
        matrix[d][s] = newE;
        m++;
    }
    void isAdjacent(int a, int b) {
        Vertex* vA = findVertex(a);
        Vertex* vB = findVertex(b);
        if(vA == NULL || vB == NULL) {
            cout << -1 << endl;
            return;
        }
        if(matrix[a][b] && matrix[b][a]) {
            if(matrix[a][b] == matrix[b][a]){
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
    void print() const { cout << n << " " << m << endl; }
};
int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    Graph h;
    while(n--){
        int l;
        cin >> l;
        h.insert(l);
    }
    while(m--) {
        int s, d;
        cin >> s >> d;
        h.insertEdge(s, d);
    }
    h.print();
    while(k--) {
        int a, b;
        cin >> a >> b;
        h.isAdjacent(a, b);
    }
    return 0;
}