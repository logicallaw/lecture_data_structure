#include <iostream>
#include <vector>
#include <string> // string을 사용하기 위해 추가
using namespace std;

class Vertex {
public:
    int ele;
};

class Edge {
public:
    string str;
};

class Graph {
private:
    int N = 2001;
    Edge*** matrix;
    vector<Vertex*> v;
    vector<Edge*> e;
    int n; // 정점 개수
    int m; // 간선 개수

public:
    Graph() {
        matrix = new Edge**[N];
        for (int i = 0; i < N; i++) {
            matrix[i] = new Edge*[N];
            for (int j = 0; j < N; j++) {
                matrix[i][j] = NULL;
            }
            v.push_back(NULL);
        }
        n = 0;
        m = 0;
    }

//    ~Graph() {
//        for (int i = 0; i < e.size(); i++){
//            delete e[i];
//        }
//        for (int i = 0; i < N; i++) {
//            delete[] matrix[i];
//            if(v[i] != NULL) {
//                delete v[i];
//            }
//        }
//        delete[] matrix;
//    }

    void insert(int x) {
        if (v[x] == NULL) {
            Vertex* newVertex = new Vertex;
            newVertex->ele = x;
            v[x] = newVertex;
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

    void insertEdge(int s, int d, const string& u) {
        Vertex* vS = findVertex(s);
        Vertex* vD = findVertex(d);
        if (vS == NULL || vD == NULL) {
            cout << -1 << endl;
            return;
        }
        if (matrix[s][d] != NULL) {
            cout << -1 << endl;
            return;
        }
        Edge* edge = new Edge;
        edge->str = u;
        matrix[s][d] = edge;
        matrix[d][s] = edge;
        e.push_back(edge);
        m++;
    }

    void print() const {
        cout << n << " " << m << endl;
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
        delete v[l];
        v[l] = NULL;
        n--;
    }
};

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    Graph h;  // 최대 정점 번호는 2000이므로 2001로 지정
    while(n--) {
        int x;
        cin >> x;
        h.insert(x);
    }
    // 정점 추가
    while(m--) {
        int s, d;
        string u;
        cin >> s >> d >> u;
        h.insertEdge(s,d,u);
    }
    // 그래프 상태 출력
    h.print();
    while(k--) {
        int l;
        cin >> l;
        h.erase(l);
    }

    return 0;
}