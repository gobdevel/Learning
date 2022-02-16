#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <utility>
#include <vector>

template <typename T = int>
using Vertex = T;

template <typename T = int>
using Vertices = std::vector<Vertex<T>>;

template <typename T = int>
struct Edge {
    template <typename T1, typename T2, typename W>
    Edge(T1&& s, T2&& d, W&& w)
        : src(std::forward<T1>(s)),
          dst(std::forward<T2>(d)),
          weight(std::forward<W>(w)) {}

    Vertex<T> src;
    Vertex<T> dst;
    int       weight;

    friend bool operator<(const Edge& left, const Edge& right) {
        return (left.weight > right.weight);  // Piority Queue work opposite
    }
};

template <typename T>
using Edges = std::vector<Edge<T>>;

template <typename T>
using Path = std::vector<Vertex<T>>;

template <typename T>
using Paths = std::vector<Path<T>>;

template <typename T>
using AdjacancyList = std::vector<std::vector<Vertex<T>>>;

template <typename T>
using AdjacancyMatrix = std::vector<std::vector<Vertex<T>>>;

/**
 * Class Adjacancy Builder to build an Adjacancy List
 */

template <typename T>
class AdjacancyListBuilder {
public:
    explicit AdjacancyListBuilder(std::size_t maxVertices)
        : m_size(maxVertices), m_adjList(m_size, std::vector<T>()) {}

    template <typename V>
    void addEdge(V&& src, V&& dst) {
        m_adjList[src].emplace_back(dst);
    }

    AdjacancyList<T>& getAdjacancyList() { return m_adjList; }

private:
    std::size_t      m_size;
    AdjacancyList<T> m_adjList;
};

/**
 * Class Adjacancy Builder to build an Adjacancy List
 */

template <typename T>
class AdjacancyMatrixBuilder {
public:
    explicit AdjacancyMatrixBuilder(std::size_t maxVertices)
        : m_size(maxVertices), m_adjMatrix(m_size, std::vector<T>(m_size, 0)) {}

    template <typename V>
    void addEdge(V&& src, V&& dst, int weight) {
        m_adjMatrix[src][dst] = weight;
    }

    AdjacancyMatrix<T>& getAdjacancymatrix() { return m_adjMatrix; }

private:
    std::size_t        m_size;
    AdjacancyMatrix<T> m_adjMatrix;
};
#endif
