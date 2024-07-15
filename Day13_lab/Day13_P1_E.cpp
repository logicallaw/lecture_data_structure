#include <iostream>
#include <vector>
using namespace std;

class Vertex{
public:
    int ele;
};
class Graph{
private:
    int N = 20000;
    vector<vector<bool>> matrix;
    vector<Vertex*> v;
    int n;
    int m;
public:
    Graph() {
        //다 NULL로 초기화
        for(int i{ 0 }; i < N; i++) {
            vector<bool> temp;
            for(int j{ 0 }; j < N; j++) {
                temp.push_back(false);
            }
            matrix.push_back(temp);
        }
        for(int i{ 0 }; i < N; i++) {
            v.push_back(NULL);
        }
        n = 0;
        m = 0;
    }
//    ~Graph(){
//        for (int i = 0; i < v.size(); i++) {
//            delete v[i];
//        }
//    }
    void insert(int x) {
        Vertex* newVertex = new Vertex;
        newVertex->ele = x;
        if(v[x-1] == NULL) {
            v[x-1] = newVertex;
            n++;
        }
    }
    void insertMatrix(int s, int d) {
        Vertex* vertexS = findVertex(s);
        Vertex* vertexD = findVertex(d);
        if(vertexS == NULL || vertexD == NULL) {
            cout << -1 << endl;
            return;
        }
        if(matrix[s][d]) {
            cout << -1 << endl;
        } else {
            matrix[s][d] = true;
            matrix[d][s] = true;
            m++;
        }
    }
    Vertex* findVertex(int x) {
        if(v[x-1] != NULL) {
            return v[x-1];
        } else {
            return NULL;
        }
    }
    void print() {
        cout << n << " " << m << endl;
    }
};
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph h;
    while(n--) {
        int x;
        cin >> x;
        h.insert(x);
    }
    while(m--) {
        int s, d;
        cin >> s >> d;
        h.insertMatrix(s, d);
    }
    h.print();
}