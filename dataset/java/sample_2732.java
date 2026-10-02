public class sample_2732 {
    public static void simulate(int[][] grid, int[] rules) {
        while (true) {
            int[][] new_grid = new int[grid.length][grid[0].length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    int[] neighbors = {
                        (i - 1 >= 0 && j - 1 >= 0) ? grid[i - 1][j - 1] : 0,
                        (i - 1 >= 0) ? grid[i - 1][j] : 0,
                        (i - 1 >= 0 && j + 1 < grid[0].length) ? grid[i - 1][j + 1] : 0,
                        (j - 1 >= 0) ? grid[i][j - 1] : 0,
                        (j + 1 < grid[0].length) ? grid[i][j + 1] : 0,
                        (i + 1 < grid.length && j - 1 >= 0) ? grid[i + 1][j - 1] : 0,
                        (i + 1 < grid.length) ? grid[i + 1][j] : 0,
                        (i + 1 < grid.length && j + 1 < grid[0].length) ? grid[i + 1][j + 1] : 0
                    };
                    int sum = 0;
                    for (int neighbor : neighbors) {
                        sum += neighbor;
                    }
                    new_grid[i][j] = rules[sum];
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        int[][] initial_grid = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
        int[] transition_rules = {0, 1, 1, 1, 0, 0, 0, 0, 0};
        simulate(initial_grid, transition_rules);
    }
}