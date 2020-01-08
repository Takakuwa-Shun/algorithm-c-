#include <stdio.h>
#include <string>

struct Node {
    int parent;
    int left;
    int right;
};

int main() {
    int n;
    scanf("%d", &n);
    Node nodes[n];
    for (int i=0; i<n; i++) {
        nodes[i].parent = -1;
        nodes[i].left = -1;
        nodes[i].right = -1;
    }
    for (int i=0; i<n; i++) {
        int id, k;
        scanf("%d %d", &id, &k);
        if (k > 0) {
            int l;
            scanf("%d", &l);
            nodes[id].left = l;
            nodes[l].parent = id;
            for (int j=1; j<k; j++) {
                int r;
                scanf("%d", &r);
                nodes[l].right = r;
                nodes[r].parent = id;
                l = r;
            }
        }
    }
    for (int i=0; i<n; i++) {
        std::string type;
        if (nodes[i].parent == -1) {
            type = "root";
        } else if (nodes[i].left == -1) {
            type = "leaf";
        } else {
            type = "internal node";
        }

        int p = nodes[i].parent;
        int depth = 0;
        while(p != -1) {
            depth++;
            p = nodes[p].parent;
        }

        printf("node %d: parent = %d, depth = %d, %s, [", i, nodes[i].parent, depth, type.c_str());
        if (nodes[i].left >= 0) {
            int l = nodes[i].left;
            printf("%d", l);
            for (int r = nodes[l].right; r != -1 ; r = nodes[r].right) {
                printf(", %d", r);
            }
        }
        printf("]\n");
    }

    return 0;
}