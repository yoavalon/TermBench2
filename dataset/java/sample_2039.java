import java.util.Random;

public class sample_2039 {

    static class CellularAutomaton {
        int[][] grid;

        CellularAutomaton(int size) {
            grid = new int[size][size];
            Random rand = new Random();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = rand.nextInt(2);
                }
            }
        }

        void update() {
            int[][] newGrid = new int[grid.length][grid[0].length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    int sum = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                                sum += grid[ni][nj];
                            }
                        }
                    }
                    newGrid[i][j] = (sum == 3) || (grid[i][j] == 1 && sum == 2) ? 1 : 0;
                }
            }
            grid = newGrid;
        }

        int[][] get_state() {
            return grid;
        }
    }

    static class FluidSimulator {
        int size;
        int steps;
        CellularAutomaton ca;

        FluidSimulator(int size, int steps) {
            this.size = size;
            this.steps = steps;
            ca = new CellularAutomaton(size);
        }

        void simulate() {
            for (int i = 0; i < steps; i++) {
                ca.update();
            }
        }

        int[][] get_result() {
            return ca.get_state();
        }
    }

    public static void main(String[] args) {
        int size = 100;
        int steps = 1000;
        FluidSimulator simulator = new FluidSimulator(size, steps);
        simulator.simulate();
        int[][] result = simulator.get_result();
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}