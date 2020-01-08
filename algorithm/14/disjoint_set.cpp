#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

static const int NONE = 0;

void unite(int sets[], const int n, const int x, const int y, int &cnt);
int same(int sets[], const int x, const int y);

int main() {
    int n, q, question = 0, cnt = 0;
    scanf("%d %d", &n, &q);
    int ans[q];
    int sets[n];
    for (int i=0;i<n; i++) {
        sets[i] = NONE;
    }
    for (int i=0;i<q; i++) {
        int com, x, y;
        scanf("%d %d %d", &com, &x, &y);   
        if (com == 0) {
            unite(sets, n, x, y, cnt);
        } else {
            ans[question] = same(sets, x, y);
            question++;
        }
    }
    for (int i=0;i<question; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
};

void unite(int sets[], const int n, const int x, const int y, int &cnt) {
    if (sets[x] == NONE && sets[y] == NONE) {
        cnt++;
        sets[x] = cnt; 
        sets[y] = cnt; 
    } else if (sets[x] != NONE && sets[y] == NONE) {
        sets[y] = sets[x];
    } else if (sets[x] == NONE && sets[y] != NONE) {
        sets[x] = sets[y];
    } else {
        cnt++;
        int xVal = sets[x];
        int yVal = sets[y];
        for (int i = 0; i<n; i++) {
            if (sets[i] == xVal || sets[i] == yVal) {
                sets[i] = cnt;
            }
        }
    }
};

int same(int sets[], const int x, const int y) {
    return sets[x] == sets[y] ? 1 : 0;
};