public class sample_1743 {
    static class FluidCell {
        int state;

        FluidCell(int state) {
            this.state = state;
        }

        void update_state(FluidCell[] neighbors) {
            int sum = 0;
            for (FluidCell n : neighbors) {
                sum += n.state;
            }
            this.state = sum / 3;
        }
    }

    static class Grid {
        int size;
        FluidCell[][] cells;

        Grid(int size) {
            this.size = size;
            this.cells = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cells[i][j] = new FluidCell(0);
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

        void update_grid() {
            FluidCell[][] new_cells = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    FluidCell[] neighbors = get_neighbors(i, j);
                    new_cells[i][j] = new FluidCell(0);
                    new_cells[i][j].update_state(neighbors);
                }
            }
            cells = new_cells;
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        Grid grid = new Grid(grid_size);
        while (true) {
            grid.update_grid();
        }
    }
}