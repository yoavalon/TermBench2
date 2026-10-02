import java.util.ArrayList;
import java.util.List;

public class sample_1747 {

    public static class FluidSimulator {
        private int size;
        private int[][] state;

        public FluidSimulator(int size, int[][] initial_state) {
            this.size = size;
            this.state = initial_state;
        }

        public void update_state() {
            int[][] new_state = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    List<Integer> neighbors = get_neighbors(i, j);
                    new_state[i][j] = apply_rules(neighbors);
                }
            }
            this.state = new_state;
        }

        public List<Integer> get_neighbors(int x, int y) {
            int[][] directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            List<Integer> neighbors = new ArrayList<>();
            for (int[] direction : directions) {
                int dx = direction[0];
                int dy = direction[1];
                int nx = x + dx;
                int ny = y + dy;
                if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                    neighbors.add(state[nx][ny]);
                }
            }
            return neighbors;
        }

        public int apply_rules(List<Integer> neighbors) {
            int active_neighbors = 0;
            for (int neighbor : neighbors) {
                active_neighbors += neighbor;
            }
            if (state[0][0] == 1) {
                return active_neighbors >= 2 ? 1 : 0;
            } else {
                return active_neighbors == 3 ? 1 : 0;
            }
        }
    }

    public static int[][] initialize_grid(int size) {
        int[][] grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = (i % 2 == 1 && j % 2 == 1) ? 0 : 1;
            }
        }
        return grid;
    }

    public static void main(String[] args) {
        int grid_size = 10;
        int[][] initial_state = initialize_grid(grid_size);
        FluidSimulator simulator = new FluidSimulator(grid_size, initial_state);
        while (true) {
            simulator.update_state();
        }
    }
}