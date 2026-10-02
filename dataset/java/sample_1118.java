public class sample_1118 {
    static class Grid {
        int size;
        int[][] grid;

        Grid(int size) {
            this.size = size;
            this.grid = new int[size][size];
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 0) {
                        new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                    } else {
                        new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                    }
                }
            }
            this.grid = new_grid;
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

    static void display(Grid grid) {
        for (int[] row : grid.grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int size = 10;
        Grid grid = new Grid(size);
        while (true) {
            display(grid);
            grid.update();
        }
    }
}