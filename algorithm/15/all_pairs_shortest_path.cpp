#include <stdio.h>
#include <vector>
#include <pair>
using namespace std;
static const int INF = -1;

/* 入力例1
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
*/

/* 入力例2
4 6
0 1 1
0 2 -5
1 2 2
1 3 4
2 3 1
3 2 7
*/

/* 入力例3
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 -7
*/

struct Node {
    int id;
    vector<pair<int, int> > adj;
};

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    Node node[V];
    for (int i=0; i<V; i++) {
        node[i].id = i;
    }
    for (int i=0; i<E; i++) {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        node[s].adj.push_back(make_pair(t, d));
    }
    return 0;
};