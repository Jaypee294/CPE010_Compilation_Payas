#include <iostream>

struct adjNode {
    int val;
    int cost;
    adjNode* next;
};

struct graphEdge {
    int start_ver;
    int end_ver;
    int weight;
};

class DiaGraph {
private:
    int N;

    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;

        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;

        return newNode;
    }

public:
    adjNode** head;

    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;

        head = new adjNode*[N];

        for (int i = 0; i < N; i++) {
            head[i] = nullptr;
        }

        for (int i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

            adjNode* newNode =
                getAdjListNode(end_ver, weight, head[start_ver]);

            head[start_ver] = newNode;
        }
    }

    ~DiaGraph() {
        for (int i = 0; i < N; i++) {
            adjNode* current = head[i];

            while (current != nullptr) {
                adjNode* temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] head;
    }

    void display_AdjList(adjNode* ptr, int i) {
        while (ptr != nullptr) {
            std::cout << "(" << i << ", "
                      << ptr->val << ", "
                      << ptr->cost << ") ";

            ptr = ptr->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    graphEdge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    int N = 6;

    int n = sizeof(edges) / sizeof(edges[0]);

    DiaGraph diagraph(edges, n, N);

    std::cout << "Graph adjacency list\n";
    std::cout << "(start_vertex, end_vertex, weight):\n";

    for (int i = 0; i < N; i++) {
        diagraph.display_AdjList(diagraph.head[i], i);
    }

    return 0;
}