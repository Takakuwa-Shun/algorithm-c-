#include <stdio.h>

void printAll(int A[], int size, int idx) {
    if (idx == 0) {
        printf("[%d]", A[0]);
    } else {
        printf("%d", A[0]);
    }
    for (int i=1; i<size; i++) {
        if (i == idx) {
            printf(" [%d]", A[i]);
        } else {
            printf(" %d", A[i]);
        }
    }
    printf("\n");
}

void swap(int A[], int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition(int A[], int p, int r) {
    int x = A[r], i=p, tmp;
    for (int j=p; j<r; j++) {
        if (A[j] < x) {
            swap(A, i, j);
            i++;
        }
    }
    swap(A, i, r);
    return i;
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    int idx = partition(A, 0, n-1);
    printAll(A, n, idx);
    return 0;
}