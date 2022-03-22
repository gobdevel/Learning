#include "DirectedGraph.h"
#include "DisjointSet.h"
#include "Graph.h"
#include "KruskalSpanningTree.h"
#include "PrimsSpanningTree.h"
#include "UndirectedGraph.h"
#include "gtest/gtest.h"

/**
  0 => 3 , 4
  1 => 2
  2 => 3
*/
TEST(DisjointSet, Basic) {
    DisjointSet set(5);
    EXPECT_EQ(set.getSetCounts(), 5);
    EXPECT_FALSE(set.isConnected(0, 3));
    EXPECT_EQ(set.find(4), 4);

    set.setUnion(0, 3);
    set.setUnion(0, 4);
    set.setUnion(1, 2);
    set.setUnion(2, 3);
    EXPECT_TRUE(set.isConnected(0, 3));
    EXPECT_TRUE(set.isConnected(0, 1));
    EXPECT_EQ(set.getSetCounts(), 1);
}

decltype(auto) getSampleUndirectedGraph() {
    UndirectedGraph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 1);
    return g;
}

TEST(UnDirectedGraph, BFS) {
    auto g = getSampleUndirectedGraph();

    Vertices<int> results, answer{0, 1, 2, 3, 4};
    g.BFS(0, [&results](auto& vertex) { results.emplace_back(vertex); });
    EXPECT_EQ(results.size(), 5);
    std::sort(results.begin(), results.end());
    EXPECT_EQ(results, answer);

    EXPECT_TRUE(g.isPathExists(0, 3));
    EXPECT_FALSE(g.isPathExists(0, 32));
}

TEST(UnDirectedGraph, DFS) {
    auto g = getSampleUndirectedGraph();

    Vertices<int> results, answer{0, 1, 2, 3, 4};
    g.DFS(0, [&results](auto& vertex) { results.emplace_back(vertex); });
    EXPECT_EQ(results.size(), 5);
    std::sort(results.begin(), results.end());
    EXPECT_EQ(results, answer);
}

decltype(auto) getSampleDirectedGraph() {
    DirectedGraph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    return g;
}

decltype(auto) getSampleDirectedCycleGraph() {
    DirectedGraph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    return g;
}

TEST(DirectedGraph, BFS) {
    auto g = getSampleDirectedGraph();

    Vertices<int> results, answer{0, 1, 2, 3, 4};
    g.BFS(0, [&results](auto& vertex) {
        results.emplace_back(vertex);
        return true;
    });
    EXPECT_EQ(results.size(), 5);
    std::sort(results.begin(), results.end());
    EXPECT_EQ(results, answer);

    EXPECT_TRUE(g.isPathExists(0, 3));
    EXPECT_FALSE(g.isPathExists(0, 32));
}

TEST(DirectedGraph, DFS) {
    auto g = getSampleDirectedGraph();

    Vertices<int> results, answer{0, 1, 2, 3, 4};
    g.DFS(0, [&results](auto& vertex) {
        results.emplace_back(vertex);
        return true;
    });
    EXPECT_EQ(results.size(), 5);
    std::sort(results.begin(), results.end());
    EXPECT_EQ(results, answer);
}

TEST(DirectedGraph, BFS_Cycle) {
    auto g = getSampleDirectedCycleGraph();

    Vertices<int> results, answer{0, 1, 2, 3, 4};
    g.BFS(0, [&results](auto& vertex) {
        results.emplace_back(vertex);
        return true;
    });
    EXPECT_EQ(results.size(), 5);
    std::sort(results.begin(), results.end());
    EXPECT_EQ(results, answer);

    EXPECT_TRUE(g.isPathExists(0, 3));
    EXPECT_FALSE(g.isPathExists(0, 32));
}

TEST(DirectedGraph, DFS_Cycle) {
    auto g = getSampleDirectedCycleGraph();

    Vertices<int> results, answer{0, 1, 2, 3, 4};
    g.DFS(0, [&results](auto& vertex) {
        results.emplace_back(vertex);
        return true;
    });
    EXPECT_EQ(results.size(), 5);
    std::sort(results.begin(), results.end());
    EXPECT_EQ(results, answer);
}

TEST(DirectedGraph, BFS_All_Path) {
    auto g      = getSampleDirectedGraph();
    using Path  = Path<int>;
    using Paths = Paths<int>;

    Paths results, answer;

    answer.emplace_back(Path{0, 1, 4});
    answer.emplace_back(Path{0, 1, 3, 4});
    answer.emplace_back(Path{0, 1, 2, 3, 4});
    answer.emplace_back(Path{0, 2, 3, 4});

    results = g.getAllPaths(0, 4);

    /**
      for (auto& res : results) {
          for (auto& r : res) {
              std::cout << r << "=>";
          }
          std::cout << "\n";
      }
      */
    EXPECT_EQ(results.size(), answer.size());
}

