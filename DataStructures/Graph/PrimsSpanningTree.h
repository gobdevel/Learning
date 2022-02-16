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
    PrimsMst() = default;

    Edges<T> getMst(AdjacancyMatrix<T>& adjMatrix) {
        Edges<T>          results;
        std::vector<bool> visited(adjMatrix.size(), false);

        // Min heap to store not-visited edges.
        std::priority_queue<Edge<T>> notVisited;

        // Select any first node and add its all edges to min heap
        for (int i = 0; i < adjMatrix[0].size(); ++i) {
            if (adjMatrix[0][i] != 0) {
                notVisited.emplace(0, i, adjMatrix[0][i]);
            }
        }
        visited[0] = true;
        int count  = adjMatrix.size() - 1;

        while (!notVisited.empty() && count > 0) {
            auto edge = std::move(notVisited.top());
            notVisited.pop();

            if (visited[edge.dst] == false) {
                visited[edge.dst] = true;
                // Add all edges of this selected vertex
                for (int i = 0; i < adjMatrix[edge.dst].size(); ++i) {
                    if (adjMatrix[edge.dst][i] != 0) {
                        notVisited.emplace(edge.dst, i, adjMatrix[edge.dst][i]);
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
