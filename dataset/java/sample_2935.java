public class sample_2935 {

    class CellularAutomaton {
        int[][] grid;
        int size;

        CellularAutomaton(int size) {
            this.grid = new int[size][size];
            this.size = size;
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

    public static void main(String[] args) {
        int size = 10;
        sample_2935 sample = new sample_2935();
        CellularAutomaton ca = sample.new CellularAutomaton(size);
        while (true) {
            ca.update();
        }
    }
}