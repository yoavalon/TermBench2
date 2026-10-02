public class sample_0516 {
    static class FluidCell {
        int state;

        FluidCell(int state) {
            this.state = state;
        }

        void update(FluidCell[] neighbors) {
            int sum = 0;
            for (FluidCell n : neighbors) {
                sum += n.state;
            }
            this.state = sum / neighbors.length;
        }
    }

    static class Grid {
        int width;
        int height;
        FluidCell[][] grid;

        Grid(int width, int height, int initial_state) {
            this.width = width;
            this.height = height;
            this.grid = new FluidCell[height][width];
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    grid[y][x] = new FluidCell(initial_state);
                }
            }
        }

        FluidCell[] get_neighbors(int x, int y) {
            int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            FluidCell[] neighbors = new FluidCell[4];
            int index = 0;
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (0 <= nx && nx < width && 0 <= ny && ny < height) {
                    neighbors[index++] = grid[ny][nx];
                }
            }
            return neighbors;
        }

        void update_cells() {
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    FluidCell[] neighbors = get_neighbors(x, y);
                    grid[y][x].update(neighbors);
                }
            }
        }
    }

    static class Simulation {
        Grid grid;

        Simulation(Grid grid) {
            this.grid = grid;
        }

        void run() {
            while (true) {
                grid.update_cells();
            }
        }
    }

    public static void main(String[] args) {
        Grid grid = new Grid(10, 10, 50);
        Simulation simulation = new Simulation(grid);
        simulation.run();
    }
}