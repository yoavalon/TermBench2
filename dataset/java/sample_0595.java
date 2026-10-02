import java.util.Random;

class Grid {
    int size;
    int[][] grid;

    public Grid(int size) {
        this.size = size;
        this.grid = new int[size][size];
    }

    public void update() {
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 1) {
                    new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                } else {
                    new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        grid = new_grid;
    }

    public int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = Math.max(0, x - 1); i < Math.min(size, x + 2); i++) {
            for (int j = Math.max(0, y - 1); j < Math.min(size, y + 2); j++) {
                if (i != x || j != y) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }
}

class Simulation {
    Grid grid;

    public Simulation(int grid_size) {
        this.grid = new Grid(grid_size);
        populate_grid();
    }

    public void populate_grid() {
        Random random = new Random();
        for (int i = 0; i < grid.size; i++) {
            for (int j = 0; j < grid.size; j++) {
                grid.grid[i][j] = random.nextInt(2);
            }
        }
    }

    public void run() {
        while (true) {
            grid.update();
        }
    }
}

public class sample_0595 {
    public static void main(String[] args) {
        Simulation sim = new Simulation(10);
        sim.run();
    }
}