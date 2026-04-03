/* 1. objects, nodes, edges
2. Adjacency, Path, Connected Graph, Directed Graph, Weighted Graph, Adjacency Matrix, Adjacency List
3. edge
4. neighbors
5. direction
6. weights
7. Adjacency Matrix, Adjacency List
8. BFS, DFS
9. Directed Acyclic Graphs
10. graph
11. C
12. B
13. C
14. C */
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    // Khởi tạo ma trận kề toàn 0
    int adj[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    cout << "Nhap " << m << " canh (uv):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // đồ thị vô hướng
    }

    cout << "Ma tran ke " << n << " x " << n << ":" << endl;

    // In tiêu đề cột
    cout << "  ";
    for (int i = 0; i < n; i++) {
        cout << i;
    }
    cout << endl;

    // In từng hàng
    for (int i = 0; i < n; i++) {
        cout << i << " ";
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
        }
        cout << endl;
    }

    return 0;
}
