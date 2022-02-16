#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__
#include <vector>

class DisjointSet {
public:
    // Initialize m_parent to self and rank to 1
    explicit DisjointSet(int size) : m_parent(size, 0), m_rank(size, 1) {
        for (int i = 0; i < size; ++i) {
            m_parent[i] = i;
        }
    }

    // Find parent of x, if not immediate find recursively and set all
    // intermediate to top parent
    int find(int x) {
        if (x == m_parent[x]) return x;
        return m_parent[x] = find(m_parent[x]);
    }

    void setUnion(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a != b) {
            if (m_rank[a] > m_rank[b]) {
                m_parent[b] = m_parent[a];
            } else if (m_rank[b] > m_rank[a]) {
                m_parent[a] = m_parent[b];
            } else {
                m_parent[b] = m_parent[a];
                m_rank[a]++;
            }
        }
    }

    int getSetCounts() {
        int count = 0;
        for (int i = 0; i < m_parent.size(); ++i) {
            if (m_parent[i] == i) {
                ++count;
            }
        }
        return count;
    }

    bool isConnected(int x, int y) { return (find(x) == find(y)); }

private:
    std::vector<int> m_parent;
    std::vector<int> m_rank;
};
#endif
