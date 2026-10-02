#include <iostream>
#include <vector>

class Automata {
public:
    Automata(int grid_size) : size(grid_size), grid(grid_size, std::vector<int>(grid_size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < size && y >= 0 && y < size && !(x == i && y == j)) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (grid[i][j] == 1) {
                    new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                } else {
                    new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        grid = new_grid;
    }

    void display() {
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell ? '#' : ' ');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    int size;
    std::vector<std::vector<int>> grid;
};

void initialize(Automata& grid) {
    for (int i = 0; i < grid.size; ++i) {
        for (int j = 0; j < grid.size; ++j) {
            if (i == j || i == grid.size - j - 1) {
                grid.grid[i][j] = 1;
            }
        }
    }
}

int main() {
    int size = 10;
    Automata automata(size);
    initialize(automata);
    while (true) {
        automata.display();
        automata.update();
    }
    return 0;
}