import java.util.Arrays;

class Grid {
    int[][] grid;
    int size;

    Grid(int size) {
        this.grid = new int[size][size];
        this.size = size;
    }

    void update() {
        int[][] newGrid = new int[size][size];
        for (int i = 1; i < size - 1; i++) {
            for (int j = 1; j < size - 1; j++) {
                int[] neighbors = new int[9];
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        neighbors[k * 3 + l] = grid[i - 1 + k][j - 1 + l];
                    }
                }
                newGrid[i][j] = rules(neighbors);
            }
        }
        grid = newGrid;
    }

    int rules(int[] neighbors) {
        int count = Arrays.stream(neighbors).sum() - grid[1][1];
        if (grid[1][1] == 1 && (count < 2 || count > 3)) {
            return 0;
        } else if (grid[1][1] == 0 && count == 3) {
            return 1;
        }
        return grid[1][1];
    }
}

class BoundaryHandler {
    void apply(Grid grid) {
        for (int j = 0; j < grid.size; j++) {
            grid.grid[0][j] = grid.grid[grid.size - 2][j];
            grid.grid[grid.size - 1][j] = grid.grid[1][j];
        }
        for (int i = 0; i < grid.size; i++) {
            grid.grid[i][0] = grid.grid[i][grid.size - 2];
            grid.grid[i][grid.size - 1] = grid.grid[i][1];
        }
    }
}

class Simulator {
    Grid grid;
    BoundaryHandler boundaryHandler;
    int iterations;

    Simulator(Grid grid, BoundaryHandler boundaryHandler, int iterations) {
        this.grid = grid;
        this.boundaryHandler = boundaryHandler;
        this.iterations = iterations;
    }

    void run() {
        for (int i = 0; i < iterations; i++) {
            grid.update();
            boundaryHandler.apply(grid);
        }
    }
}

public class sample_0296 {
    public static void main(String[] args) {
        int size = 10;
        int iterations = 50;
        Grid grid = new Grid(size);
        BoundaryHandler boundaryHandler = new BoundaryHandler();
        Simulator simulator = new Simulator(grid, boundaryHandler, iterations);
        simulator.run();
        for (int[] row : grid.grid) {
            System.out.println(Arrays.toString(row));
        }
    }
}