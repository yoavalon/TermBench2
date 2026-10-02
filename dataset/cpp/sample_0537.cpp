#include <iostream>
#include <vector>

class Grid {
public:
    std::vector<std::vector<int>> grid;
    int size;

    Grid(int size) : size(size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update(int (*rule)(int, const std::vector<int>&)) {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<int> neighbors = get_neighbors(i, j);
                new_grid[i][j] = rule(grid[i][j], neighbors);
            }
        }
        grid = new_grid;
    }

    std::vector<int> get_neighbors(int x, int y) {
        std::vector<std::pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        std::vector<int> neighbors;
        for (const auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors.push_back(grid[nx][ny]);
            }
        }
        return neighbors;
    }
};

class Automaton {
public:
    Grid grid;

    Automaton(Grid grid) : grid(grid) {}

    void run(int (*rule)(int, const std::vector<int>&), int steps) {
        for (int _ = 0; _ < steps; ++_) {
            grid.update(rule);
        }
    }
};

int simple_rule(int center, const std::vector<int>& neighbors) {
    int live_neighbors = 0;
    for (int neighbor : neighbors) {
        live_neighbors += neighbor;
    }
    if (center == 1) {
        return (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
    } else {
        return (live_neighbors == 3) ? 1 : 0;
    }
}

void main() {
    int grid_size = 10;
    Grid initial_grid(grid_size);
    initial_grid.grid[4][4] = 1;
    initial_grid.grid[5][5] = 1;
    initial_grid.grid[6][4] = 1;
    initial_grid.grid[5][3] = 1;
    initial_grid.grid[4][5] = 1;
    Automaton automaton(initial_grid);
    while (true) {
        automaton.run(simple_rule, 1);
    }
}

int main() {
    main();
    return 0;
}