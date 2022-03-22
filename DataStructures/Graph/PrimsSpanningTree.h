#ifndef __PRIMS_MST_H__
#define __PRIMS_MST_H__
#include <queue>

#include "Graph.h"
/*
 * Prim's Algo implementation in C++ to find MST
 * 1. Start with two sets of edges - visited and not visited.
 *    (visited = edge's source node is visited)
 * 2. Initially both set will be empty, start by adding any vertex's all edges
 *    to not visited set.
 * 3. Each iteration select one minimum weighted edge from not-visited set
 *    (using below criteria) and add it to visited set. Again add its all
 *    connected edges to not visited set.
 * 4. Select edge from not-visited set with minimum weight/distance
 * 5. End the process after N - 1 ( N = number of vertices ) iteration.
 */
template <typename T = int>
class PrimsMst {
public:
    PrimsMst()      = default;
    using Edge      = Edge<T>;
    using Edges     = Edges<T>;
    using AdjMatrix = AdjacancyMatrix<T>;

    Edges getMst(AdjMatrix& adjMatrix) {
        Edges results;

        std::vector<bool> visited(adjMatrix.size(), false);

        std::priority_queue<Edge> minHeap;
        // Select any one vertex and add all its edges to minHeap
        for (int i = 0; i < adjMatrix[0].size(); ++i) {
            if (adjMatrix[0][i] != 0) {
                minHeap.emplace(0, i, adjMatrix[0][i]);
            }
        }
        // Mark 0 as visited vertex
        visited[0] = true;

        // Max MST is max vertex - 1;
        int count = adjMatrix.size() - 1;

        while (!minHeap.empty() && count > 0) {
            auto edge = std::move(minHeap.top());
            minHeap.pop();

            if (!visited[edge.dst]) {
                visited[edge.dst] = true;
                // Add all its edges to minHeap;
                for (int j = 0; j < adjMatrix[edge.dst].size(); ++j) {
                    if (adjMatrix[edge.dst][j] != 0) {
                        minHeap.emplace(edge.dst, j, adjMatrix[edge.dst][j]);
                    }
                }
                results.emplace_back(std::move(edge));
                --count;
            }
        }

        return results;
    }
};

#endif
