#include <vector>
#include <cstdlib>
#include <ctime>

class Grid {
public:
    int size;
    std::vector<std::vector<int>> state;

    Grid(int size, std::vector<std::vector<int>> initial_state) {
        this->size = size;
        this->state = initial_state;
    }

    void update() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = count_neighbors(i, j);
                if (state[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                    new_state[i][j] = 1;
                } else if (state[i][j] == 0 && neighbors == 3) {
                    new_state[i][j] = 1;
                }
            }
        }
        state = new_state;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); i++) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); j++) {
                if ((i != x || j != y) && state[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
};

std::vector<std::vector<int>> generate_initial_state(int size, double density) {
    std::vector<std::vector<int>> initial_state(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (static_cast<double>(rand()) / RAND_MAX < density) {
                initial_state[i][j] = 1;
            }
        }
    }
    return initial_state;
}

int main() {
    srand(time(0));
    int size = 100;
    double density = 0.2;
    Grid grid(size, generate_initial_state(size, density));
    while (true) {
        grid.update();
    }
    return 0;
}