#include <stdio.h>
#include <stack>
using namespace std;

static const int INF = 100000; 
static const int N = 100; 
int A[N][N];

void dfs(const int n);
void dijkstra(const int n);

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j] = -1;
        }
    }
    for (int i=0; i<n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j=0; j<k; j++) {
            int v, c;
            scanf("%d %d", &v, &c);
            A[u][v] = c;
            A[v][u] = c;
        }
    }
    // dfs(n);
    dijkstra(n);
    return 0;
};

void dijkstra(const int n) {
    int distance[n];
    bool visited[n];
    for (int i=0; i<n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[0] = 0;
    while(true) {
        int u = -1, minD = INF;
        for(int i=0; i<n; i++) {
            if (!visited[i] && minD > distance[i]) {
                minD = distance[i];
                u = i;
            }
        }
        if (u == -1) break; 
        visited[u] = true;
        for(int v=0; v<n; v++) {
            if (A[u][v] == -1 || visited[v]) continue;
            if (A[u][v] + distance[u] < distance[v]) {
                distance[v] = A[u][v] + distance[u];
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d %d\n", i, distance[i]);
    }
};

void dfs(const int n) {
    int sssp[n], parent[n];
    bool visited[n];
    for (int i=0; i<n; i++) {
        sssp[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    stack<int> st;
    st.push(0);
    parent[0] = 0;
    sssp[0] = 0;
    while(!st.empty()) {
        int next = st.top();
        st.pop();
        visited[next] = true;
        for(int j=0; j<n; j++) {
            if (A[next][j] == -1) continue;
            if (A[next][j] + sssp[next] < sssp[j]) {
                sssp[j] = A[next][j] + sssp[next];
                parent[j] = next;
            }
            if (!visited[j]) {
                st.push(j);
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d %d\n", i, sssp[i]);
    }
};