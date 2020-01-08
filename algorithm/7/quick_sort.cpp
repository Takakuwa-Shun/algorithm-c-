#include <stdio.h>

struct Card{ char pattern; int val; };

void printAll(Card cards[], int size);
void swap(Card cards[], int i, int j);
int partition(Card cards[], int p, int r);
void quickSort(Card cards[], int p, int r);
void bubbleSort(Card card[], int N);

int main() {
    int n;
    scanf("%d", &n);
    Card cards1[n];
    Card cards2[n];
    for(int i=0; i<n; i++) {
        char pattern;
        int val;
        scanf(" %c %d", &cards1[i].pattern, &cards1[i].val);
        cards2[i].pattern = cards1[i].pattern;
        cards2[i].val = cards1[i].val;
    }
    quickSort(cards1, 0, n-1);
    bubbleSort(cards2, n);

    bool isStable = true;
    for (int i=0; i<n; i++) {
        if (cards1[i].pattern != cards2[i].pattern || cards1[i].val != cards2[i].val) {
            isStable = false;
            break;
        }
    }
    if (isStable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    printAll(cards1, n);
    return 0;
}

void printAll(Card cards[], int size) {
    for (int i=0; i<size; i++) {
        printf("%c %d\n", cards[i].pattern, cards[i].val);
    }
}

void swap(Card cards[], int i, int j) {
    Card tmp = cards[i];
    cards[i] = cards[j];
    cards[j] = tmp;
}

int partition(Card cards[], int p, int r) {
    int x = cards[r].val, i=p, tmp;
    for (int j=p; j<r; j++) {
        if (cards[j].val < x) {
            swap(cards, i, j);
            i++;
        }
    }
    swap(cards, i, r);
    return i;
}

void quickSort(Card cards[], int p, int r) {
    if (p < r) {
        int q = partition(cards, p ,r);
        quickSort(cards, p , q-1);
        quickSort(cards, q+1, r);
    }
}

void bubbleSort(Card card[], int N) {
    bool flg = true;
    for (int i=0; flg; i++) {
        flg = false;
        for (int j = N-1; j > i; j--) {
            if (card[j-1].val > card[j].val) {
                swap(card, j, j-1);
                flg = true;
            }
        }
    }
}