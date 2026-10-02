#include <iostream>
#include <vector>

class Grid {
public:
    Grid(int size) : size(size), state(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (state[i][j] == 0) {
                    if (neighbors == 3) {
                        new_state[i][j] = 1;
                    }
                } else if (neighbors == 2 || neighbors == 3) {
                    new_state[i][j] = 1;
                }
            }
        }
        state = new_state;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if ((i != x || j != y) && state[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    
private:
    int size;
    std::vector<std::vector<int>> state;
};

void display(const Grid& grid) {
    for (const auto& row : grid.state) {
        for (int cell : row) {
            std::cout << (cell == 1 ? 'O' : '.');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int size = 50;
    Grid grid(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid.state[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
    }
    while (true) {
        display(grid);
        grid.update();
    }
    return 0;
}