public class sample_1788 {

    class Grid {
        int size;
        int[][] state;

        Grid(int size) {
            this.size = size;
            this.state = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    state[i][j] = 0;
                }
            }
        }

        void update() {
            int[][] new_state = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (state[i][j] == 0) {
                        if (neighbors == 3) {
                            new_state[i][j] = 1;
                        }
                    } else if (neighbors == 2 || neighbors == 3) {
                        new_state[i][j] = 1;
                    }
                }
            }
            state = new_state;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(size, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(size, y + 2); j++) {
                    if ((i != x || j != y) && state[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }

    void display(Grid grid) {
        for (int[] row : grid.state) {
            for (int cell : row) {
                System.out.print(cell == 1 ? 'O' : '.');
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        sample_1788 sample = new sample_1788();
        int size = 50;
        Grid grid = sample.new Grid(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid.state[i][j] = (i + j) % 2 == 0 ? 1 : 0;
            }
        }
        while (true) {
            sample.display(grid);
            grid.update();
        }
    }
}