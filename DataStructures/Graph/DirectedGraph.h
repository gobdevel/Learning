#ifndef __DIRECTED_GRAPH_H__
#define __DIRECTED_GRAPH_H__

#include <iostream>
#include <queue>
#include <stack>
#include <type_traits>
#include <vector>

template <typename T>
using remove_cv_ref_t = typename std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T>
class DirectedGraph {
public:
    using AdjacancyList = std::vector<std::vector<T>>;
    DirectedGraph(std::size_t nodes)
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
        std::stack<T>     st;
        std::vector<bool> visited(m_nodes, false);
        st.emplace(0);

        while (!st.empty()) {
            T node = st.top();
            st.pop();

            if (!visited[node]) {
                visited[node] = true;
                f(node);
            }
            for (auto& n : m_adjList[node]) {
                st.emplace(n);
            }
        }
    }

    template <typename F>
    void BFS(T source, F&& f) {
        std::queue<T>     Q;
        std::vector<bool> visited(m_nodes, false);
        Q.emplace(source);

        while (!Q.empty()) {
            T node = Q.front();
            Q.pop();

            if (visited[node] == false) {
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

    void printAllPath(T source, T destination) {
        using Path  = std::vector<T>;
        using Paths = std::vector<Path>;
        Paths paths;

        std::queue<Path> q;
        q.emplace(Path(1, source));

        while (!q.empty()) {
            auto path = std::move(q.front());
            q.pop();

            T node = path.back();
            if (node == destination) {
                paths.emplace_back(std::move(path));
                continue;
            }

            for (auto& n : m_adjList[node]) {
                Path p{path.begin(), path.end()};
                p.emplace_back(n);
                q.emplace(std::move(p));
            }
        }

        for (auto& path : paths) {
            for (auto& n : path) {
                std::cout << n << ", ";
            }
            std::cout << "\n";
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
