#ifndef __TOPOLOGOCAL_SORT_H__
#define __TOPOLOGOCAL_SORT_H__

#include <queue>

#include "Graph.h"

static Vertices<int> TopoSort(AdjacancyList<int>& adjList) {
    Vertices<int>     vertices;
    std::vector<bool> visited(adjList.size(), false);
    std::vector<int>  inDegrees(adjList.size(), 0);
    std::queue<int>   q;

    // Build indegree
    for (const auto& vertices : adjList) {
        for (const auto& vertex : vertices) {
            inDegrees[vertex]++;
        }
    }

    // Add all zero in degree as source
    for (int i = 0; i < inDegrees.size(); ++i) {
        if (inDegrees[i] == 0) {
            q.emplace(i);
        }
    }

    while (!q.empty()) {
        Vertex<int> vertex = q.front();
        q.pop();

        if (visited[vertex] == false) {
            visited[vertex] = true;
            if (inDegrees[vertex] == 0) {
                vertices.emplace_back(vertex);
                for (const auto& v : adjList[vertex]) {
                    inDegrees[v]--;
                    if (inDegrees[v] == 0) {
                        q.emplace(v);
                    }
                }
            }
        }
    }
    return vertices;
}

#endif