AdjacancyMatrix<int> getSampleUndirectedWeightedGraph() {
    AdjacancyMatrixBuilder<int> g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 1, 9);
    return g.getAdjacancymatrix();
}

TEST(MST, Kruskal) {
    auto g = getSampleUndirectedWeightedGraph();

    KruskalMst<int> k;

    auto edges = k.getMst(g);
    EXPECT_EQ(edges.size(), 4);

    auto sum = 0;
    for (auto& e : edges) {
        sum += e.weight;
    }
    EXPECT_EQ(sum, 8);
}

TEST(MST, Prims) {
    auto g = getSampleUndirectedWeightedGraph();

    PrimsMst<int> p;

    auto edges = p.getMst(g);
    EXPECT_EQ(edges.size(), 4);

    auto sum = 0;
    for (auto& e : edges) {
        sum += e.weight;
    }
    EXPECT_EQ(sum, 8);
}

#if 0
#include <iostream>

#include "Graph.h"
#include "GraphTraversal.h"
#include "KruskalSpanningTree.h"
#include "PrimsSpanningTree.h"

void testBfsUndirected() {
    AdjacancyListBuilder<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 1);

    std::cout << "========== BFS UNDIRECTED TRAVERSAL ===============\n";
    BFSUndirected(g.getAdjacancyList(),
                  [](const auto& vertex) { std::cout << vertex << ", "; });
    std::cout << "\n";
}

void testBfsDirectedWithoutCycle() {
    AdjacancyListBuilder<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout
        << "========== BFS DIRECTED WITHOUT CYCLE TRAVERSAL ===============\n";
    BFSDirectedWithoutCycle(g.getAdjacancyList(), [](const auto& vertex) {
        std::cout << vertex << ", ";
    });
    std::cout << "\n";
}

void testBfsDirectedWithCycle() {
    AdjacancyListBuilder<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 4);

    std::cout
        << "========== BFS DIRECTED WITH CYCLE TRAVERSAL ===============\n";
    BFSDirectedWithCycle(g.getAdjacancyList(), [](const auto& vertex) {
        std::cout << vertex << ", ";
    });
    std::cout << "\n";
}

void testAllPathDirectedWithoutCycle() {
    AdjacancyListBuilder<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout
        << "========== ALL PATH DIRECTED WITHOUT CYCLE TRAVERSAL =======\n";
    auto paths = AllPathDirectedWithoutCycle(g.getAdjacancyList(), 0, 4);
    for (const auto& path : paths) {
        for (const auto& v : path) {
            std::cout << v << ", ";
        }
        std::cout << "\n";
    }
}

void testAllPathDirectedWithCycle() {
    AdjacancyListBuilder<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 4);

    std::cout << "========== ALL PATH DIRECTED WITH CYCLE TRAVERSAL =======\n";
    auto paths = AllPathDirectedWithCycle(g.getAdjacancyList(), 0, 4);
    for (const auto& path : paths) {
        for (const auto& v : path) {
            std::cout << v << ", ";
        }
        std::cout << "\n";
    }
}

void testKruskalMst() {
    std::cout << "========== KRUSKAL MST ===============\n";
    AdjacancyMatrixBuilder<int> g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 1, 9);

    auto& adjMatrix = g.getAdjacancymatrix();
    /*
    for (auto& i : adjMatrix) {
        for (auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    */
    KruskalMst<int> kMst;
    auto            mst = kMst.getMst(adjMatrix);

    for (auto& e : mst) {
        std::cout << e.src << ", " << e.dst << ", " << e.weight << "\n";
    }
}

void testPrimsMst() {
    std::cout << "========== PRIMS MST ===============\n";
    AdjacancyMatrixBuilder<int> g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 9);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 1, 9);
    auto& adjMatrix = g.getAdjacancymatrix();
    /*
    for (auto& i : adjMatrix) {
        for (auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    */
    PrimsMst<int> pMst;
    auto          mst = pMst.getMst(adjMatrix);

    for (auto& e : mst) {
        std::cout << e.src << ", " << e.dst << ", " << e.weight << "\n";
    }
}

/**
int main() {
    testBfsUndirected();
    testBfsDirectedWithoutCycle();
    testBfsDirectedWithCycle();
    testAllPathDirectedWithoutCycle();
    testAllPathDirectedWithCycle();
    testKruskalMst();
    testPrimsMst();
}
*/
#endif
