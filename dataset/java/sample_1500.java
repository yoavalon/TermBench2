import java.util.HashMap;
import java.util.Map;

public class sample_1500 {

    class AutomataSimulator {
        int[][] grid;
        Map<Integer, Map<Integer, Integer>> rule;
        int size;

        AutomataSimulator(int size, Map<Integer, Map<Integer, Integer>> rule) {
            this.grid = new int[size][size];
            this.rule = rule;
            this.size = size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int state = grid[i][j];
                    int neighbors = count_neighbors(i, j);
                    int new_state = apply_rule(state, neighbors);
                    new_grid[i][j] = new_state;
                }
            }
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if (i >= 0 && i < size && j >= 0 && j < size && !(i == x && j == y)) {
                        count += grid[i][j];
                    }
                }
            }
            return count;
        }

        int apply_rule(int state, int neighbors) {
            return rule.get(state).get(neighbors);
        }
    }

    public static void main(String[] args) {
        int size = 10;
        Map<Integer, Map<Integer, Integer>> rule = new HashMap<>();
        rule.put(0, Map.of(0, 0, 1, 1, 2, 1, 3, 1, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0));
        rule.put(1, Map.of(0, 0, 1, 0, 2, 0, 3, 1, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0));
        AutomataSimulator automata = new sample_1500().new AutomataSimulator(size, rule);
        for (int _ = 0; _ < 100; _++) {
            automata.update();
        }
        for (int[] row : automata.grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}