#include <iostream>
#include <climits>
using namespace std;

int n, m;
int adj[100][100];
int dist[100];
bool visited[100];
int parent[100];

void printPath(int v) {
    if (v == -1) return;
    printPath(parent[v]);
    if (parent[v] != -1) cout << " ";
    cout << v;
}

int main() {
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    cout << "Nhap " << m << " canh (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w; // đồ thị vô hướng
    }

    int s = 0;
    int t;
    cout << "Nhap dinh dich: ";
    cin >> t;

    // Dijkstra từ đỉnh 0
    dist[s] = 0;

    for (int k = 0; k < n - 1; k++) {
        int u = -1, minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] > 0 &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }

    // In kết quả
    if (dist[t] == INT_MAX) {
        cout << "Khong co duong di tu 0 den " << t;
    } else {
        cout << "Shortest path 0 -> " << t << ": ";
        printPath(t);
        cout << endl;
        cout << "Cost: " << dist[t];
    }

    return 0;
}
