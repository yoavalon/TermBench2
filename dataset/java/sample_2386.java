public class sample_2386 {

    static class FluidSimulator {
        double[][] grid;
        int size;

        FluidSimulator(int size) {
            this.size = size;
            this.grid = new double[size][size];
        }

        void update() {
            double[][] new_grid = new double[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_grid[i][j] = grid[i][j] + calculate_flow(i, j);
                }
            }
            grid = new_grid;
        }

        double calculate_flow(int x, int y) {
            double flow = 0.0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int nx = x + dx;
                    int ny = y + dy;
                    if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                        flow += grid[nx][ny] * 0.1;
                    }
                }
            }
            return flow;
        }
    }

    static class FluidController {
        FluidSimulator simulator;

        FluidController(FluidSimulator simulator) {
            this.simulator = simulator;
        }

        void run() {
            while (true) {
                simulator.update();
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        FluidSimulator simulator = new FluidSimulator(size);
        FluidController controller = new FluidController(simulator);
        controller.run();
    }
}