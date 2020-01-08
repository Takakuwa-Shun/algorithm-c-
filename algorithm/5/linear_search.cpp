#include <stdio.h>

int linearSearch(int t, int arr[], int size) {
    // for (int i=0; i<size ; i++) {
    //     if (t == arr[i]) {
    //         return i;
    //     }
    // }
    // return -1;

    int i = 0;
    arr[size] = t;
    while (arr[i] != t) i++;
    return i == size ? -1 : i;
}

int main() {
    try {
        int n, q, sum = 0;
        scanf("%d", &n);
        int S[n+1];
        for (int i=0; i<n; i++) {
            scanf("%d", &S[i]);
        }

        scanf("%d", &q);
        for (int i=0; i<q; i++) {
            int t;
            scanf("%d", &t);
            int result = linearSearch(t, S, n);
            if (result >= 0) {
                sum += 1;
            }
        }
        printf("%d", sum);
    } catch(char const *str) {
        printf("%s\n", str);
    }
    return 0;
}