public class sample_1165 {
    class FluidGrid {
        int[][] grid;
        int size;

        FluidGrid(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_grid[i][j] = calculate_next_state(i, j);
                }
            }
            this.grid = new_grid;
        }

        int calculate_next_state(int x, int y) {
            int[] neighbors = get_neighbors(x, y);
            int count = 0;
            for (int neighbor : neighbors) {
                count += neighbor;
            }
            if (grid[x][y] == 0) {
                return count > 2 ? 1 : 0;
            } else {
                return count == 2 || count == 3 ? 1 : 0;
            }
        }

        int[] get_neighbors(int x, int y) {
            int[] directions = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
            int[] neighbors = new int[8];
            for (int i = 0; i < 8; i++) {
                int dx = directions[2 * i];
                int dy = directions[2 * i + 1];
                int nx = x + dx;
                int ny = y + dy;
                if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                    neighbors[i] = grid[nx][ny];
                } else {
                    neighbors[i] = 0;
                }
            }
            return neighbors;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        sample_1165 sample = new sample_1165();
        FluidGrid grid = sample.new FluidGrid(size);
        while (true) {
            grid.update();
        }
    }
}