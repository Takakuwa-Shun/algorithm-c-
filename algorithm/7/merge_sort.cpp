#include <stdio.h>
#include <climits>

int n;

void printAll(int A[], int size) {
    printf("%d", A[0]);
    for (int i=1; i<size; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}

int merge(int A[], int left, int mid, int right, int times) {
    printf("***************** left=%d, mid=%d, right=%d\n", left, mid, right);
    int n1 = mid - left, n2 = right - mid;
    int L[n1+1], R[n2+1];
    for (int i=0; i<n1; i++) {
        L[i] = A[left + i];
    }
    for (int i=0; i<n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i=0, j=0;
    printAll(L, n1+1);
    printAll(R, n2+1);
    for (int k=left; k<right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        times++;
    }
    printAll(A, n);
    return times;
}

int mergeSort(int A[], int left, int right, int times) {
    if (left + 1 < right) {
        int mid = (right + left) / 2;
        times = mergeSort(A, left, mid, times);
        times = mergeSort(A, mid, right, times);
        times = merge(A, left, mid, right, times);
    }
    return times;
}

int main() {
    scanf("%d", &n);
    int S[n]; 
    for (int i=0; i<n; i++) {
        scanf("%d", &S[i]);
    }
    int times = mergeSort(S, 0, n, 0);
    printAll(S, n);
    printf("%d", times);
    return 0;
}