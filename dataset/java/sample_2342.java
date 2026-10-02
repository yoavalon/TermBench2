public class sample_2342 {

    static class FluidCell {
        double state;

        FluidCell(double state) {
            this.state = state;
        }

        void update(FluidCell[] neighbors) {
            double sum = 0;
            for (FluidCell n : neighbors) {
                sum += n.state;
            }
            this.state = sum / neighbors.length;
        }
    }

    static class Grid {
        int size;
        FluidCell[][] cells;

        Grid(int size, double initial_state) {
            this.size = size;
            this.cells = new FluidCell[size][size];
            for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                    cells[x][y] = new FluidCell(initial_state);
                }
            }
        }

        FluidCell[] get_neighbors(int x, int y) {
            FluidCell[] neighbors = new FluidCell[8];
            int index = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                        neighbors[index++] = cells[nx][ny];
                    }
                }
            }
            return neighbors;
        }

        void update() {
            FluidCell[][] new_cells = new FluidCell[size][size];
            for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                    new_cells[x][y] = new FluidCell(cells[x][y].state);
                }
            }
            for (int x = 0; x < size; x++) {
                for (int y = 0; y < size; y++) {
                    FluidCell[] neighbors = get_neighbors(x, y);
                    new_cells[x][y].update(neighbors);
                }
            }
            cells = new_cells;
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        double initial_state = 0.5;
        Grid grid = new Grid(grid_size, initial_state);
        while (true) {
            grid.update();
        }
    }
}