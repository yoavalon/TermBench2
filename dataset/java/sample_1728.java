public class sample_1728 {

    static class Automaton {
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
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int ni = x + i;
                    int nj = y + j;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        count += grid[ni][nj];
                    }
                }
            }
            return count;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        Automaton automaton = new Automaton(size);
        while (true) {
            automaton.update();
        }
    }
}