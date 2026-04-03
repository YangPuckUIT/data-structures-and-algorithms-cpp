#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    int adj[100][100];
    int deg[100];
    bool visited[100];
    int dist[100];

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        visited[i] = false;
        dist[i] = -1; // chưa tới được
    }

    cout << "Nhap " << m << " canh (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u; // vô hướng
    }

    // BFS từ đỉnh 0
    queue<int> q;
    q.push(0);
    visited[0] = true;
    dist[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "Khoang cach ngan nhat tu dinh 0 den cac dinh:" << endl;
    cout << "Dinh\tKhoang cach" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << endl;
    }

    return 0;
}
