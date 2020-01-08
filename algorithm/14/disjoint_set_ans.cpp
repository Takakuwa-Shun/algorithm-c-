#include <stdio.h>
#include "../my_library/disjoin_set/disjoin_set.hpp"
// #include "../my_library/disjoin_set/disjoin_set.cpp"
using namespace std;

/**
  5 12
  0 1 4
  0 2 3
  1 1 2
  1 3 4
  1 1 4
  1 3 2
  0 1 3
  1 2 4
  1 3 0
  0 0 4
  1 0 2
  1 3 0
 */

int main() {
    int n, q, question = 0;
    scanf("%d %d", &n, &q);
    bool ans[q];
    DisjoinSet ds(n);
    // for (int i=0;i<q; i++) {
    //     int com, x, y;
    //     scanf("%d %d %d", &com, &x, &y);   
    //     if (com == 0) {
    //         ds.unite(x, y);
    //     } else {
    //         ans[question] = ds.same(x, y);
    //         ds.print();
    //         question++;
    //     }
    // }
    // for (int i=0;i<question; i++) {
    //     printf("%d\n", ans[i] ? 1 : 0);
    // }
    return 0;
};