#include <iostream>
using namespace std;

int n, m;
int adj[100][100];   // danh sách kề
int deg[100];        // bậc mỗi đỉnh
bool visited[100];

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        visited[i] = false;
    }

    cout << "Nhap " << m << " canh (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // đồ thị vô hướng
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    cout << "Thu tu duyet DFS tu dinh 0: ";
    DFS(0);
    cout << endl;

    return 0;
}
