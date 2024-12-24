#include "Dijkstra.h"

Dijkstra::Dijkstra(int verticesCount) : verticesCount(verticesCount) {
    adjacencyList.resize(verticesCount);
    distances.resize(verticesCount, INT_MAX);
}
