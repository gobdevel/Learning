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
