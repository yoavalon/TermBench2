#include <vector>

class CellularAutomata {
public:
    CellularAutomata(int size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
        this->size = size;
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int state = grid[i][j];
                int neighbors = count_neighbors(i, j);
                if (state == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = state;
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if ((i != x || j != y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

private:
    std::vector<std::vector<int>> grid;
    int size;
};

class Simulation {
public:
    Simulation(int size) {
        automata = CellularAutomata(size);
        this->size = size;
    }

    void run() {
        while (true) {
            automata.update();
        }
    }

private:
    CellularAutomata automata;
    int size;
};

int main() {
    Simulation simulation(10);
    simulation.run();
    return 0;
}