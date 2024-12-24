#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <set>
#include <queue>
#include <climits>


class Dijkstra {
    public:
        Dijkstra(int verticesCount);

        void AddEdge(int fromVertex, int toVertex, int edgeWeight);

        void ComputeShortestPaths(int sourceVertex);

        int GetDistance(int destinationVertex) const;

        const std::vector<int>& GetDistances() const;

    private:
        int verticesCount;
        std::vector<std::vector<Edge>> adjacencyList;
        std::vector<int> distances;
};

#endif