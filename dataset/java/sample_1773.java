public class sample_1773 {
    static class FluidCell {
        int state;

        FluidCell(int state) {
            this.state = state;
        }

        void update_state(FluidCell[] neighbors) {
            int active_neighbors = 0;
            for (FluidCell neighbor : neighbors) {
                if (neighbor.state > 0) {
                    active_neighbors++;
                }
            }
            if (active_neighbors > 4) {
                this.state = 2;
            } else if (active_neighbors < 2) {
                this.state = 0;
            } else {
                this.state = 1;
            }
        }
    }

    static class FluidGrid {
        FluidCell[][] grid;
        int size;

        FluidGrid(int size) {
            this.grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = new FluidCell(0);
                }
            }
            this.size = size;
        }

        FluidCell[] get_neighbors(int x, int y) {
            FluidCell[] neighbors = new FluidCell[8];
            int index = 0;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if (i >= 0 && i < size && j >= 0 && j < size && (i != x || j != y)) {
                        neighbors[index++] = this.grid[i][j];
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
        FluidGrid grid = new FluidGrid(size);
        while (true) {
            grid.update_grid();
        }
    }
}