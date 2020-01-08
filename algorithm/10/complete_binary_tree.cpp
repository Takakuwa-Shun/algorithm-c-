#include <stdio.h>
#include <math.h>

int main() {
    int H;
    scanf("%d", &H);
    int keys[H];
    for(int i=0; i<H; i++) {
        scanf("%d", &keys[i]);
    }
    for(int i=1; i<=H; i++) {
        printf("node %d: key = %d, ", i, keys[i-1]);

        int parent = (int)i/2;
        if (i>1 && parent <= H) {
          printf("parent key = %d, ", keys[parent-1]);
        }

        if (2*i <= H) {
          printf("left key = %d, ", keys[2*i-1]);
        }

        if (2*i+1 <= H) {
            printf("right key = %d, ", keys[2*i]);
        }
        printf("\n");
    }
    return 0;
};