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
    int N;
    Edge*** matrix;
    vector<Vertex*> vertices;
    vector<Edge*> edges;
    int n; // 정점 개수
    int m; // 간선 개수

public:
    Graph(int maxVertices) : N(maxVertices) {
        matrix = new Edge**[N];
        for (int i = 0; i < N; i++) {
            matrix[i] = new Edge*[N];
            for (int j = 0; j < N; j++) {
                matrix[i][j] = nullptr;
            }
            vertices.push_back(nullptr);
        }
        n = 0;
        m = 0;
    }

//    ~Graph() {
//        for (int i = 0; i < N; i++) {
//            if (vertices[i] != nullptr) {
//                delete vertices[i];
//            }
//        }
//        for (Edge* edge : edges) {
//            delete edge;
//        }
//        for (int i = 0; i < N; i++) {
//            delete[] matrix[i];
//        }
//        delete[] matrix;
//    }

    void insert(int x) {
        if (vertices[x] == nullptr) {
            Vertex* newVertex = new Vertex;
            newVertex->ele = x;
            vertices[x] = newVertex;
            n++;
        }
    }

    Vertex* findVertex(int x) {
        if(vertices[x] != nullptr) {
            return vertices[x];
        } else {
            return nullptr;
        }
    }

    void insertEdge(int s, int d, const string& u) {
        Vertex* vS = findVertex(s);
        Vertex* vD = findVertex(d);
        if (vS == nullptr || vD == nullptr) {
            cout << -1 << endl;
            return;
        }
        if (matrix[s][d] != nullptr) {
            cout << -1 << endl;
            return;
        }
        Edge* edge = new Edge;
        edge->str = u;
        matrix[s][d] = edge;
        matrix[d][s] = edge;
        edges.push_back(edge);
        m++;
    }

    void print() const {
        cout << n << " " << m << endl;
    }
    void erase(int l) {
        Vertex* vL = findVertex(l);
        if(vL == nullptr) {
            cout << -1 << endl;
            return;
        }
        for(int i{ 1 }; i < N; i++) {
            if(matrix[l][i] != nullptr) {
                Edge* old = matrix[l][i];
                matrix[l][i] = nullptr;
                matrix[i][l] = nullptr;
                eraseEdge(old);
                delete old;
                m--;
            }
        }
        eraseVertex(l);
        cout << m << " ";
        for(int i{ 0 }; i < edges.size(); i++) {
            cout << edges[i]->str << " ";
        }
        cout << endl;
    }

    void eraseEdge(Edge* old) {
        for(int i{ 0 }; i < edges.size(); i++) {
            if(edges[i] == old) {
                edges.erase(edges.begin() + i);
                return;
            }
        }
    }

    void eraseVertex(int l) {
        delete vertices[l];
        vertices[l] = nullptr;
        n--;
    }
};

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    Graph h(2001);  // 최대 정점 번호는 2000이므로 2001로 지정

    // 정점 추가
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }

    // 간선 추가
    for (int i = 0; i < m; i++) {
        int s, d;
        string u;
        cin >> s >> d >> u;
        h.insertEdge(s, d, u);
    }

    // 그래프 상태 출력
    h.print();

    // 정점 삭제
    for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        h.erase(l);
    }

    return 0;
}
