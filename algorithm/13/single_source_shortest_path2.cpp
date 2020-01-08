#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

static const int INF = 100000; 
static const int N = 100; 
struct V {
    int v,c;
};

void dijkstra(const vector<V> vec[], const int n);
void dijkstra2(const vector<V> vec[], const int n);

int main() {
    int n;
    scanf("%d", &n);
    vector<V> vec[n];
    for (int i=0; i<n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j=0; j<k; j++) {
            V v;
            scanf("%d %d", &v.v, &v.c);
            vec[u].push_back(v);
        }
    }
    printf("**************************\n");
    for (int i=0; i<n; i++) {
        printf("%d : ", i);
        for(vector<const V>::iterator it = vec[i].begin() ; it != vec[i].end() ; it++) {
            V v = *it;
            printf(" %d %d", v.v, v.c);
        }
        printf("\n");
    }
    printf("**************************\n");
    dijkstra2(vec, n);
    return 0;
};

void dijkstra2(const vector<V> vec[], const int n) {
    int distance[n];
    bool visited[n];
    priority_queue<
        pair<int, int>,
        vector< pair<int, int> >,
        greater<pair<int, int> >
    > que;
    for (int i=0; i<n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[0] = 0;
    que.push(make_pair(0, 0));
    while(!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();
        int u = p.second;
        visited[u] = true;
        if (distance[u] < p.first) continue; 
        for(vector<const V>::iterator it = vec[u].begin() ; it != vec[u].end() ; it++) {
            V v = *it;
            if (visited[v.v]) continue;
            if (v.c + distance[u] < distance[v.v]) {
                distance[v.v] = v.c + distance[u];
                que.push(make_pair(distance[v.v], v.v));
            }
        }
    }
    printf("**************************\n");
    for (int i=0; i<n; i++) {
        printf("%d %d\n", i, distance[i]);
    }
};

void dijkstra(const vector<V> vec[], const int n) {
    int distance[n];
    bool visited[n];
    list<int> adj;
    for (int i=0; i<n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[0] = 0;
    adj.push_back(0);
    while(true) {
        int minD = INF;
        list<int>::iterator u = adj.end();
        for(list<int>::iterator it = adj.begin() ; it != adj.end() ; it++) {
            if (!visited[*it] && minD > distance[*it]) {
                minD = distance[*it];
                u = it;
            }
        }
        if (u == adj.end()) break; 
        visited[*u] = true;
        for(vector<const V>::iterator it = vec[*u].begin() ; it != vec[*u].end() ; it++) {
            V v = *it;
            if (visited[v.v]) continue;
            printf("(v.v, v.c, *u, distance[*u], distance[v.v]) = (%d, %d, %d, %d, %d), \n", v.v, v.c, *u, distance[*u], distance[v.v]);
            if (v.c + distance[*u] < distance[v.v]) {
                distance[v.v] = v.c + distance[*u];
            }
            adj.push_back(v.v);
        }
        adj.erase(u);
    }
    printf("**************************\n");
    for (int i=0; i<n; i++) {
        printf("%d %d\n", i, distance[i]);
    }
};