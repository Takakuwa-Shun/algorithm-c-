#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

struct Node {
    Node* prev;
    Node* next;
    int x;
};

class DoublyLinkedList {
    private:
        int size;
        Node* nil;
        Node* searchNode(int const x);
        void deleteNode(Node* node);
    public:
        DoublyLinkedList();
        void insert(int const x);
        void del(int const x);
        void deleteFirst();
        void deleteLast();
        void const printAll();
} list;

DoublyLinkedList::DoublyLinkedList() {
    size = 0;
    nil = new Node;
    nil -> prev = nil;
    nil -> next = nil;
};

void DoublyLinkedList::insert(int const x) {
    Node* node = new Node;
    node -> x = x;
    node -> prev = nil -> prev;
    node -> next = nil;
    nil -> prev -> next = node;
    nil -> prev = node;
    size++;
};

Node*  DoublyLinkedList::searchNode(int const x) {
    if (size <= 0) {
        printf("%s", "no content");
    }
    Node* cur = nil -> next;
    while (cur -> x != x) {
        if(cur == nil) return nullptr;
        cur = cur -> next;
    }
    return cur;
}

void DoublyLinkedList::deleteNode(Node* node) {
    if (size < 0) {
        throw "zero size list delete";
    } else {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
    delete node;
    size--;
}

void DoublyLinkedList::del(int const x) {
    deleteNode(searchNode(x));
};

void DoublyLinkedList::deleteFirst() {
    deleteNode(nil -> next);
};

void DoublyLinkedList::deleteLast() {
    deleteNode(nil -> prev);
};

void const DoublyLinkedList::printAll() {
    if (size <= 0) {
        printf("%s", "no content");
        return;
    }
    Node* cur = nil -> next;
    printf("%d", cur -> x);
    cur = cur -> next;
    while (cur != nil) {
        printf(" %d", cur -> x);
        cur = cur -> next;
    }
    printf("\n");
};


int main() {
    try {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++) {
            int x;
            char command[20];
            scanf("%s", command);
            if (strcmp(command, "insert") == 0) {
                scanf("%d", &x);
                list.insert(x);
            } else if (strcmp(command, "delete") == 0) {
                scanf("%d", &x);
                list.del(x);
            } else if (strcmp(command, "deleteFirst") == 0) {
                list.deleteFirst();
            } else if (strcmp(command, "deleteLast") == 0) {
                list.deleteLast();
            } else {
                throw "wrong command";
            }
        }
        list.printAll();
    } catch(char const *str) {
        printf("%s\n", str);
    }
    return 0;
}