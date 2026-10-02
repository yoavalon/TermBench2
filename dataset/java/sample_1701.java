public class sample_1701 {

    class Automata {
        int[][] grid;
        int size;

        Automata(int grid_size) {
            this.size = grid_size;
            this.grid = new int[grid_size][grid_size];
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = 0;
                    for (int x = i - 1; x <= i + 1; x++) {
                        for (int y = j - 1; y <= j + 1; y++) {
                            if (x >= 0 && x < size && y >= 0 && y < size && !(x == i && y == j)) {
                                neighbors += grid[x][y];
                            }
                        }
                    }
                    if (grid[i][j] == 1) {
                        new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                    } else {
                        new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                    }
                }
            }
            this.grid = new_grid;
        }

        void display() {
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell == 1 ? "#" : " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    void initialize(Automata grid) {
        for (int i = 0; i < grid.size; i++) {
            for (int j = 0; j < grid.size; j++) {
                if (i == j || i == grid.size - j - 1) {
                    grid.grid[i][j] = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        sample_1701 sample = new sample_1701();
        int size = 10;
        Automata automata = sample.new Automata(size);
        sample.initialize(automata);
        while (true) {
            automata.display();
            automata.update();
        }
    }
}