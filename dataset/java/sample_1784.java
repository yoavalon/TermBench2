import java.util.Arrays;

class sample_1784 {

    class Automaton {
        int[][] grid;
        int size;

        Automaton(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
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

    int[][] run_simulation(int size, int steps) {
        Automaton automaton = new Automaton(size);
        for (int _ = 0; _ < steps; _++) {
            automaton.update();
        }
        return automaton.grid;
    }

    void main() {
        int size = 50;
        int steps = 1000;
        int[][] result = run_simulation(size, steps);
        for (int[] row : result) {
            System.out.println(Arrays.toString(row).replace("1", "#").replace("0", "."));
        }
    }

    public static void main(String[] args) {
        sample_1784 obj = new sample_1784();
        obj.main();
    }
}