#ifndef __KRUSKAL_MST_H__
#define __KRUSKAL_MST_H__
#include <queue>

#include "DisjointSet.h"
#include "Graph.h"

template <typename T = int>
class KruskalMst {
public:
    KruskalMst() = default;

    Edges<T> getMst(AdjacancyMatrix<T>& adjMatrix) {
        Edges<T> results;
        // Min heap to store edges of till now selected MST vertex
        std::priority_queue<Edge<T>> minHeap;

        // Sort edges by ascending order
        for (int i = 0; i < adjMatrix.size(); ++i) {
            for (int j = 0; j < adjMatrix[i].size(); ++j) {
                if (adjMatrix[i][j] != 0) {
                    minHeap.emplace(i, j, adjMatrix[i][j]);
                }
            }
        }

        int count = adjMatrix.size() - 1;

        DisjointSet dSet(adjMatrix.size());  // To check loop
        while (!minHeap.empty() && count > 0) {
            auto edge = std::move(minHeap.top());
            minHeap.pop();

            if (!dSet.isConnected(edge.src, edge.dst)) {
                dSet.setUnion(edge.src, edge.dst);
                results.emplace_back(std::move(edge));
                --count;
            }
        }
        return results;
    }
};

#endif
