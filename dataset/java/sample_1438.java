import java.util.HashMap;
import java.util.Map;

public class sample_1438 {

    class CellularAutomaton {
        int grid_size;
        Map<String, int[]> rule;
        int[][] grid;

        CellularAutomaton(int grid_size, Map<String, int[]> rule) {
            this.grid_size = grid_size;
            this.rule = rule;
            this.grid = new int[grid_size][grid_size];
            this.grid[grid_size / 2][grid_size / 2] = 1;
        }

        void update() {
            int[][] new_grid = new int[grid_size][grid_size];
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    int neighbors = count_neighbors(i, j);
                    new_grid[i][j] = apply_rule(grid[i][j], neighbors);
                }
            }
            this.grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if (0 <= i && i < grid_size && 0 <= j && j < grid_size && !(i == x && j == y)) {
                        count += grid[i][j];
                    }
                }
            }
            return count;
        }

        int apply_rule(int cell, int neighbors) {
            if (cell == 1 && contains(rule.get("survive"), neighbors)) {
                return 1;
            } else if (cell == 0 && contains(rule.get("birth"), neighbors)) {
                return 1;
            }
            return 0;
        }

        boolean contains(int[] array, int value) {
            for (int num : array) {
                if (num == value) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        sample_1438 sample = new sample_1438();
        int size = 50;
        Map<String, int[]> rule = new HashMap<>();
        rule.put("survive", new int[]{2, 3});
        rule.put("birth", new int[]{3});
        CellularAutomaton ca = sample.new CellularAutomaton(size, rule);
        for (int _ = 0; _ < 100; _++) {
            ca.update();
        }
        for (int[] row : ca.grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}