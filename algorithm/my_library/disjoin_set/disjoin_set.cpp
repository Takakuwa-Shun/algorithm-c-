#include "disjoin_set.hpp"
#include <stdio.h>

DisjoinSet::DisjoinSet(const int n) {
    rank.resize(n, 0);
    parent.resize(n, 0);
    for (int i=0; i<n; i++) {
        rank[i] = 0;
        parent[i] = i;
    }
};

int DisjoinSet::findSet(const int x) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
};

void DisjoinSet::link(const int x, const int y) {
    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else if (rank[x] < rank[y]) {
        parent[x] = y;
    } else {
        parent[x] = y;
        rank[y]++;
    }
};

bool DisjoinSet::same(const int x, const int y) {
    return findSet(x) == findSet(y);
};

void DisjoinSet::unite(const int x, const int y) {
    link(findSet(x), findSet(y));
};

void DisjoinSet::print() {
    printf("\n**************************\n");
    printf("parent : %d", parent[0]);
    for (int i=1; i<parent.size(); i++) {
        printf(" %d", parent[i]);
    }
    printf("\n  rank : %d", rank[0]);
    for (int i=1; i<rank.size(); i++) {
        printf(" %d", rank[i]);
    }
    printf("\n**************************\n");
};