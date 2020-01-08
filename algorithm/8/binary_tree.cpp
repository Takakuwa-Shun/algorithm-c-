#include <stdio.h>
#include <string>

struct Node {
    int p, l, r, s, deg, h;
    std::string type;
};

int setHeightAns(Node nodes[], int i) {
    int hr = 0, hl = 0;

    if (nodes[i].l != -1) {
        hl = setHeightAns(nodes, nodes[i].l) + 1;
    }
    if (nodes[i].r != -1) {
        hr = setHeightAns(nodes, nodes[i].r) + 1;
    }
    return nodes[i].h = (hr > hl ? hr : hl);
};

void setHeight(Node nodes[], const int cur, const int h) {
    if (nodes[cur].h < h) {
        nodes[cur].h = h;
        if (nodes[cur].deg == 0 && nodes[cur].s != -1 && nodes[nodes[cur].s].h < h) {
            nodes[nodes[cur].s].h = h;
        }
    }
    if (nodes[cur].p != -1) {
        setHeight(nodes, nodes[cur].p, (h+1));
    }
};

int main() {
    int n;
    scanf("%d", &n);
    Node nodes[n];
    for (int i=0; i<n; i++) {
        nodes[i].p = -1;
        nodes[i].l = -1;
        nodes[i].r = -1;
        nodes[i].s = -1;
        nodes[i].deg = 0;
        nodes[i].h = -1;
    }
    for (int i=0; i<n; i++) {
        int id, l, r;
        scanf("%d %d %d", &id, &l, &r);
        // 子を記録
        nodes[id].l = l;
        nodes[id].r = r;

        // 親を記録
        nodes[l].p = id;
        nodes[r].p = id;

        // 兄弟を記録
        nodes[l].s = r;
        nodes[r].s = l;

        // 子の数を記録
        if(l != -1) nodes[id].deg++;
        if(r != -1) nodes[id].deg++;
    }
    for (int i=0; i<n; i++) {
        if (nodes[i].p == -1) {
            nodes[i].type = "root";
        } else if (nodes[i].deg == 0) {
            nodes[i].type = "leaf";
            if (nodes[i].h == -1) {
                setHeight(nodes, i, 0);
            }
        } else {
            nodes[i].type = "internal node";
        }
    }

    for (int i=0; i<n; i++) {
        int depth = 0;
        for (int p=nodes[i].p ; p != -1; p=nodes[p].p, depth++);
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, nodes[i].p, nodes[i].s, nodes[i].deg, depth, nodes[i].h, nodes[i].type.c_str());
    }
    return 0;
}