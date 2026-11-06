#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <stack>

template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    inline bool operator<(const Edge<T>& e) const {
        return this->weight < e.weight;
    }

    inline bool operator>(const Edge<T>& e) const {
        return this->weight > e.weight;
    }
};

template <typename T>
class Graph {
public:
    Graph(size_t N) : V(N) {}

    size_t vertices() const {
        return V;
    }

    std::vector<Edge<T>> edges() const {
        return edge_list;
    }

    void add_edge(const Edge<T>& edge) {
        edge_list.push_back(edge);
    }

    std::vector<Edge<T>> outgoing_edges(size_t vertex) const {
        std::vector<Edge<T>> result;

        for (const auto& edge : edge_list) {
            if (edge.src == vertex) {
                result.push_back(edge);
            }
        }

        return result;
    }

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

template <typename T>
auto depth_first_search(const Graph<T>& G, size_t dest)
{
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    stack.push(1);

    while (!stack.empty()) {
        auto current_vertex = stack.top();
        stack.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto e : G.outgoing_edges(current_vertex)) {
                if (visited.find(e.dest) == visited.end()) {
                    stack.push(e.dest);
                }
            }
        }
    }

    return visit_order;
}

template <typename T>
Graph<T> create_reference_graph()
{
    Graph<T> G(9);

    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 0}, {5, 0}};
    edges[2] = {{1, 0}, {5, 0}, {4, 0}};
    edges[3] = {{4, 0}, {7, 0}};
    edges[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edges[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edges[6] = {{4, 0}, {7, 0}, {8, 0}};
    edges[7] = {{3, 0}, {6, 0}};
    edges[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (auto& i : edges) {
        for (auto& j : i.second) {
            G.add_edge(Edge<T>{i.first, j.first, j.second});
        }
    }

    return G;
}

int main()
{
    auto G = create_reference_graph<unsigned>();

    std::cout << "DFS Order of vertices:\n";

    auto dfs_visit_order = depth_first_search(G, 1);

    for (auto v : dfs_visit_order) {
        std::cout << v << std::endl;
    }

    return 0;
}