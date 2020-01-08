#include <stdio.h>

int left(const int i, const int H);
int right(const int i, const int H);
int parent(const int i, const int H);
void maxHeapify(int A[], const int i, const int H);
void buildMaxHeap(int A[], const int H);

int main() {
    int H;
    scanf("%d", &H);
    int A[H+1];
    for (int i=1; i<=H; i++) {
        scanf("%d", &A[i]);
    }
    buildMaxHeap(A, H);
    for (int i=1; i<=H; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
    return 0;
};

int left(const int i, const int H) { return 2*i <= H ? 2*i : -1;};
int right(const int i, const int H) { return (2*i+1) <= H ? (2*i+1) : -1;};
int parent(const int i, const int H) { return (int)i/2 <= H ? (int)i/2 : -1;};

void maxHeapify(int A[], const int i, const int H) {
    const int l = left(i, H);
    const int r = right(i, H);
    int largest = i;
    largest = l != -1 && A[largest] < A[l] ? l : largest;
    largest = r != -1 && A[largest] < A[r] ? r : largest;

    if (largest != i) {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(A, largest, H);
    }
};

void buildMaxHeap(int A[], const int H) {
    for (int i=parent(H, H); i>=1; i--) {
        maxHeapify(A, i, H);
    }
};