import java.util.Arrays;

public class sample_2265 {
    public static void updateGrid(int[][] grid, int size) {
        int[][] newGrid = new int[size][size];
        for (int i = 1; i < size - 1; i++) {
            for (int j = 1; j < size - 1; j++) {
                int neighborsSum = 0;
                for (int ni = -1; ni <= 1; ni++) {
                    for (int nj = -1; nj <= 1; nj++) {
                        if (ni == 0 && nj == 0) continue;
                        neighborsSum += grid[i + ni][j + nj];
                    }
                }
                if (grid[i][j] == 0 && neighborsSum > 2) {
                    newGrid[i][j] = 1;
                } else if (grid[i][j] == 1 && (neighborsSum < 2 || neighborsSum > 3)) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = grid[i][j];
                }
            }
        }
        for (int i = 0; i < size; i++) {
            System.arraycopy(newGrid[i], 0, grid[i], 0, size);
        }
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        while (true) {
            updateGrid(grid, size);
        }
    }
}