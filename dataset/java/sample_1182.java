public class sample_1182 {
    static class Automata {
        int[][] grid;
        int size;

        public Automata(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        public void update() {
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

        public int count_neighbors(int x, int y) {
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

    public static void main(String[] args) {
        int size = 50;
        Automata automata = new Automata(size);
        automata.grid[25][25] = 1;
        automata.grid[26][25] = 1;
        automata.grid[27][25] = 1;
        while (true) {
            automata.update();
        }
    }
}