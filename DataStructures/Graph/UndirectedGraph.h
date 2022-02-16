#ifndef __UNDIRECTED_GRAPH_H__
#define __UNDIRECTED_GRAPH_H__

#include <iostream>
#include <queue>
#include <stack>
#include <type_traits>
#include <vector>

template <typename T>
using remove_cv_ref_t = typename std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T>
class UndirectedGraph {
public:
    using AdjacancyList = std::vector<std::vector<T>>;
    UndirectedGraph(std::size_t nodes)
        : m_nodes(nodes), m_adjList(nodes, std::vector<T>{}) {}

    template <typename N>
    void addEdge(N&& a, N&& b) {
        static_assert(std::is_same_v<T, remove_cv_ref_t<N>>,
                      "Types are not same !!!");
        m_adjList[a].emplace_back(b);
    }

    AdjacancyList& getAdjacancyList() { return m_adjList; }

    template <typename F>
    void DFS(F&& f) {
        std::vector<bool> visited(m_nodes, false);
        std::stack<T>     st;
        st.emplace(0);

        while (!st.empty()) {
            T node = st.top();
            st.pop();

            if (!visited[node]) {
                visited[node] = true;
                f(node);
            }

            for (auto& n : m_adjList[node]) {
                if (visited[n] == false) {
                    st.emplace(n);
                }
            }
        }
    }

    template <typename F>
    void BFS(T source, F&& f) {
        std::vector<bool> visited(m_nodes, false);
        std::queue<T>     Q;
        Q.emplace(source);

        while (!Q.empty()) {
            T node = Q.front();
            Q.pop();

            if (!visited[node]) {
                visited[node] = true;
                f(node);
            }

            for (auto& n : m_adjList[node]) {
                if (visited[n] == false) {
                    Q.emplace(n);
                }
            }
        }
    }

    bool isPathExists(T source, T destination) {
        bool result;
        BFS(source, [&result, destination](int node) {
            if (node == destination) {
                result = true;
            }
        });
        return result;
    }

private:
    std::size_t   m_nodes;
    AdjacancyList m_adjList;
};

#endif
