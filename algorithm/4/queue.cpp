#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

struct Process {
    char name[10];
    int time;
};

class Queue {
    private:
        Process array[100000];
        int head;
        int tail;
    public:
        Queue(){
            head = 0;
            tail = 0;
        };
        Process pop();
        void push(Process const x);
        bool const isEmpty();
        bool const isFull();
} queue;

Process Queue::pop() {
    head++;
    return array[head-1];
};

void Queue::push(Process const x) {
    array[tail] = x;
    tail++;
};

bool const Queue::isFull() {
    return tail == 100000;
};

bool const Queue::isEmpty() {
    return tail == head;
};

int main() {
    int n, q;
    scanf("%d %d",&n, &q);

    for (int i=0; i<n; i++) {
        int time;
        char name[10];
        scanf("%s %d", name, &time);
        Process process;
        strcpy(process.name, name);
        process.time = time;
        queue.push(process);
    }

    int time = 0;
    while (!queue.isEmpty()) {
        Process process = queue.pop();
        if (process.time <= q) {
            printf("%s %d\n", process.name, time + process.time);
            time += process.time;
        } else {
            process.time -= q;
            queue.push(process);
            time += q;
        } 
    }
    return 0;
}