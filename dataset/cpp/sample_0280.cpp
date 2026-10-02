#include <vector>

class Grid {
public:
    Grid(int size) : size(size), data(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_data(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                new_data[i][j] = _calculate_next_state(i, j);
            }
        }
        data = new_data;
    }

private:
    int _calculate_next_state(int i, int j) {
        std::vector<int> neighbors = _get_neighbors(i, j);
        int alive_count = 0;
        for (int neighbor : neighbors) {
            alive_count += neighbor;
        }
        if (data[i][j] == 1) {
            return alive_count == 2 || alive_count == 3 ? 1 : 0;
        } else {
            return alive_count == 3 ? 1 : 0;
        }
    }

    std::vector<int> _get_neighbors(int i, int j) {
        std::vector<int> neighbors;
        for (int x = std::max(0, i - 1); x < std::min(size, i + 2); ++x) {
            for (int y = std::max(0, j - 1); y < std::min(size, j + 2); ++y) {
                if (x != i || y != j) {
                    neighbors.push_back(data[x][y]);
                }
            }
        }
        return neighbors;
    }

    int size;
    std::vector<std::vector<int>> data;
};

void main() {
    int grid_size = 10;
    Grid grid(grid_size);
    int steps = 50;
    for (int _ = 0; _ < steps; ++_) {
        grid.update();
    }
}