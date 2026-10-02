#include <vector>

class FluidGrid {
public:
    FluidGrid(int size) {
        grid.resize(size, std::vector<int>(size, 0));
        this->size = size;
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                new_grid[i][j] = calculate_next_state(i, j);
            }
        }
        grid = new_grid;
    }

    int calculate_next_state(int x, int y) {
        std::vector<int> neighbors = get_neighbors(x, y);
        int count = 0;
        for (int neighbor : neighbors) {
            count += neighbor;
        }
        if (grid[x][y] == 0) {
            return count > 2 ? 1 : 0;
        } else {
            return count == 2 || count == 3 ? 1 : 0;
        }
    }

    std::vector<int> get_neighbors(int x, int y) {
        std::vector<std::pair<int, int>> directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        std::vector<int> neighbors;
        for (const auto& [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors.push_back(grid[nx][ny]);
            } else {
                neighbors.push_back(0);
            }
        }
        return neighbors;
private:
    std::vector<std::vector<int>> grid;
    int size;
};

int main() {
    int size = 10;
    FluidGrid grid(size);
    while (true) {
        grid.update();
    }
    return 0;
}