public class sample_0208 {
    public static class AutomataGrid {
        private int[][] grid;

        public AutomataGrid(int size) {
            this.grid = new int[size][size];
        }

        public void update() {
            int[][] new_grid = new int[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 1) {
                        if (neighbors < 2 || neighbors > 3) {
                            new_grid[i][j] = 0;
                        } else {
                            new_grid[i][j] = 1;
                        }
                    } else if (neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            this.grid = new_grid;
        }

        public int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(grid.length, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(grid[i].length, y + 2); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count += 1;
                    }
                }
            }
            return count;
        }
    }

    public static void boundary_conditions(AutomataGrid grid, int step_limit) {
        int steps = 0;
        while (steps < step_limit) {
            grid.update();
            steps += 1;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int step_limit = 100;
        AutomataGrid automata = new AutomataGrid(size);
        boundary_conditions(automata, step_limit);
    }
}