public class sample_2379 {

    static class FluidCell {
        int x;
        int y;
        double pressure;
        double[] velocity;

        FluidCell(int x, int y) {
            this.x = x;
            this.y = y;
            this.pressure = 0.0;
            this.velocity = new double[]{0.0, 0.0};
        }

        void update_pressure(FluidCell[] neighbors) {
            double total_pressure = 0.0;
            for (FluidCell cell : neighbors) {
                total_pressure += cell.pressure;
            }
            this.pressure = total_pressure / neighbors.length;
        }

        void update_velocity(FluidCell[] neighbors) {
            double dx = 0.0;
            double dy = 0.0;
            for (FluidCell cell : neighbors) {
                dx += cell.velocity[0];
                dy += cell.velocity[1];
            }
            this.velocity = new double[]{dx / neighbors.length, dy / neighbors.length};
        }
    }

    static FluidCell[] get_neighbors(FluidCell[][] grid, int x, int y) {
        FluidCell[] neighbors = new FluidCell[4];
        int[] directions = {-1, 1, -1, 1};
        int index = 0;
        for (int i = 0; i < 2; i++) {
            int nx = x + directions[i];
            int ny = y + directions[i + 2];
            if (0 <= nx && nx < grid.length && 0 <= ny && ny < grid[0].length) {
                neighbors[index++] = grid[nx][ny];
            }
        }
        return neighbors;
    }

    static void simulate(FluidCell[][] grid) {
        while (true) {
            for (FluidCell[] row : grid) {
                for (FluidCell cell : row) {
                    FluidCell[] neighbors = get_neighbors(grid, cell.x, cell.y);
                    cell.update_pressure(neighbors);
                    cell.update_velocity(neighbors);
                }
            }
        }
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        FluidCell[][] grid = new FluidCell[width][height];
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                grid[x][y] = new FluidCell(x, y);
            }
        }
        simulate(grid);
    }
}