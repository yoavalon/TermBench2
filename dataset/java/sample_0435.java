public class sample_0435 {
    public static int[][] update_grid(int[][] grid, java.util.function.BiFunction<java.util.List<Integer>, Integer, Integer> rule) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                java.util.List<Integer> neighbors = new java.util.ArrayList<>();
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (!(di == 0 && dj == 0)) {
                            neighbors.add(grid[(i + di) % grid.length][(j + dj) % grid[0].length]);
                        }
                    }
                }
                new_grid[i][j] = rule.apply(neighbors, grid[i][j]);
            }
        }
        return new_grid;
    }

    public static int[][] evolve(int[][] grid, java.util.function.BiFunction<java.util.List<Integer>, Integer, Integer> rule, int steps) {
        for (int _ = 0; _ < steps; _++) {
            grid = update_grid(grid, rule);
        }
        return grid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};

        java.util.function.BiFunction<java.util.List<Integer>, Integer, Integer> rule = (neighbors, cell) -> {
            int sum = 0;
            for (int neighbor : neighbors) {
                sum += neighbor;
            }
            return sum == 3 ? 1 : 0;
        };

        while (true) {
            grid = evolve(grid, rule, 1);
        }
    }
}