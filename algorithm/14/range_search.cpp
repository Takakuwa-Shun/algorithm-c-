#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
static const int NIL = -1;

/*
6
2 1
2 2
4 2
6 2
3 3
5 4
2
2 4 0 4
4 10 2 5
*/

struct Node {
    int location, l, r;
};

class Point {
    private:
        int id, x, y;
    public:
        Point(const int id, const int x, const int y);
        Point(){};
        int getX() const { return x;};
        int getY() const { return y;};
        bool operator < (const Point &p) const {
            return this->id < p.id;
        };
        void print() const {
            printf("%d\n", this->id);
        };
};

bool lessX(const Point &p1, const Point &p2);
bool lessY(const Point &p1, const Point &p2);
int makeKDTree(Point points[], Node node[], const int l, const int r, const int depth);
void find(const Point points[], Node node[], const int v, const int sx, const int tx, const int sy, const int ty, const int depth, vector<Point> &ans);


int np = 0;
int main() {
    int n, q;
    scanf("%d", &n);
    Node node[n];
    Point point[n];
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        point[i] = Point(i, x, y);
        node[i].location = NIL;
        node[i].l = NIL;
        node[i].r = NIL;
    }

    int root = makeKDTree(point, node, 0, n, 0);
    vector<Point> ans;
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int sx, tx, sy, ty;
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        find(point, node, root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (int i=0; i<ans.size(); i++) {
            ans[i].print();
        }
        printf("\n");
    }
};

Point::Point(const int id, const int x, const int y) {
    this->id = id;
    this->x = x;
    this->y = y;
};

bool lessX(const Point &p1, const Point &p2) {
    return p1.getX() < p2.getX();
};

bool lessY(const Point &p1, const Point &p2) {
    return p1.getY() < p2.getY();
};

int makeKDTree(Point points[], Node node[], const int l, const int r, const int depth) {
    // static int t = 0;
    if (l >= r) return NIL;
    int mid = (l + r) / 2;
    if (depth % 2 == 0) {
        sort(points + l, points + r, lessX);
    } else {
        sort(points + l, points + r, lessY);
    }
    int t = np++;
    node[t].location = mid;
    node[t].l = makeKDTree(points, node, l, mid, depth+1);
    node[t].r = makeKDTree(points, node, mid+1, r, depth+1);
    return t;
};

void find(const Point points[], Node node[], const int v, const int sx, const int tx, const int sy, const int ty, const int depth, vector<Point> &ans) {
    Point p = points[node[v].location];
    int x = p.getX();
    int y = p.getY();

    if (sx <= x && x <= tx && sy <= y && y <= ty) {
        ans.push_back(p);
    }

    if (depth % 2 == 0) {
        if (node[v].l != NIL && sx <= x) {
            find(points, node, node[v].l, sx, tx, sy, ty, depth+1, ans);
        }

        if (node[v].r != NIL && x <= tx) {
            find(points, node, node[v].r, sx, tx, sy, ty, depth+1, ans);
        }
    } else {
        if (node[v].l != NIL && sy <= y) {
            find(points, node, node[v].l, sx, tx, sy, ty, depth+1, ans);
        }

        if (node[v].r != NIL && y <= ty) {
            find(points, node, node[v].r, sx, tx, sy, ty, depth+1, ans);
        }
    }
};