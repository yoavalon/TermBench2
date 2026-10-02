public class sample_0280 {

    class Grid {
        int size;
        int[][] data;

        Grid(int size) {
            this.size = size;
            this.data = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    data[i][j] = 0;
                }
            }
        }

        void update() {
            int[][] new_data = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_data[i][j] = _calculate_next_state(i, j);
                }
            }
            this.data = new_data;
        }

        int _calculate_next_state(int i, int j) {
            int[] neighbors = _get_neighbors(i, j);
            int alive_count = 0;
            for (int neighbor : neighbors) {
                alive_count += neighbor;
            }
            if (data[i][j] == 1) {
                return alive_count == 2 || alive_count == 3 ? 1 : 0;
            } else {
                return alive_count == 3 ? 1 : 0;
            }
        }

        int[] _get_neighbors(int i, int j) {
            int[] neighbors = new int[8];
            int index = 0;
            for (int x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (int y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    if ((x, y) != (i, j)) {
                        neighbors[index++] = data[x][y];
                    }
                }
            }
            return neighbors;
        }
    }

    public static void main(String[] args) {
        int gridSize = 10;
        sample_0280 sample = new sample_0280();
        Grid grid = sample.new Grid(gridSize);
        int steps = 50;
        for (int _ = 0; _ < steps; _++) {
            grid.update();
        }
    }
}