#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    // Danh sách kề dùng mảng vector
    int adj[100][100];
    int deg[100]; // bậc của mỗi đỉnh

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
    }

    cout << "Nhap " << m << " canh (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Thêm v vào danh sách kề của u
        adj[u][deg[u]++] = v;
        // Thêm u vào danh sách kề của v (vô hướng)
        adj[v][deg[v]++] = u;
    }

    cout << "Danh sach ke" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int j = 0; j < deg[i]; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
