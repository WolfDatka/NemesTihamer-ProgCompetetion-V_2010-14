#include "Main.h"

int main(int argc, char const *argv[]) {
    int cityCount;
    int courierCount;
    int startingPlace;

    /* Get info */ {
        std::string inputStr;
        std::cout << "Input the info(amountOfCities amountOfCouriers startingCity): ";
        std::getline(std::cin, inputStr);

        std::istringstream inputStrStream(inputStr);
        std::string word;
        int inputVals[3];

        for (int i = 0; i < 3; i++) {
            inputStrStream >> word;
            inputVals[i] = std::stoi(word);
        }

        cityCount = inputVals[0];
        courierCount = inputVals[1];
        startingPlace = inputVals[2];
    }

    Dijkstra graph(5);

    graph.AddEdge(0, 1, 10);
    graph.AddEdge(0, 2, 3);
    graph.AddEdge(1, 2, 1);
    graph.AddEdge(1, 3, 2);
    graph.AddEdge(2, 3, 9);
    graph.AddEdge(2, 4, 2);
    graph.AddEdge(3, 4, 6);

    graph.ComputeShortestPaths(0);

    for (int vertex = 0; vertex < 5; vertex++) {
        std::cout << "Distance from 0 to " << vertex << " is " << graph.GetDistance(vertex) << '\n';
    }

    std::cout << std::endl;

    return 0;
}
