#include <stdio.h>
#include <algorithm>

int binarySearch(int S[], int n, int target) {
    int left = 0 , right = n, mid;
    while(left < right) {
        mid = (right + left) / 2;
        printf("left=%d, right=%d, mid=%d, S[mid]=%d\n", left, right, mid, S[mid]);
        if (target < S[mid]) {
            right = mid;
        } else if (S[mid] < target) {
            left = mid+1;
        } else {
            printf("gj! %d\n", mid);
            return mid;
        }
    }
    return -1;
}

int main() {
    int n, q;
    scanf("%d", &n);
    int S[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &S[i]);
    }
    std::sort(S, S + n);
    for (int i=0; i<n; i++) {
        printf("%d ", S[i]);
    }

    scanf("%d", &q);
    int res = 0;
    for (int i=0; i<q; i++) {
        int t;
        scanf("%d", &t);
        if (binarySearch(S, n, t) >= 0) res++;
    }

    printf("%d ", res);
    return 0;
}