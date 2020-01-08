#include <stdio.h>
#include <string>
#define MAX_VALUE 1000000

enum Type {
    ROOT, INTERNAL_NODE, LEAF
};

class Node {
    public:
    int id;
    Type type;
    int depth;
    Node* parent;
    Node* children[20];
    int childCnt;
    void addChild(Node *node);
};

void Node::addChild(Node *node) {
    children[childCnt] = node;
    childCnt++;
};

int main() {
    int n, k, idx;
    scanf("%d", &n);
    Node nodes[n];
    scanf("%d %d", &nodes[0].id, &k);
    nodes[0].parent = nullptr;
    nodes[0].depth = 0;
    nodes[0].type = ROOT;
    nodes[0].childCnt = 0;
    for (int j=0; j<k; j++) {
        scanf("%d", &idx);
        nodes[0].addChild(&nodes[idx]);
        nodes[idx].parent = &nodes[0];
        nodes[idx].depth = 1;
    }
    for (int i=1; i<n; i++) {
        scanf("%d %d", &nodes[i].id, &k);
        nodes[i].childCnt = 0;
        if (k == 0) {
            nodes[i].type = LEAF;
        } else {
            nodes[i].type = INTERNAL_NODE;
            for (int j=0; j<k; j++) {
                scanf("%d", &idx);
                nodes[i].addChild(&nodes[idx]);
                nodes[idx].parent = &nodes[i];
                nodes[idx].depth = nodes[i].depth + 1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        int parent = nodes[i].parent == nullptr ? -1 : nodes[i].parent->id;
        std::string type;
        switch (nodes[i].type) {
            case ROOT:
                type = "root";
                break;
            case INTERNAL_NODE:
                type = "internal node";
                break;
            case LEAF:
                type = "leaf";
                break;
            default:
                break;
        }
        printf("node %d: parent = %d, depth = %d, %s, [", nodes[i].id, parent, nodes[i].depth, type.c_str());
        for (int j=0; j<nodes[i].childCnt; j++) {
            if (j != 0) printf(", ");
            printf("%d", nodes[i].children[j] -> id);
        }
        printf("]\n");
    }

    return 0;
}