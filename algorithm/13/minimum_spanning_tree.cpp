#include <stdio.h>
static const int INF = 200000;
static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int A[N][N];
int parent[N];
int prim(const int n);

int main() {
    int n;
    scanf("%d", &n);
    int S[n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {   
            scanf("%d", &A[i][j]);
        }
        S[i] = INF;
    }

    printf("%d", prim(n));
    return 0;
};

int prim(const int n) {
    int parent[n], distance[n], color[n];
    for(int i=0; i<n; i++) {
        parent[i] = -1;
        distance[i] = INF;
        color[i] = WHITE;
    }
    distance[0] = 0;
    while(true) {
        int u = -1, minD = INF;
        for(int i=0; i<n; i++) {
            if (minD > distance[i] && color[i] != BLACK) {
                minD = distance[i];
                u = i;
            }
        }
        if (u == -1) break; 
        color[u] = BLACK;
        for(int j=0; j<n; j++) {
            if (A[u][j] != -1 && A[u][j] < distance[j] && color[j] != BLACK) {
                distance[j] = A[u][j];
                color[j] = GRAY;
                parent[j] = u;
            }
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        if(parent[i] != -1)sum += A[i][parent[i]];
    }
    return sum;
};