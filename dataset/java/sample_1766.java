public class sample_1766 {

    public static void main(String[] args) {
        int grid_size = 10;
        RuleSet rules = new RuleSet();
        FluidSimulator simulator = new FluidSimulator(grid_size, rules);
        simulator.grid[4][4] = 1;
        simulator.grid[5][4] = 1;
        simulator.grid[4][5] = 1;
        while (true) {
            simulator.display();
            simulator.update();
        }
    }

    static class FluidSimulator {
        int[][] grid;
        RuleSet rules;

        public FluidSimulator(int grid_size, RuleSet rules) {
            this.grid = new int[grid_size][grid_size];
            this.rules = rules;
        }

        public void update() {
            int[][] new_grid = new int[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid.length; j++) {
                    new_grid[i][j] = rules.apply(grid, i, j);
                }
            }
            this.grid = new_grid;
        }

        public void display() {
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    static class RuleSet {
        public int apply(int[][] grid, int x, int y) {
            int neighbors = count_neighbors(grid, x, y);
            return neighbors == 2 ? 1 : 0;
        }

        public int count_neighbors(int[][] grid, int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(grid.length, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(grid.length, y + 2); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }
}