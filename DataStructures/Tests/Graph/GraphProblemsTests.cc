#include "Graph.h"
//#include "GraphProblems.h"
#include "TopologicalSort.h"
#include "gtest/gtest.h"

using AdjList = AdjacancyList<int>;

AdjList getAdjList() {
    AdjacancyListBuilder<int> adj(10);
    adj.addEdge(0, 1);
    adj.addEdge(0, 2);
    adj.addEdge(1, 3);
    adj.addEdge(2, 3);
    adj.addEdge(3, 4);
    adj.addEdge(3, 5);
    adj.addEdge(3, 6);
    adj.addEdge(4, 7);
    adj.addEdge(6, 8);
    adj.addEdge(7, 9);
    return adj.getAdjacancyList();
}

TEST(GraphProblem, TopoSort) {
    AdjList          adj = getAdjList();
    std::vector<int> result, answer{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    result = TopoSort(adj);
    EXPECT_EQ(result, answer);
}
