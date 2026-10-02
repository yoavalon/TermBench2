public class sample_2699 {

    class Automaton {
        int[][] grid;
        int size;

        Automaton(int grid_size) {
            this.grid = new int[grid_size][grid_size];
            this.size = grid_size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = grid[i][j];
                    }
                }
            }
            this.grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(size, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(size, y + 2); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }

    void simulate(Automaton automaton, int steps) {
        for (int _ = 0; _ < steps; _++) {
            automaton.update();
        }
    }

    public static void main(String[] args) {
        sample_2699 app = new sample_2699();
        int grid_size = 10;
        int steps = 50;
        Automaton automaton = app.new Automaton(grid_size);
        app.simulate(automaton, steps);
    }
}