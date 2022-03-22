#ifndef __UNDIRECTED_GRAPH_H__
#define __UNDIRECTED_GRAPH_H__

#include <queue>
#include <stack>

#include "Graph.h"
#include "utils.h"

template <typename T>
class UndirectedGraph {
public:
    using Vertex   = Vertex<T>;
    using Vertices = Vertices<T>;
    using AdjList  = AdjacancyList<T>;

    UndirectedGraph(std::size_t size)
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
        std::vector<bool>  visited(m_size, false);
        std::stack<Vertex> st;
        st.emplace(source);

        while (!st.empty()) {
            Vertex vertex = st.top();
            st.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                f(vertex);
            }

            for (auto& v : m_adjList[vertex]) {
                if (visited[v] == false) {
                    st.emplace(v);
                }
            }
        }
    }

    template <typename F>
    void BFS(Vertex source, F&& f) {
        std::vector<bool>  visited(m_size, false);
        std::queue<Vertex> Q;
        Q.emplace(source);

        while (!Q.empty()) {
            Vertex vertex = Q.front();
            Q.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                f(vertex);
            }

            for (auto& v : m_adjList[vertex]) {
                if (visited[v] == false) {
                    Q.emplace(v);
                }
            }
        }
    }

    bool isPathExists(Vertex source, Vertex destination) {
        bool result;
        BFS(source, [&result, destination](const Vertex& vertex) {
            if (vertex == destination) {
                result = true;
            }
        });
        return result;
    }

private:
    std::size_t m_size;
    AdjList     m_adjList;
};

#endif
