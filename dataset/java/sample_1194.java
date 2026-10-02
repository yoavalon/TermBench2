public class sample_1194 {
    class Automaton {
        int[][] grid;
        int size;

        Automaton(int size) {
            this.size = size;
            this.grid = new int[size][size];
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
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nx = x + i;
                    int ny = y + j;
                    if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                        count += grid[nx][ny];
                    }
                }
            }
            return count;
        }
    }

    void run_simulation(int size) {
        Automaton automaton = new Automaton(size);
        automaton.grid[1][1] = 1;
        automaton.grid[1][2] = 1;
        automaton.grid[2][1] = 1;
        automaton.grid[2][2] = 1;
        while (true) {
            automaton.update();
        }
    }

    public static void main(String[] args) {
        sample_1194 sample = new sample_1194();
        sample.run_simulation(5);
    }
}