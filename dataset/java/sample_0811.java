import java.util.Arrays;

public class sample_0811 {
    class FluidSimulator {
        int[][] grid;
        int steps;
        int step_count;

        public FluidSimulator(int grid_size, int steps) {
            this.grid = new int[grid_size][grid_size];
            this.steps = steps;
            this.step_count = 0;
        }

        public void update() {
            int[][] new_grid = new int[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    } else {
                        new_grid[i][j] = grid[i][j];
                    }
                }
            }
            this.grid = new_grid;
            this.step_count += 1;
        }

        public int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = x - 1; i < x + 2; i++) {
                for (int j = y - 1; j < y + 2; j++) {
                    if ((i != x || j != y) && 0 <= i && i < grid.length && 0 <= j && j < grid[i].length) {
                        count += grid[i][j];
                    }
                }
            }
            return count;
        }

        public void run() {
            if (step_count < steps) {
                update();
                run();
            }
        }
    }

    public static void main(String[] args) {
        sample_0811 sample = new sample_0811();
        FluidSimulator sim = sample.new FluidSimulator(10, 100);
        sim.run();
        for (int[] row : sim.grid) {
            System.out.println(Arrays.toString(row));
        }
    }
}