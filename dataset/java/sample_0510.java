public class sample_0510 {

    static class FluidCell {
        int state;

        FluidCell(int state) {
            this.state = state;
        }

        void update_state(FluidCell[] neighbors) {
            int active_neighbors = 0;
            for (FluidCell cell : neighbors) {
                if (cell.state == 1) {
                    active_neighbors++;
                }
            }
            if (active_neighbors == 2 || active_neighbors == 3) {
                this.state = 1;
            } else {
                this.state = 0;
            }
        }
    }

    static class Grid {
        int size;
        FluidCell[][] grid;

        Grid(int size) {
            this.size = size;
            this.grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = new FluidCell(0);
                }
            }
        }

        FluidCell[] get_neighbors(int x, int y) {
            int[][] directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
            FluidCell[] neighbors = new FluidCell[8];
            int index = 0;
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors[index++] = grid[nx][ny];
                }
            }
            return neighbors;
        }

        void update_grid() {
            FluidCell[][] new_grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_grid[i][j] = new FluidCell(grid[i][j].state);
                }
            }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    FluidCell[] neighbors = get_neighbors(i, j);
                    new_grid[i][j].update_state(neighbors);
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        int grid_size = 50;
        Grid simulation = new Grid(grid_size);
        while (true) {
            simulation.update_grid();
        }
    }
}