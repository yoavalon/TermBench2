import java.util.Random;

class Grid {
    int width;
    int height;
    int[][] grid;

    public Grid(int width, int height) {
        this.width = width;
        this.height = height;
        this.grid = new int[height][width];
    }

    public void update() {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = count_neighbors(x, y);
                if (grid[y][x] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[y][x] = 0;
                    } else {
                        new_grid[y][x] = 1;
                    }
                } else if (neighbors == 3) {
                    new_grid[y][x] = 1;
                }
            }
        }
        this.grid = new_grid;
    }

    public int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = (x + i + width) % width;
                int ny = (y + j + height) % height;
                count += grid[ny][nx];
            }
        }
        return count;
    }

    public void display() {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? 'O' : ' ');
            }
            System.out.println();
        }
    }
}

class Simulation {
    Grid grid;

    public Simulation(Grid grid) {
        this.grid = grid;
    }

    public void run() {
        while (true) {
            grid.update();
            grid.display();
            for (int i = 0; i < grid.width; i++) {
                System.out.print('-');
            }
            System.out.println();
        }
    }
}

public class sample_0571 {
    public static void main(String[] args) {
        int width = 20;
        int height = 20;
        Grid grid = new Grid(width, height);
        Random random = new Random();
        for (int i = 0; i < 50; i++) {
            int x = random.nextInt(width);
            int y = random.nextInt(height);
            grid.grid[y][x] = 1;
        }
        Simulation simulation = new Simulation(grid);
        simulation.run();
    }
}