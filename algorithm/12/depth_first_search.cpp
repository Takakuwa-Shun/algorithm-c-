#include <stdio.h>
#include <stack>
using namespace std;
#define N 100

struct Node {
    int u, k, v[N];
};


// 再起
void dfs(int output[][2], const Node node[], const int u);
// スタック
void dfs2(int output[][2], const Node node[]);

int main() {
    int n;
    scanf("%d", &n);
    Node node[n];
    for (int i=0; i<n; i++) {
        scanf("%d %d", &node[i].u, &node[i].k);
        for (int j=0; j<node[i].k; j++) {
            scanf("%d", &node[i].v[j]); 
        } 
    }
    int output[n][2];
    for (int i=0; i<n; i++) {
        output[i][0] = 0;
        output[i][1] = 0;
    }
    // dfs(output, node, 1);
    dfs2(output, node);

    for (int i=0; i<n; i++) {
        printf("%d %d %d\n", node[i].u, output[i][0], output[i][1]);
    }
    return 0;
};

void dfs(int output[][2], const Node node[], const int u) {
    static int time = 1;
    if (output[u-1][0] > 0) return;
    output[u-1][0] = time;
    time++;
    for (int i=0; i<node[u-1].k; i++) {
        dfs(output, node, node[u-1].v[i]);
    } 
    if (output[u-1][1] > 0) return;
    output[u-1][1] = time;
    time++;
};

void dfs2(int output[][2], const Node node[]) {
    int time = 1;
    stack<Node> st;
    st.push(node[0]);
    while (!st.empty()) {
        Node cur = st.top();
        if (output[cur.u-1][0] == 0) {
            output[cur.u-1][0] = time;
            time++;
            for (int i=cur.k-1; i>=0; i--) {
                st.push(node[cur.v[i]-1]);
            }
        } else {
            if (output[cur.u-1][1] > 0) {
                st.pop();
                continue; 
            }
            output[cur.u-1][1] = time;
            time++;
            st.pop();
        }
    };
};