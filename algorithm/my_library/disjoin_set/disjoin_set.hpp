#ifndef __DISJOIN_SET_H_INCLUDED__
#define __DISJOIN_SET_H_INCLUDED__
#include <vector>

// 互いに素な集合　P318
class DisjoinSet {
    private:
        std::vector<int> rank, parent;
        int findSet(const int x);
        void link(const int x, const int y);
    public:
        DisjoinSet(const int n);
        bool same(const int x, const int y);
        void unite(const int x, const int y);
        void print();
};
#endif