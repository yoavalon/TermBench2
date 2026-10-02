public class sample_2577 {
    public static int[] update_grid(int[] grid, Rule rule) {
        int size = grid.length;
        int[] new_grid = new int[size];
        for (int i = 0; i < size; i++) {
            int left = grid[(i - 1 + size) % size];
            int right = grid[(i + 1) % size];
            new_grid[i] = rule.apply(left, grid[i], right);
        }
        return new_grid;
    }

    public static int[] cellular_automaton(int steps, int[] initial_state, Rule rule) {
        int[] current_state = initial_state;
        for (int _ = 0; _ < steps; _++) {
            current_state = update_grid(current_state, rule);
        }
        return current_state;
    }

    public static int rule_conway(int left, int center, int right) {
        int neighbor_count = left + center + right;
        if (center == 1) {
            return neighbor_count == 2 || neighbor_count == 3 ? 1 : 0;
        } else {
            return neighbor_count == 3 ? 1 : 0;
        }
    }

    public static void main(String[] args) {
        int[] initial_state = {0, 1, 0, 1, 1, 0, 1, 0};
        int steps = 5;
        int[] final_state = cellular_automaton(steps, initial_state, new Rule() {
            @Override
            public int apply(int left, int center, int right) {
                return rule_conway(left, center, right);
            }
        });
        for (int i : final_state) {
            System.out.print(i + " ");
        }
    }

    interface Rule {
        int apply(int left, int center, int right);
    }
}