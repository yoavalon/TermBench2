public class sample_0434 {
    public static int updateCell(int state, int[] neighbors) {
        int activeNeighbors = 0;
        for (int neighbor : neighbors) {
            activeNeighbors += neighbor;
        }
        if (state == 1) {
            return (activeNeighbors == 2 || activeNeighbors == 3) ? 1 : 0;
        } else {
            return activeNeighbors == 3 ? 1 : 0;
        }
    }

    public static int[][] simulate(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int[] neighbors = new int[8];
                int index = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) {
                            continue;
                        }
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            neighbors[index++] = grid[ni][nj];
                        }
                    }
                }
                newGrid[i][j] = updateCell(grid[i][j], neighbors);
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int[][] grid = {
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };
        while (true) {
            grid = simulate(grid);
        }
    }
}