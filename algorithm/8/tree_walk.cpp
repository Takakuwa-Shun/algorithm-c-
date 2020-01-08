#include <stdio.h>

struct Node {
    int p, l, r;
};

void preorder(Node nodes[], int i, bool first);
void inorder(Node nodes[], int i, bool* first);
void postorder(Node nodes[], int i, bool* first);

int main() {
    int n;
    scanf("%d", &n);
    Node nodes[n];
    for (int i=0; i<n; i++) {
        int id, l, r;
        scanf("%d %d %d", &id, &l, &r);
        nodes[id].l = l;
        nodes[id].r = r;
        if (l != -1) nodes[l].p = id;
        if (r != -1) nodes[r].p = id;
    }

    printf("Preorder\n");
    preorder(nodes, 0, true);

    bool* firstInOrder = new bool();
    *firstInOrder = true;
    printf("\nInorder\n");
    inorder(nodes, 0, firstInOrder);
    delete firstInOrder;

    bool* firstPostOrder = new bool();
    *firstPostOrder = true;
    printf("\nPostorder\n");
    postorder(nodes, 0, firstPostOrder);
    delete firstPostOrder;
    return 0;
}

void preorder(Node nodes[], int i, bool first) {
    if(first) { 
        printf("%d", i);
    } else {
        printf(" %d", i);
    }
    if (nodes[i].l != -1) preorder(nodes, nodes[i].l, false);
    if (nodes[i].r != -1) preorder(nodes, nodes[i].r, false);
};

void inorder(Node nodes[], int i, bool* first) {
    if (nodes[i].l != -1) inorder(nodes, nodes[i].l, first);
    if(*first) { 
        printf("%d", i);
        *first = false;
    } else {
        printf(" %d", i);
    }
    if (nodes[i].r != -1) inorder(nodes, nodes[i].r, first);
};
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
