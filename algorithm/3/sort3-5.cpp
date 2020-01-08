#include <iostream>
#include<string>
using namespace std;

class Card {
    private:
        int number;
        char pattern;
    public:
        Card() {};
        int get_number() const;
        char get_pattern() const;
        void input(string s);
        string get_value() const;
        bool equals(Card other) const;
};

int Card::get_number() const {
    return number;
}

char Card::get_pattern() const {
    return pattern;
}

void Card::input(string s) {
    pattern = s[0];
    number = s[1] - '0';
    // cout << pattern << ", " << number << endl;
}

string Card::get_value() const {
    return pattern + to_string(number);
}

void trace(Card cards[], int N) {
    for (int i=0; i<N; i++) {
        cout << cards[i].get_value() << " ";
    }
    cout << endl;
}

bool Card::equals(Card other) const {
    return pattern == other.get_pattern() && number == other.get_number();
}

void bubbleSort(Card card[], int N) {
    bool flg = true;
    for (int i=0; flg; i++) {
        flg = false;
        for (int j = N-1; j > i; j--) {
            if (card[j-1].get_number() > card[j].get_number()) {
                Card c = card[j];
                card[j] = card[j-1];
                card[j-1] = c;
                flg = true;
            }
        }
    }
    trace(card, N);
    cout << "Stable" << endl;
}

void selectionSort(Card card[], int N) {
    for (int i=0; i<N-1; i++) {
        int min = i;
        for (int j = i; j < N; j++) {
            if (card[min].get_number() > card[j].get_number()) {
                min = j;
            }
        }
        Card c = card[i];
        card[i] = card[min];
        card[min] = c;
    }
    trace(card, N);
}

int main() {
    int N;
    cin >> N;
    Card cards1[N];
    Card cards2[N];
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        cards1[i].input(s);
        cards2[i].input(s);
    }
    bubbleSort(cards1, N);
    selectionSort(cards2, N);

    bool is_stable = true;
    for (int i=0; i<N; i++) {
        if (!cards1[i].equals(cards2[i])) {
            is_stable = false;
            break;
        }
    }
    if (is_stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
}