#include <stdio.h>


bool solve(int A[], int size, int start, int m) {
  if (m == 0) return true; 
  if (start >= size) return false;
  return solve(A, size, start + 1, m) || solve(A, size, start + 1, m - A[start]);
};

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++) {
      scanf("%d", &A[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
      int m;
      scanf("%d", &m);
      if (solve(A, n, 0 ,m)) {
        printf("%s\n", "yes");
      } else {
        printf("%s\n", "no");
      }
    }

    return 0;
}