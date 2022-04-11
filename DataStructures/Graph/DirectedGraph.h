#ifndef __DIRECTED_GRAPH_H__
#define __DIRECTED_GRAPH_H__

#include <queue>
#include <stack>

#include "Graph.h"
#include "utils.h"

template <typename T>
class DirectedGraph {
public:
    using Vertex   = Vertex<T>;
    using Vertices = Vertices<T>;
    using AdjList  = AdjacancyList<T>;
    DirectedGraph(std::size_t size)
        : m_size(size), m_adjList(size, Vertices{}) {}

    template <typename N>
    void addEdge(N&& a, N&& b) {
        static_assert(std::is_same_v<T, remove_cv_ref_t<N>>,
                      "Types are not same !!!");
        m_adjList[a].emplace_back(b);
    }

    AdjList& getAdjacancyList() { return m_adjList; }

    template <typename F>
    void DFS(Vertex source, F&& f) {
        std::stack<Vertex> st;
        std::vector<bool>  visited(m_size, false);
        st.emplace(source);

        while (!st.empty()) {
            auto vertex = std::move(st.top());
            st.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                if (f(vertex) == false) {
                    return;
                }
                for (auto& v : m_adjList[vertex]) {
                    if (!visited[v]) {
                        st.emplace(v);
                    }
                }
            }
        }
    }

    template <typename F>
    void DFS_Recursion(Vertex source, F&& f) {
        std::vector<bool> visited(m_size, false);
        DFS_Recursion_Impl(source, visited, f);
    }

    template <typename F>
    bool DFS_Recursion_Impl(Vertex vertex, std::vector<bool>& visited, F&& f) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            if (f(vertex) == false) {
                return false;
            }
            for (auto& v : m_adjList[vertex]) {
                if (!visited[v]) {
                    if (!DFS_Recursion_Impl(v, visited, f)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    template <typename F>
    void BFS(Vertex source, F&& f) {
        std::queue<Vertex> q;
        std::vector<bool>  visited(m_size, false);
        q.emplace(source);

        while (!q.empty()) {
            auto vertex = std::move(q.front());
            q.pop();
            if (!visited[vertex]) {
                visited[vertex] = true;
                if (f(vertex) == false) {
                    return;
                }
                for (auto& v : m_adjList[vertex]) {
                    if (!visited[v]) {
                        q.emplace(v);
                    }
                }
            }
        }
    }

    // Directed no cycle
    decltype(auto) getAllPaths(Vertex source, Vertex destination) {
        using Path  = Path<T>;
        using Paths = Paths<T>;

        Paths            results;
        std::queue<Path> q;
        q.emplace(Path{source});

        while (!q.empty()) {
            auto path = std::move(q.front());
            q.pop();

            auto& vertex = path.back();
            if (vertex == destination) {
                results.emplace_back(std::move(path));
                continue;
            }

            for (auto& v : m_adjList[vertex]) {
                Path p{path.begin(), path.end()};
                p.emplace_back(v);
                q.emplace(std::move(p));
            }
        }
        return results;
    }

    bool isPathExists(Vertex source, Vertex destination) {
        bool result;
        BFS(source, [&result, destination](auto& vertex) {
            if (vertex == destination) {
                result = true;
                return false;  // return from lambda false break from BFS loop
            }
            return true;
        });
        return result;
    }

    bool isCyclic() {
        std::vector<bool> visited(m_size, false);
        std::vector<bool> dfsVisited(m_size, false);
        for (int i = 0; i < m_adjList.size(); ++i) {
            if (visited[i] == false) {
                if (isCyclicDfs(i, visited, dfsVisited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool isCyclicDfs(Vertex vertex, std::vector<bool>& visited,
                     std::vector<bool>& dfsVisited) {
        visited[vertex]    = true;
        dfsVisited[vertex] = true;

        for (auto& v : m_adjList[vertex]) {
            if (visited[v] == false) {
                if (isCyclicDfs(v, visited, dfsVisited)) {
                    return true;
                }
            } else if (dfsVisited[v] == true) {
                return true;
            }
        }
        dfsVisited[vertex] = false;
        return false;
    }
    std::size_t m_size;
    AdjList     m_adjList;
};

#endif
