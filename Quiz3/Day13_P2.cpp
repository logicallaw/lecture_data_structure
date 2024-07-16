#include <iostream>
#include <vector>
#include <string>
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
    vector<Edge*> e;
    int N = 2001;
    int n;
    int m;
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
        n = 0;
        m = 0;
    }
    Vertex* findVertex(int x) {
        if(v[x] != NULL){
            return v[x];
        } else {
            return NULL;
        }
    }
    void insert(int x) {
        if(v[x] == NULL) {
            Vertex* newV = new Vertex;
            newV->ele = x;
            v[x] = newV;
            n++;
        }
    }
    void insertEdge(int s, int d, string u) {
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
        newE->str = u;
        matrix[s][d] = newE;
        matrix[d][s] = newE;
        e.push_back(newE);
        m++;
    }
    void erase(int l) {
        Vertex* vL = findVertex(l);
        if(vL == NULL) {
            cout << -1 << endl;
            return;
        }
        for(int i{ 1 }; i < N; i++) {
            if(matrix[l][i] != NULL) {
                Edge* old = matrix[l][i];
                matrix[l][i] = NULL;
                matrix[i][l] = NULL;
                eraseEdge(old);
                delete old;
                m--;
            }
        }
        eraseVertex(l);
        cout << m << " ";
        for(int i{ 0 }; i < e.size(); i++) {
            cout << e[i]->str << " ";
        }
        cout << endl;
    }
    void eraseEdge(Edge* old) {
        for(int i{ 0 }; i < e.size(); i++) {
            if(e[i] == old) {
                e.erase(e.begin() + i);
                return;
            }
        }
    }
    void eraseVertex(int l) {
        Vertex* old = v[l];
        v[l] = NULL;
        delete old;
        n--;
    }
    void print() const { cout << n << " " << m << endl;        }
};
int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    Graph h;
    while(n--) {
        int x;
        cin >> x;
        h.insert(x);
    }
    while(m--) {
        int s, d;
        string u;
        cin >> s >> d >> u;
        h.insertEdge(s, d, u);
    }
    h.print();
    while(k--) {
        int x;
        cin >> x;
        h.erase(x);
    }
}