import java.util.Arrays;

public class sample_1227 {
    public static int[][] cellular_automata(int size, int steps) {
        int[][] grid = new int[size][size];
        for (int s = 0; s < steps; s++) {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = 0;
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                        }
                    }
                    neighbors -= grid[i][j];
                    new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0;
                }
            }
            grid = new_grid;
        }
        return grid;
    }

    public static void main(String[] args) {
        int[][] result = cellular_automata(10, 5);
        for (int[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}