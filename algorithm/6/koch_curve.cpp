#include <stdio.h>
#include <cmath>

struct Point {
    float x;
    float y;
};


void kochCurve(Point p1, Point p2, int n) {
    if (n == 0) {
        printf("%f %f\n", p2.x, p2.y);
        return;
    }

    float diffP2P1X = (p2.x - p1.x);
    float diffP2P1Y = (p2.y - p1.y);

    Point s, t, u;
    s.x = p1.x + diffP2P1X / 3;
    s.y = p1.y + diffP2P1Y / 3;
    t.x = p2.x - diffP2P1X / 3;
    t.y = p2.y - diffP2P1Y / 3;

    if (diffP2P1X >= 0) {
        if (diffP2P1Y == 0) {
            u.x = p1.x + diffP2P1X / 2;
            u.y = p1.y + diffP2P1X * std::sqrt(3.0) / 6;
        } else if (diffP2P1Y > 0) {
            u.x = p1.x;
            u.y = p1.y + diffP2P1X * std::sqrt(3.0) * 2 / 3;
        } else {
            u.x = p2.x;
            u.y = p2.y + diffP2P1X * std::sqrt(3.0) * 2 / 3;
        }
    } else {
        if (diffP2P1Y == 0) {
            u.x = p1.x + diffP2P1X / 2;
            u.y = p1.y + diffP2P1X * std::sqrt(3.0) / 6;
        } else if (diffP2P1Y > 0) {
            u.x = p2.x;
            u.y = p2.y + diffP2P1X * std::sqrt(3.0) * 2 / 3;
        } else {
            u.x = p1.x;
            u.y = p1.y + diffP2P1X * std::sqrt(3.0) * 2 / 3;
        }
    }
    kochCurve(p1, s, n-1);
    kochCurve(s, u, n-1);
    kochCurve(u, t, n-1);
    kochCurve(t, p2, n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    printf("%f %f\n", p1.x, p1.y);
    kochCurve(p1, p2 ,n);
    return 0;
}