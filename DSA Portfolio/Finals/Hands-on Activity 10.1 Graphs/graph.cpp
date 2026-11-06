#include <iostream>
#include <vector>
#include <utility>

class Graph {
private:
    std::vector<int> vertices;
    std::vector<std::pair<int, int>> edges;

public:
    // Add a vertex
    void addVertex(int vertex) {
        vertices.push_back(vertex);
    }

    // Add an edge
    void addEdge(int vertex1, int vertex2) {
        edges.push_back({vertex1, vertex2});
    }

    // Display the graph
    void displayGraph() {
        std::cout << "Vertices: ";

        for (int vertex : vertices) {
            std::cout << vertex << " ";
        }

        std::cout << "\nEdges:\n";

        for (const auto& edge : edges) {
            std::cout << edge.first << " - " << edge.second << std::endl;
        }
    }
};

int main() {
    Graph graph;

    // Add vertices
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    // Add edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    // Display graph
    graph.displayGraph();

    return 0;
}