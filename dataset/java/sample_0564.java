public class sample_0564 {

    static class FluidSimulator {
        int[][] grid;
        int size;

        FluidSimulator(int grid_size) {
            this.size = grid_size;
            this.grid = new int[grid_size][grid_size];
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    this.grid[i][j] = 0;
                }
            }
        }

        void update() {
            int[][] new_grid = new int[this.size][this.size];
            for (int i = 0; i < this.size; i++) {
                for (int j = 0; j < this.size; j++) {
                    new_grid[i][j] = this.apply_rules(i, j);
                }
            }
            this.grid = new_grid;
        }

        int apply_rules(int x, int y) {
            int[] neighbors = this.get_neighbors(x, y);
            int count = 0;
            for (int neighbor : neighbors) {
                count += neighbor;
            }
            if (this.grid[x][y] == 1) {
                return count > 1 ? 1 : 0;
            } else {
                return count == 3 ? 1 : 0;
            }
        }

        int[] get_neighbors(int x, int y) {
            int[] directions = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
            int[] neighbors = new int[8];
            for (int i = 0; i < 8; i++) {
                int dx = directions[i * 2];
                int dy = directions[i * 2 + 1];
                int nx = (x + dx + this.size) % this.size;
                int ny = (y + dy + this.size) % this.size;
                neighbors[i] = this.grid[nx][ny];
            }
            return neighbors;
        }
    }

    static class BoundaryConditionApplier {
        FluidSimulator simulator;

        BoundaryConditionApplier(FluidSimulator simulator) {
            this.simulator = simulator;
        }

        void apply() {
            for (int i = 0; i < this.simulator.size; i++) {
                this.simulator.grid[i][0] = 1;
                this.simulator.grid[i][this.simulator.size - 1] = 1;
                this.simulator.grid[0][i] = 1;
                this.simulator.grid[this.simulator.size - 1][i] = 1;
            }
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        FluidSimulator simulator = new FluidSimulator(grid_size);
        BoundaryConditionApplier boundary_conditions = new BoundaryConditionApplier(simulator);
        while (true) {
            boundary_conditions.apply();
            simulator.update();
        }
    }
}