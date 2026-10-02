#include <vector>

class FluidSimulator {
public:
    FluidSimulator(int size) : size(size) {
        grid.resize(size, std::vector<double>(size, 0.0));
    }

    void update() {
        std::vector<std::vector<double>> new_grid(size, std::vector<double>(size, 0.0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                new_grid[i][j] = grid[i][j] + calculate_flow(i, j);
            }
        }
        grid = new_grid;
    }

    double calculate_flow(int x, int y) {
        double flow = 0.0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                    flow += grid[nx][ny] * 0.1;
                }
            }
        }
        return flow;
    }

private:
    std::vector<std::vector<double>> grid;
    int size;
};

class FluidController {
public:
    FluidController(FluidSimulator& simulator) : simulator(simulator) {}

    void run() {
        while (true) {
            simulator.update();
        }
    }

private:
    FluidSimulator& simulator;
};

int main() {
    int size = 10;
    FluidSimulator simulator(size);
    FluidController controller(simulator);
    controller.run();
    return 0;
}