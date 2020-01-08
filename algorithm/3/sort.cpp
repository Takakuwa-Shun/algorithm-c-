#include <iostream>
using namespace std;

void trace(int A[], int N) {
    for (int i=0; i<N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insersionSort(int A[], int N, bool is_ascending) {
    for (int i=1; i<N; i++) {
        int v = A[i];
        int j = i-1;
        while (j >= 0 && ((is_ascending && v < A[j]) || (!is_ascending && v > A[j]))) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

void bubbleSort(int A[], int N, bool is_ascending) {
    int change_cnt = 0;
    bool flg = true;
    for (int i=0; flg; i++) {
        flg = false;
        for (int j = N-1; j > i; j--) {
            if ((is_ascending && A[j-1] > A[j]) || (!is_ascending && A[j-1] < A[j])) {
                swap(A[j-1], A[j]);
                flg = true;
                change_cnt++;
            }
        }
    }
    trace(A, N);
    printf("%d", change_cnt);
}

void selectionSort(int A[], int N, bool is_ascending) {
    int change_cnt = 0;
    for (int i=0; i<N-1; i++) {
        if (is_ascending) {
            int min = i;
            for (int j = i; j < N; j++) {
                if (A[min] > A[j]) {
                    min = j;
                }
            }
            swap(A[i], A[min]);
            change_cnt++;
        } else {
            int max = i;
            for (int j = i; j < N; j++) {
                if (A[max] < A[j]) {
                    max = j;
                }
            }
            swap(A[i], A[max]);
            change_cnt++;
        }
        
    }
    trace(A, N);
    printf("%d", change_cnt);
}

int insersionSortForShellSort(int A[], int N, int g, int cnt, bool is_ascending) {
    for (int i=g; i<N; i++) {
        int v = A[i];
        int j = i-g;
        while (j >= 0 && ((is_ascending && v < A[j]) || (!is_ascending && v > A[j]))) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
    return cnt;
}

void shellSort(int A[], int N, bool is_ascending) {
    int cnt = 0;
    int m = 1;
    cout << m << endl;
    int G[m];
    for (int i=0; i<m; i++) {
        G[i] = 1;
        cout << G[i] << " ";
    }
    cout << endl;

    for (int i=0; i<m; i++) {
        cnt = insersionSortForShellSort(A, N, G[i], cnt, is_ascending);
    }
    cout << cnt << endl;
    trace(A, N);
}


int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    // insersionSort(A, N, true);
    // bubbleSort(A, N, false);
    // selectionSort(A, N, false);
    shellSort(A, N, true);

    return 0;
}