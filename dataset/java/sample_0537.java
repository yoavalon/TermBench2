public class sample_0537 {

    static class Grid {
        int[][] grid;
        int size;

        Grid(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update(java.util.function.BiFunction<Integer, java.util.List<Integer>, Integer> rule) {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    java.util.List<Integer> neighbors = get_neighbors(i, j);
                    new_grid[i][j] = rule.apply(grid[i][j], neighbors);
                }
            }
            this.grid = new_grid;
        }

        java.util.List<Integer> get_neighbors(int x, int y) {
            int[][] directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
            java.util.List<Integer> neighbors = new java.util.ArrayList<>();
            for (int[] dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.add(grid[nx][ny]);
                }
            }
            return neighbors;
        }
    }

    static class Automaton {
        Grid grid;

        Automaton(Grid grid) {
            this.grid = grid;
        }

        void run(java.util.function.BiFunction<Integer, java.util.List<Integer>, Integer> rule, int steps) {
            for (int i = 0; i < steps; i++) {
                grid.update(rule);
            }
        }
    }

    static int simple_rule(int center, java.util.List<Integer> neighbors) {
        int live_neighbors = 0;
        for (int neighbor : neighbors) {
            live_neighbors += neighbor;
        }
        if (center == 1) {
            return live_neighbors == 2 || live_neighbors == 3 ? 1 : 0;
        } else {
            return live_neighbors == 3 ? 1 : 0;
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        Grid initial_grid = new Grid(grid_size);
        initial_grid.grid[4][4] = 1;
        initial_grid.grid[5][5] = 1;
        initial_grid.grid[6][4] = 1;
        initial_grid.grid[5][3] = 1;
        initial_grid.grid[4][5] = 1;
        Automaton automaton = new Automaton(initial_grid);
        while (true) {
            automaton.run(sample_0537::simple_rule, 1);
        }
    }
}