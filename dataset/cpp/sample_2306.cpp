#include <vector>
#include <cstdlib>
#include <ctime>

class Automaton {
public:
    int size;
    std::vector<std::vector<int>> state;

    Automaton(int size, const std::vector<std::vector<int>>& initial_state) {
        this->size = size;
        this->state = initial_state;
    }

    void update() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (state[i][j] == 1) {
                    new_state[i][j] = (2 <= neighbors && neighbors <= 3) ? 1 : 0;
                } else {
                    new_state[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        state = new_state;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if ((0 <= i && i < size && 0 <= j && j < size) && (i != x || j != y)) {
                    count += state[i][j];
                }
            }
        }
        return count;
};

std::vector<std::vector<int>> generate_initial_state(int size) {
    std::vector<std::vector<int>> initial_state(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            initial_state[i][j] = rand() % 2;
        }
    }
    return initial_state;
}

int main() {
    srand(time(0));
    int size = 10;
    std::vector<std::vector<int>> initial_state = generate_initial_state(size);
    Automaton automaton(size, initial_state);
    while (true) {
        automaton.update();
    }
    return 0;
}