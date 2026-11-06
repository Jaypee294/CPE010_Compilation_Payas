#include <iostream>

int main() {
    char vertices[] = {'A', 'B', 'C', 'D', 'E'};

    int matrix[5][5] = {
        {0, 4, 3, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0}
    };

    std::cout << "Weighted Directed Adjacency Matrix:\n\n";

    std::cout << "  ";
    for (int i = 0; i < 5; i++) {
        std::cout << vertices[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << vertices[i] << " ";

        for (int j = 0; j < 5; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}