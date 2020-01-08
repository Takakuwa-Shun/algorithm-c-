#include <stdio.h>
#include<string.h>
#define CAPACITY 100

class PriorityQueue {
private:
    int A[CAPACITY];
    int size;
    int left(const int i);
    int right(const int i);
    int parent(const int i);
    void maxHeapify(const int i);
    void swap(int i, int j);
public:
    PriorityQueue ();
    void insert(const int k);
    int extract();
};


int main() {
    PriorityQueue queue;
    while(true) {
        char command[20];
        scanf("%s", command);
        if (strcmp(command, "end") == 0) {
            break;
        } else if (strcmp(command, "extract") == 0) {
            int val = queue.extract();
            printf("%d\n", val);
        } else {
            int k;
            scanf("%d", &k);
            queue.insert(k);
        }
    }
    return 0;
};

PriorityQueue::PriorityQueue (){
    size = 0;
};

void PriorityQueue::insert(const int k) {
    if (size+1 == CAPACITY) throw "FULL";
    size++;
    A[size] = k;
    int child = size;
    int parent = this->parent(size);
    while(parent != -1 && A[parent] < A[child]) {
        this->swap(parent, child);
        child = parent;
        parent = this->parent(parent);
    }
};

int PriorityQueue::extract() {
    if(size <= 0) throw "No data";
    int res = A[1];
    A[1] = A[size];
    size--;
    maxHeapify(1);
    return res;
};

void PriorityQueue::maxHeapify(const int i) {
    const int l = left(i);
    const int r = right(i);
    int largest = i;
    largest = l != -1 && A[largest] < A[l] ? l : largest;
    largest = r != -1 && A[largest] < A[r] ? r : largest;

    if (largest != i) {
        swap(i, largest);
        maxHeapify(largest);
    }
};

void PriorityQueue::swap(int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
};

int PriorityQueue::left(const int i) { return 2*i <= size ? 2*i : -1;};
int PriorityQueue::right(const int i) { return (2*i+1) <= size ? (2*i+1) : -1;};
int PriorityQueue::parent(const int i) {
    if (i == 1) return -1;
    int parent = (int)i/2;
    return parent <= size ? parent : -1;
};