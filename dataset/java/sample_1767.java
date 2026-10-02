import java.util.Random;

public class sample_1767 {

    static class Grid {
        int size;
        int[][] state;

        Grid(int size, int[][] initial_state) {
            this.size = size;
            this.state = initial_state;
        }

        void update() {
            int[][] new_state = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (state[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                        new_state[i][j] = 1;
                    } else if (state[i][j] == 0 && neighbors == 3) {
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
                        count += 1;
                    }
                }
            }
            return count;
        }
    }

    static int[][] generate_initial_state(int size, double density) {
        Random random = new Random();
        int[][] initial_state = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                initial_state[i][j] = random.nextDouble() < density ? 1 : 0;
            }
        }
        return initial_state;
    }

    public static void main(String[] args) {
        int size = 100;
        double density = 0.2;
        Grid grid = new Grid(size, generate_initial_state(size, density));
        while (true) {
            grid.update();
        }
    }
}