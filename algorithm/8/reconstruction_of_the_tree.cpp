#include <stdio.h>

struct Node {
    int p, l, r;
};
void postorder(Node nodes[], int i, bool* first);

int main() {
    int n;
    scanf("%d", &n);
    Node nodes[n];
    for (int i=0; i<n; i++) {
        nodes[i].p = -1;
        nodes[i].l = -1;
        nodes[i].r = -1;
    }
    for (int i=0; i<n; i++) {
        int p;
        scanf("%d", &p);

    }

    return 0;
}

void postorder(Node nodes[], int i, bool* first) {
    if (nodes[i].l != -1) postorder(nodes, nodes[i].l, first);
    if (nodes[i].r != -1) postorder(nodes, nodes[i].r, first);
    if(*first) { 
        printf("%d", i);
        *first = false;
    } else {
        printf(" %d", i);
    }
};