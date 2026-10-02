public class sample_2715 {
    public static int[][] cellular_automata(int rows, int cols, int steps) {
        int[][] grid = new int[rows][cols];
        for (int step = 0; step < steps; step++) {
            int[][] new_grid = new int[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int neighbors = 0;
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 && dy == 0) continue;
                            neighbors += grid[(i + dx + rows) % rows][(j + dy + cols) % cols];
                        }
                    }
                    new_grid[i][j] = neighbors == 3 ? 1 : grid[i][j];
                }
            }
            grid = new_grid;
        }
        return grid;
    }

    public static void main(String[] args) {
        while (true) {
            cellular_automata(10, 10, 100);
        }
    }
}