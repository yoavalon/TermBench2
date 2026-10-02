public class sample_1712 {
    class CellularAutomata {
        int[][] grid;
        int size;

        CellularAutomata(int size) {
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
            this.grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(x + 2, size); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(y + 2, size); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }

    public static void main(String[] args) {
        sample_1712 sample = new sample_1712();
        CellularAutomata ca = sample.new CellularAutomata(10);
        ca.grid[5][5] = 1;
        ca.grid[5][6] = 1;
        ca.grid[6][5] = 1;
        ca.grid[6][6] = 1;
        while (true) {
            ca.update();
        }
    }
}