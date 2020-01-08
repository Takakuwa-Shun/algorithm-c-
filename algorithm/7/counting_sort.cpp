#include <stdio.h>

void printAll(int B[], int n);
void countingSort(int A[], int B[], int n, int k);

int main() {
    int n;
    scanf("%d", &n);
    int A[n], B[n], k=0;
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
        if (k < A[i]) k = A[i];
    }
    countingSort(A, B, n, k);
    printAll(B, n);
    return 0;
}

void countingSort(int A[], int B[], int n, int k) {
    int C[k+1];
    for (int i=0; i<=k; i++) {
        C[i] = 0;
    }
    for (int i=0; i<n; i++) {
        C[A[i]]++;
    }
    for (int i=1; i<=k; i++) {
        C[i] += C[i-1];
    }
    for (int i=n-1; i>=0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}

void printAll(int B[], int n) {
    printf("%d", B[0]);
    for (int i=1; i<n; i++) {
        printf(" %d", B[i]);
    }
}