#include <iostream>
#include <stack>
using namespace std;

int n, m;
int adj[100][100];
int deg[100];
bool visited[100];
bool inStack[100];
stack<int> st;
bool hasCycle = false;

void DFS(int u) {
    visited[u] = true;
    inStack[u] = true;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            DFS(v);
        } else if (inStack[v]) {
            hasCycle = true; // phát hiện chu trình
        }
    }

    inStack[u] = false;
    st.push(u);
}

int main() {
    cout << "Nhap so dinh n: ";
    cin >> n;

    cout << "Nhap so canh m: ";
    cin >> m;

    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        visited[i] = false;
        inStack[i] = false;
    }

    cout << "Nhap " << m << " canh (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][deg[u]++] = v; // đồ thị có hướng
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    if (hasCycle) {
        cout << "Do thi co CHU TRINH! Khong the sap xep topo.";
    } else {
        cout << "Thu tu sap xep to-po (Topological Order):" << endl;
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }

    return 0;
}
