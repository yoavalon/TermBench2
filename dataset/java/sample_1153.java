import java.util.Random;

public class sample_1153 {
    public static void main(String[] args) {
        size = 50;
        automata = new CellAutomata(size);
        while (true) {
            automata.update_grid();
        }
    }

    static int size;
    static CellAutomata automata;

    static class CellAutomata {
        int grid_size;
        int[][] grid;

        CellAutomata(int grid_size) {
            this.grid_size = grid_size;
            this.grid = initialize_grid();
        }

        int[][] initialize_grid() {
            Random random = new Random();
            int[][] grid = new int[grid_size][grid_size];
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    grid[i][j] = random.nextInt(2);
                }
            }
            return grid;
        }

        void update_grid() {
            int[][] new_grid = new int[grid_size][grid_size];
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 1) {
                        if (neighbors == 2 || neighbors == 3) {
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
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int ni = (x + i + grid_size) % grid_size;
                    int nj = (y + j + grid_size) % grid_size;
                    count += grid[ni][nj];
                }
            }
            return count;
        }
    }
}