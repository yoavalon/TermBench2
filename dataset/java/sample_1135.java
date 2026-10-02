public class sample_1135 {
    class Automaton {
        int[][] grid;

        public Automaton(int size) {
            this.grid = new int[size][size];
        }

        public void update() {
            int[][] new_grid = new int[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
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

        public int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int ni = x + i;
                    int nj = y + j;
                    if (0 <= ni && ni < grid.length && 0 <= nj && nj < grid[i].length) {
                        count += grid[ni][nj];
                    }
                }
            }
            return count;
        }
    }

    public static void main(String[] args) {
        int size = 50;
        sample_1135 sample = new sample_1135();
        Automaton automaton = sample.new Automaton(size);
        automaton.grid[size / 2][size / 2] = 1;
        automaton.update();
        while (true) {
            automaton.update();
        }
    }
}