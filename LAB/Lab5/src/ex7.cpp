#include <iostream>
#include <climits>
using namespace std;

int n, m;
int adj[100][100];   // ma trận trọng số
bool visited[100];
int dist[100];
int parent[100];

void printPath(int v) {
    if (v == -1) return;
    printPath(parent[v]);
    if (parent[v] != -1)
        cout << "->";
    cout << v;
}

int main() {
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
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

    int s = 0; // đỉnh bắt đầu
    dist[s] = 0;

    // Dijkstra
    for (int k = 0; k < n - 1; k++) {
        int u = -1;
        int minDist = INT_MAX;

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
    cout << "\nKet qua Dijkstra tu dinh 0:\n";
    cout << "Dinh\tKhoang cach\tDuong di\n";

    for (int i = 0; i < n; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX) {
            cout << "INF\t\tKhong co\n";
        } else {
            cout << dist[i] << "\t\t";
            printPath(i);
            cout << endl;
        }
    }

    return 0;
}
