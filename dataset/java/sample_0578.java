public class sample_0578 {
    class CellularAutomaton {
        int[][] grid;
        int rule;

        CellularAutomaton(int grid_size, int rule) {
            this.grid = new int[grid_size][grid_size];
            this.rule = rule;
        }

        void update_grid() {
            int[][] new_grid = new int[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    int state = grid[i][j];
                    int neighbors = count_neighbors(i, j);
                    int new_state = apply_rule(state, neighbors);
                    new_grid[i][j] = new_state;
                }
            }
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(grid.length, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(grid[i].length, y + 2); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }

        int apply_rule(int state, int neighbors) {
            if (rule == 1) {
                if (state == 0 && neighbors == 3) {
                    return 1;
                } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                    return 0;
                } else {
                    return state;
                }
            }
            return state;
        }
    }

    public static void main(String[] args) {
        sample_0578 obj = new sample_0578();
        CellularAutomaton automaton = obj.new CellularAutomaton(100, 1);
        while (true) {
            automaton.update_grid();
        }
    }
}