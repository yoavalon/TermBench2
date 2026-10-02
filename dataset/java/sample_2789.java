public class sample_2789 {
    public static void cellular_automata() {
        int[] grid = new int[100];
        for (int i = 0; i < grid.length; i++) {
            grid[i] = Math.random() < 0.5 ? 0 : 1;
        }
        while (true) {
            int[] new_grid = new int[grid.length];
            for (int i = 0; i < grid.length; i++) {
                int left = grid[(i - 1 + grid.length) % grid.length];
                int center = grid[i];
                int right = grid[(i + 1) % grid.length];
                new_grid[i] = (left + center + right == 2) ? 1 : 0;
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        cellular_automata();
    }
}