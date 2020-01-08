#include <stdio.h>

int fib(int dp[], const int i);

int main() {
    int n;
    scanf("%d", &n);
    int dp[n+1];
    for (int i=0; i<=n; i++) dp[i] = -1;
    printf("%d", fib(dp, n));
    return 0;
}

int fib(int dp[], const int i) {
    if (dp[i] != -1) return dp[i];
    if (i == 0 || i == 1) {
        return dp[i] = 1;
    } else {
        return dp[i] = fib(dp, i-1) + fib(dp, i-2);
    }
};