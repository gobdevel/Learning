#ifndef __GRAPH_PROBLEMS_H__
#define __GRAPH_PROBLEMS_H__

#include <queue>

#include "Graph.h"

using Vert    = int;
using Verts   = Vertices<int>;
using AdjList = AdjacancyList<Vert>;

// Topological Sorting
static Verts topoSort(AdjList& adjList) {
    Verts            vertices;
    std::vector<int> inDegree(adjList.size(), 0);

    for (auto& list : adjList) {
        for (auto& v : list) {
            inDegree[v]++;
        }
    }

    std::queue<Vert> q;
    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) {
            q.emplace(i);
        }
    }

    while (!q.empty()) {
        auto vertex = q.front();
        q.pop();

        vertices.emplace_back(vertex);

        for (auto& v : adjList[vertex]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.emplace(v);
            }
        }
    }
    return vertices;
}

#endif
