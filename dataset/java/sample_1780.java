public class sample_1780 {
    private int[][] grid;

    public sample_1780(int size) {
        this.grid = new int[size][size];
    }

    public void update() {
        int[][] new_grid = new int[grid.length][grid.length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
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
        for (int i = Math.max(0, x - 1); i < Math.min(grid.length, x + 2); i++) {
            for (int j = Math.max(0, y - 1); j < Math.min(grid.length, y + 2); j++) {
                if ((i != x || j != y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int size = 10;
        sample_1780 ca = new sample_1780(size);
        ca.grid[1][1] = 1;
        ca.grid[2][2] = 1;
        ca.grid[2][3] = 1;
        ca.grid[3][1] = 1;
        ca.grid[3][2] = 1;
        while (true) {
            ca.update();
            for (int[] row : ca.grid) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}