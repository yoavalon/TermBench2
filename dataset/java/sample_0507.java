import java.util.Random;

public class sample_0507 {

    public static class Grid {

        int size;
        int[][] grid;

        public Grid(int size) {
            this.size = size;
            this.grid = new int[size][size];
            Random random = new Random();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = random.nextInt(2);
                }
            }
        }

        public void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int state = this.grid[i][j];
                    int neighbors = countNeighbors(i, j);
                    if (state == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = state;
                    }
                }
            }
            this.grid = new_grid;
        }

        public int countNeighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(x + 2, size); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(y + 2, size); j++) {
                    if ((i != x || j != y)) {
                        count += this.grid[i][j];
                    }
                }
            }
            return count;
        }
    }

    public static class Simulation {

        Grid grid;

        public Simulation(Grid grid) {
            this.grid = grid;
        }

        public void run() {
            while (true) {
                this.grid.update();
                this.display();
            }
        }

        public void display() {
            for (int[] row : this.grid.grid) {
                for (int cell : row) {
                    System.out.print(cell == 1 ? '#' : ' ');
                }
                System.out.println();
            }
            for (int i = 0; i < this.grid.size; i++) {
                System.out.print("-");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int size = 50;
        Grid grid = new Grid(size);
        Simulation simulation = new Simulation(grid);
        simulation.run();
    }
}