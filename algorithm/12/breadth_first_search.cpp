#include <stdio.h>
#include <queue>
#define N 100
using namespace std;

struct Node {
    int u, k, v[N], a;
};

void bfs(Node node[]);

int main() {
    int n;
    scanf("%d", &n);
    Node node[n];
    for (int i=0; i<n; i++) {
        scanf("%d %d", &node[i].u, &node[i].k);
        for (int j=0; j<node[i].k; j++) {
            scanf("%d", &node[i].v[j]);
        }
        node[i].a = -1;
    }
    bfs(node);

    for (int i=0; i<n; i++) {
        printf("%d %d\n", node[i].u, node[i].a);
    }

    return 0;
};

void bfs(Node node[]) {
    queue<int> que;
    node[0].a = 0;
    que.push(0);
    while(!que.empty()) {
        Node next = node[que.front()];
        que.pop();
        for (int i=0; i<next.k; i++) {
            int adj = next.v[i]-1;
            if (node[adj].a == -1) {
                node[adj].a = next.a + 1;
                que.push(adj);
            }
        }
    }
};