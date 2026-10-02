public class sample_1471 {

    class Automaton {
        int[][] grid;
        int size;

        public Automaton(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        public void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 0) {
                        if (neighbors == 3) {
                            new_grid[i][j] = 1;
                        }
                    } else if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    }
                }
            }
            grid = new_grid;
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
                    if (0 <= ni && ni < size && 0 <= nj && nj < size) {
                        count += grid[ni][nj];
                    }
                }
            }
            return count;
        }
    }

    public static void main(String[] args) {
        sample_1471 sample = new sample_1471();
        Automaton automaton = sample.new Automaton(10);
        for (int _ = 0; _ < 50; _++) {
            automaton.update();
            boolean allZero = true;
            for (int i = 0; i < automaton.size; i++) {
                for (int j = 0; j < automaton.size; j++) {
                    if (automaton.grid[i][j] != 0) {
                        allZero = false;
                        break;
                    }
                }
                if (!allZero) {
                    break;
                }
            }
            if (allZero) {
                break;
            }
        }
    }
}