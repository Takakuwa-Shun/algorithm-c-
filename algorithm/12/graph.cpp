#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int A[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i=0; i<n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j=0; j<k; j++) {
            int v;
            scanf("%d", &v);
            A[u-1][v-1] = 1;
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d", A[i][0]);
        for (int j=1; j<n; j++) {
            printf(" %d", A[i][j]);
        }
        printf("\n");
    }

    return 0;
};