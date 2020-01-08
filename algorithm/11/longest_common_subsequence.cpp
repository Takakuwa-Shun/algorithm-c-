#include <stdio.h>
#include <iostream>
#include <string>

const int calculateLongestCommonSequence(std::string X, std::string Y);

int main() {
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        std::string X;
        std::string Y;
        std::cin >> X;
        std::cin >> Y;
        printf("%d\n", calculateLongestCommonSequence(X, Y));
    }
    return 0;
};


const int calculateLongestCommonSequence(std::string X, std::string Y) {
    int lenX = X.size();
    int lenY = Y.size();
    int c[lenX+1][lenY+1];

    for(int i=0; i<=lenY; i++) {
        c[0][i] = 0;
    }
    for(int i=0; i<=lenX; i++) {
        c[i][0] = 0;
    }
    for(int i=1; i<=lenX; i++) {
        for(int j=1; j<=lenY; j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i-1][j-1] + 1;   
            } else {
                if (c[i-1][j] >= c[i][j-1]) {
                    c[i][j] = c[i-1][j];   
                } else {
                    c[i][j] = c[i][j-1];   
                }
            }
        }
    }
    return c[lenX][lenY];
}
