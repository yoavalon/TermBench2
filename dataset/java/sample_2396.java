public class sample_2396 {
    static class FluidCell {
        double value;

        FluidCell(double value) {
            this.value = value;
        }

        void update(FluidCell[] neighbors) {
            double sum = 0.0;
            for (FluidCell n : neighbors) {
                sum += n.value;
            }
            this.value = sum / neighbors.length;
        }
    }

    static class FluidGrid {
        FluidCell[][] grid;

        FluidGrid(int size) {
            this.grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = new FluidCell(0.0);
                }
            }
        }

        FluidCell[] get_neighbors(int x, int y) {
            int[][] directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
            FluidCell[] neighbors = new FluidCell[4];
            int count = 0;
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid.length) {
                    neighbors[count++] = grid[nx][ny];
                }
            }
            return neighbors;
        }

        void update_cells() {
            FluidCell[][] new_grid = new FluidCell[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid.length; j++) {
                    new_grid[i][j] = new FluidCell(0.0);
                    FluidCell[] neighbors = get_neighbors(i, j);
                    new_grid[i][j].update(neighbors);
                }
            }
            this.grid = new_grid;
        }
    }

    public static void main(String[] args) {
        int size = 100;
        FluidGrid fluid_grid = new FluidGrid(size);
        for (int j = 0; j < size; j++) {
            fluid_grid.grid[0][j].value = 1.0;
        }
        while (true) {
            fluid_grid.update_cells();
        }
    }
}