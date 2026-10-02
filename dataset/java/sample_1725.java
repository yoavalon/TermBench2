public class sample_1725 {
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
                    } else {
                        new_grid[i][j] = 1;
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
                    int ni = x + i, nj = y + j;
                    if (0 <= ni && ni < size && 0 <= nj && nj < size) {
                        count += grid[ni][nj];
                    }
                }
            }
            return count;
        }
    }

    public static void display(int[][] grid) {
        for (int[] row : grid) {
            StringBuilder sb = new StringBuilder();
            for (int cell : row) {
                sb.append(cell == 1 ? '#' : ' ');
            }
            System.out.println(sb.toString());
        }
    }

    public static void main(String[] args) {
        int size = 10;
        sample_1725 sample = new sample_1725();
        Automaton automaton = sample.new Automaton(size);
        automaton.grid[5][5] = 1;
        automaton.grid[5][6] = 1;
        automaton.grid[6][5] = 1;
        automaton.grid[6][6] = 1;
        while (true) {
            display(automaton.grid);
            automaton.update();
        }
    }
}