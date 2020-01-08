#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Stack {
    private:
        int val[100];
        int next;
    public:
        Stack();
        void push(int x);
        int pop();
        bool isEmpty();
        bool isFull();
};

Stack::Stack(){
    next = 0;
}

void Stack::push(int x) {
    if(isFull()) {
        throw "Exception :full push\n";
    } else {
        val[next] = x;
        next++;
    }
}

int Stack::pop() {
    if(isEmpty()) {
        throw "Exception :empty pop\n";
    } else {
        next--;
        return val[next];
    }
}

bool Stack::isEmpty() {
    return next == 0;
}

bool Stack::isFull() {
    return next >= 100;
}

int main() {
    try {
        Stack stack;
        int a, b;
        char s[100];
        while (scanf("%s", s) != EOF) {
            switch (s[0]) {
                case '=':
                    goto OUT;
                case '+':
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a+b);
                    break;
                case '-':
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a-b);
                    break;
                case '*':
                    b = stack.pop();
                    a = stack.pop();
                    stack.push(a*b);
                    break;
                default:
                    stack.push(atoi(s));
                    break;
            }
        }
        OUT:
        printf("%d\n", stack.pop());
        if (!stack.isEmpty()) {
            throw "あれれ〜";
        }
    } catch(char const *str) {
        printf("%s\n", str);
    }
    
    return 0;
}