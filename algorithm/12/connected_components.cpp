#include <stdio.h>
#include <set>
#include <queue>
using namespace std;

const bool bfs(set<int> link[], int s, int t);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    set<int> link[n];
    for (int i=0; i<m; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        link[s].insert(t);
        link[t].insert(s);
    }
    int q;
    scanf("%d", &q);
    bool a[q];
    for (int i=0; i<q; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        a[i] = bfs(link, s, t);
    }
    for (int i=0; i<q; i++) {
        if (a[i]) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}

const bool bfs(set<int> link[], int s, int t) {
    queue<int> que;
    que.push(s);
    set<int> searched;
    
    while(!que.empty()) {
        int next = que.front();
        printf("s=%d t=%d next=%d\n", s, t, next);
        que.pop();
        set<int> adj = link[next];
        searched.insert(next);
        for (set<int>::iterator it = adj.begin(); it != adj.end(); it++) {
            if(*it == t) return true;
            if (searched.find(*it) == searched.end()) {
                que.push(*it);
            }
        }
    }
    return false;
};