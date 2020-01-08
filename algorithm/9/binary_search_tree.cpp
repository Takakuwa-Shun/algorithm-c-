#include <stdio.h>
#define VOLUME 100
#define NIL -1

struct Node {
    Node *p, *l, *r;
    int val;
};
void insert(Node* root, const int t);
Node* find(Node* root, const int t);
void del(Node* root, const int t);
Node* getSuccessor(Node* target);
void preorder(const Node* root);
void inorder(const Node* root);

int main() {
    int n;
    scanf("%d", &n);
    Node* root = new Node;
    root->p = NULL;
    root->l = NULL;
    root->r = NULL;
    root->val = NIL;
    for (int i=0; i<n; i++) {
        char command[10];
        scanf("%s", command);
        if (command[0] == 'i') {
            if (root->val == NIL) {
                scanf("%d", &(root->val));
            } else {
                int t;
                scanf("%d", &t);
                insert(root, t);
            }
        } else if (command[0] == 'f') {
            int t;
            scanf("%d", &t);
            Node* found = find(root, t);
            if (found == NULL) {
                printf("no\n");
            } else {
                printf("yes\n");
            }
        } else if (command[0] == 'd') {
            int t;
            scanf("%d", &t);
            del(root, t);
        } else {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
    return 0;
};

void insert(Node* root, const int t) {
    Node* node = new Node;
    node->p = NULL;
    node->l = NULL;
    node->r = NULL;
    node->val = t;
    while (root != NULL) {
        if (root->val > node->val) {
            if (root->l == NULL) {
                node->p = root;
                root->l = node;
                break;
            } else {
                root = root->l;
            }
        } else if (root->val < node->val) {
            if (root->r == NULL) {
                node->p = root;
                root->r = node;
                break;
            } else {
                root = root->r;
            }
        } else {
            return;
        }
    }
};

Node* find(Node* root, const int t) {
    while (root != NULL) {
        if (root->val > t) {
            root = root->l;
        } else if (root->val < t) {
            root = root->r;
        } else {
            return root;
        }
    }
    return NULL;
};

void del(Node* root, const int t) {
    Node* target = find(root, t);
    if (target->p == NULL) {
        Node* parent = getSuccessor(target);
    } else if (target->p->l == target) {
        if (target->l == NULL && target->r == NULL) {
            target->p->l = NULL;
        } else if (target->l != NULL && target->r == NULL) {
            target->p->l = target->l;
            target->l->p = target->p;
        } else if (target->l == NULL && target->r != NULL) {
            target->p->l = target->r;
            target->r->p = target->p;
        } else {
            Node* successor = getSuccessor(target);
            target->p->l = target->r;
            target->r->p = target->p;
            target->l->p = target->r;
        }
    } else {
        if (target->l == NULL && target->r == NULL) {
            target->p->r = NULL;
        } else if (target->l != NULL && target->r == NULL) {
            target->p->r = target->l;
            target->l->p = target->p;
        } else if (target->l == NULL && target->r != NULL) {
            target->p->r = target->r;
            target->r->p = target->p;
        } else {
            target->p->r = target->r;
            target->r->p = target->p;
            target->l->p = target->r;
        }
    }
    delete target;
};

Node* getSuccessor(Node* target) {
    Node* successor = target->r;
    if (successor == NULL) {
        return target;
    }
    while (successor->l != NULL) {
        successor = successor->l;
    }
    return successor;
}

void preorder(const Node* root) {
    printf(" %d", root->val);
    if (root->l != NULL) preorder(root->l);
    if (root->r != NULL) preorder(root->r);
};

void inorder(const Node* root) {
    if (root->l != NULL) inorder(root->l);
    printf(" %d", root->val);
    if (root->r != NULL) inorder(root->r);
};