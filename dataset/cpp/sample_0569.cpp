#include <vector>

class Grid {
public:
    Grid(int size) : size(size), state(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<int> neighbors = get_neighbors(i, j);
                int alive_neighbors = 0;
                for (int neighbor : neighbors) {
                    alive_neighbors += neighbor;
                }
                if (state[i][j] == 1) {
                    new_state[i][j] = (2 <= alive_neighbors && alive_neighbors <= 3) ? 1 : 0;
                } else {
                    new_state[i][j] = (alive_neighbors == 3) ? 1 : 0;
                }
            }
        }
        state = new_state;
    }

    std::vector<int> get_neighbors(int x, int y) {
        std::vector<int> neighbors;
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if (i != x || j != y) {
                    neighbors.push_back(state[i][j]);
                }
            }
        }
        return neighbors;
private:
    int size;
    std::vector<std::vector<int>> state;
};

class Simulation {
public:
    Simulation(int grid_size) : grid(grid_size), iteration(0) {}

    void run() {
        while (true) {
            grid.update();
            ++iteration;
        }
    }
private:
    Grid grid;
    int iteration;
};

int main() {
    Simulation sim(10);
    sim.run();
    return 0;
}