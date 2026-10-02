public class sample_2921 {
    static class Automaton {
        int[][] grid;
        Rule rule;
        int grid_size;

        Automaton(int grid_size, Rule rule) {
            this.grid = new int[grid_size][grid_size];
            this.rule = rule;
            this.grid_size = grid_size;
        }

        void set_initial_state(int[][] state) {
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    this.grid[i][j] = state[i][j];
                }
            }
        }

        void update() {
            int[][] new_grid = new int[grid_size][grid_size];
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    int[] neighbors = {
                        this.grid[(i - 1 + grid_size) % grid_size][(j - 1 + grid_size) % grid_size],
                        this.grid[(i - 1 + grid_size) % grid_size][j],
                        this.grid[(i - 1 + grid_size) % grid_size][(j + 1) % grid_size],
                        this.grid[i][(j - 1 + grid_size) % grid_size],
                        this.grid[i][(j + 1) % grid_size],
                        this.grid[(i + 1) % grid_size][(j - 1 + grid_size) % grid_size],
                        this.grid[(i + 1) % grid_size][j],
                        this.grid[(i + 1) % grid_size][(j + 1) % grid_size]
                    };
                    new_grid[i][j] = apply_rule(neighbors);
                }
            }
            this.grid = new_grid;
        }

        int apply_rule(int[] neighbors) {
            int sum = 0;
            for (int neighbor : neighbors) {
                sum += neighbor;
            }
            return rule.apply(sum);
        }
    }

    static class Rule {
        int threshold;

        Rule(int threshold) {
            this.threshold = threshold;
        }

        int apply(int count) {
            return count > threshold ? 1 : 0;
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        int[][] initial_state = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
        Rule rule = new Rule(3);
        Automaton automaton = new Automaton(grid_size, rule);
        automaton.set_initial_state(initial_state);
        while (true) {
            automaton.update();
        }
    }
}