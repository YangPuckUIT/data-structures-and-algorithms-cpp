#include <iostream>
using namespace std;

int n, m;
int adj[100][100];
int deg[100];
bool visited[100];

void DFS(int u) {
    visited[u] = true;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    cin >> n >> m;

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    // Chạy DFS từ đỉnh 0
    DFS(0);

    // Kiểm tra tất cả các đỉnh đã được thăm chưa
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected) {
        cout << "Do thi LIEN THONG";
    } else {
        cout << "Do thi KHONG LIEN THONG";
    }

    return 0;
}
