import java.util.Arrays;

public class sample_0544 {
    static class Grid {
        int size;
        int[][] state;

        Grid(int size) {
            this.size = size;
            this.state = new int[size][size];
            for (int i = 0; i < size; i++) {
                Arrays.fill(this.state[i], 0);
            }
        }

        void update() {
            int[][] new_state = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = get_neighbors(i, j);
                    if (state[i][j] == 0 && neighbors == 3) {
                        new_state[i][j] = 1;
                    } else if (state[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_state[i][j] = 0;
                    } else {
                        new_state[i][j] = state[i][j];
                    }
                }
            }
            this.state = new_state;
        }

        int get_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(x + 2, size); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(y + 2, size); j++) {
                    if ((i != x || j != y) && state[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }

    static void display(Grid grid) {
        for (int[] row : grid.state) {
            for (int cell : row) {
                System.out.print(cell == 1 ? '*' : ' ');
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int size = 10;
        Grid grid = new Grid(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i % 2 == 0 && j % 2 == 0) {
                    grid.state[i][j] = 1;
                }
            }
        }
        while (true) {
            display(grid);
            grid.update();
        }
    }
}