#ifndef __GRAPH_TRAVERSAL_H__
#define __GRAPH_TRAVERSAL_H__

#include <queue>

#include "Graph.h"

/**
 * Basic Traversal of undirected graph.
 * Will visit each node only once, uses visited concept
 * Can find shortes path between two vertices quickly
 */

template <typename T, typename F>
void BFSUndirected(AdjacancyList<T>& adjList, F&& f) {
    std::vector<bool> visited(adjList.size(), false);
    std::queue<T>     q;  // DFS same but with stack
    q.emplace(0);

    while (!q.empty()) {
        auto vertex = std::move(q.front());
        q.pop();

        if (visited[vertex] == false) {
            visited[vertex] = true;
            f(vertex);

            for (const auto& v : adjList[vertex]) {
                if (visited[v] == false) {
                    q.emplace(v);
                }
            }
        }
    }
}

/**
 * Basic Traversal of directed graph without cycle.
 * May visit each node more than once, Does not use visited concept
 * Can find shortes path between two vertices quickly
 */
template <typename T, typename F>
void BFSDirectedWithoutCycle(AdjacancyList<T>& adjList, F&& f) {
    std::queue<T> q;  // DFS same but with stack
    q.emplace(0);

    while (!q.empty()) {
        auto vertex = std::move(q.front());
        q.pop();

        f(vertex);

        for (const auto& v : adjList[vertex]) {
            q.emplace(v);
        }
    }
}

/**
 * Basic Traversal of directed graph with cycle.
 * May visit each node more than once, Does not use visited concept but removes
 * adjacancy list on visit.
 * Can find shortes path between two vertices quickly
 */
template <typename T, typename F>
void BFSDirectedWithCycle(AdjacancyList<T>& adjList, F&& f) {
    std::queue<T> q;  // DFS same but with stack
    q.emplace(0);

    while (!q.empty()) {
        auto vertex = std::move(q.front());
        q.pop();

        f(vertex);

        for (const auto& v : adjList[vertex]) {
            q.emplace(v);
        }
        adjList[vertex].clear();  // we have visited these
    }
}

/**
 * All possible path can only be found in Directed graph
 *  A list of vertices added to queue for traversal.
 * list contans info of previous paths
 */
template <typename T>
Paths<T> AllPathDirectedWithoutCycle(AdjacancyList<T>& adjList, T source,
                                     T destination) {
    Paths<T>            paths;
    std::queue<Path<T>> q;  // DFS same but with stack

    // Add source's path vector to queue
    q.emplace(Path<T>(1, source));

    while (!q.empty()) {
        auto path = std::move(q.front());
        q.pop();

        auto& thisVertex = path.back();
        if (thisVertex == destination) {
            paths.emplace_back(std::move(path));
            continue;
        }
        for (const auto& v : adjList[thisVertex]) {
            Path<T> p(path.begin(), path.end());
            p.emplace_back(v);
            q.emplace(std::move(p));
        }
    }
    return paths;
}

/**
 * All possible path can only be found in Directed graph
 *  A list of vertices added to queue for traversal.
 * list contans info of previous paths
 */
template <typename T>
Paths<T> AllPathDirectedWithCycle(AdjacancyList<T>& adjList, T source,
                                  T destination) {
    Paths<T>            paths;
    std::queue<Path<T>> q;  // DFS same but with stack

    // Add source's path vector to queue
    q.emplace(Path<T>(1, source));

    while (!q.empty()) {
        auto path = std::move(q.front());
        q.pop();

        auto& thisVertex = path.back();

        if (thisVertex == destination) {
            paths.emplace_back(std::move(path));
            continue;
        }
        for (const auto& v : adjList[thisVertex]) {
            Path<T> p(path.begin(), path.end());
            p.emplace_back(v);
            q.emplace(std::move(p));
        }
        adjList[thisVertex].clear();
    }
    return paths;
}

#endif
