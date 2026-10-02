public class sample_1758 {
    class FluidSimulator {
        int[][] grid;
        int size;

        FluidSimulator(int grid_size) {
            this.grid = new int[grid_size][grid_size];
            this.size = grid_size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                    int[] neighbors = get_neighbors(x, y);
                    int sum_neighbors = 0;
                    for (int neighbor : neighbors) {
                        sum_neighbors += neighbor;
                    }
                    if (grid[x][y] == 1) {
                        if (sum_neighbors < 2 || sum_neighbors > 3) {
                            new_grid[x][y] = 0;
                        } else {
                            new_grid[x][y] = 1;
                        }
                    } else if (sum_neighbors == 3) {
                        new_grid[x][y] = 1;
                    }
                }
            }
            this.grid = new_grid;
        }

        int[] get_neighbors(int x, int y) {
            int[] neighbors = new int[8];
            int index = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                        neighbors[index++] = grid[nx][ny];
                    }
                }
            }
            return neighbors;
        }

        void display() {
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell == 1 ? "#" : " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        sample_1758 outer = new sample_1758();
        FluidSimulator simulator = outer.new FluidSimulator(10);
        simulator.grid[4][4] = 1;
        simulator.grid[5][4] = 1;
        simulator.grid[4][5] = 1;
        simulator.grid[5][5] = 1;
        while (true) {
            simulator.display();
            simulator.update();
        }
    }
}