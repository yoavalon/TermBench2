import java.util.Arrays;
import java.util.function.Function;

public class sample_0967 {
    static int[][] cellular_automata(int[][] grid, Function<int[], Integer> rule) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int[] neighbors = new int[8];
                int index = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x != 0 || y != 0) {
                            neighbors[index++] = grid[(i + x) % grid.length][(j + y) % grid[0].length];
                        }
                    }
                }
                Arrays.sort(neighbors);
                new_grid[i][j] = rule.apply(neighbors);
            }
        }
        return cellular_automata(new_grid, rule);
    }

    public static void main(String[] args) {
        int[][] initial_grid = new int[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                initial_grid[i][j] = i == j ? 1 : 0;
            }
        }
        Function<int[], Integer> rule = n -> Arrays.stream(n).sum() == 3 ? 1 : 0;
        cellular_automata(initial_grid, rule);
    }
}