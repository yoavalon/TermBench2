public class sample_2387 {

    static class FluidCell {
        double state;

        FluidCell(double state) {
            this.state = state;
        }

        void update_state(FluidCell[] neighbors) {
            double sum = 0;
            for (FluidCell n : neighbors) {
                sum += n.state;
            }
            this.state = sum / neighbors.length;
        }
    }

    static class FluidGrid {
        int size;
        FluidCell[][] grid;

        FluidGrid(int size, double initial_state) {
            this.size = size;
            this.grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = new FluidCell(initial_state);
                }
            }
        }

        FluidCell[] get_neighbors(int x, int y) {
            FluidCell[] neighbors = new FluidCell[8];
            int index = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                        neighbors[index++] = grid[nx][ny];
                    }
                }
            }
            return neighbors;
        }

        void update_grid() {
            FluidCell[][] new_grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_grid[i][j] = new FluidCell(0);
                    FluidCell[] neighbors = get_neighbors(i, j);
                    new_grid[i][j].update_state(neighbors);
                }
            }
            this.grid = new_grid;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        double initial_state = 1.0;
        FluidGrid grid = new FluidGrid(size, initial_state);
        while (true) {
            grid.update_grid();
        }
    }
}