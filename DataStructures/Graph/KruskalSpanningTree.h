#ifndef __KRUSKAL_MST_H__
#define __KRUSKAL_MST_H__
#include <queue>

#include "DisjointSet.h"
#include "Graph.h"

template <typename T = int>
class KruskalMst {
public:
    KruskalMst()    = default;
    using Edge      = Edge<T>;
    using Edges     = Edges<T>;
    using AdjMatrix = AdjacancyMatrix<T>;

    Edges getMst(AdjMatrix& adjMatrix) {
        // Results to hold
        Edges results;
        // Priority Queue to sort all edges
        std::priority_queue<Edge> pq;

        for (auto i = 0; i < adjMatrix.size(); ++i) {
            for (auto j = 0; j < adjMatrix[i].size(); ++j) {
                if (adjMatrix[i][j] != 0) {
                    // insert source, destination, weight
                    pq.emplace(i, j, adjMatrix[i][j]);
                }
            }
        }

        // Disjoint Set to check loop in undirected weighted Graph
        DisjointSet dj(adjMatrix.size());

        auto count = adjMatrix.size() - 1;

        while (!pq.empty() && count > 0) {
            auto edge = std::move(pq.top());
            pq.pop();

            // check if loop is formed, first time always false
            if (!dj.isConnected(edge.src, edge.dst)) {
                dj.setUnion(edge.src, edge.dst);
                results.emplace_back(std::move(edge));
                --count;
            }
        }
        return results;
    }
};

#endif
