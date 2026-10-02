#include <iostream>
#include <vector>

class Grid {
public:
    Grid(int size) : size(size), state(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = get_neighbors(i, j);
                if (state[i][j] == 0 && neighbors == 3) {
                    new_state[i][j] = 1;
                } else if (state[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_state[i][j] = 0;
                } else {
                    new_state[i][j] = state[i][j];
                }
            }
        }
        state = new_state;
    }

    int get_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(x + 2, size); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(y + 2, size); ++j) {
                if ((i, j) != (x, y) && state[i][j] == 1) {
                    count += 1;
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
            std::cout << (cell ? '*' : ' ');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int size = 10;
    Grid grid(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                grid.state[i][j] = 1;
            }
        }
    }
    while (true) {
        display(grid);
        grid.update();
    }
    return 0;
}