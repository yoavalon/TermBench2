import java.util.Random;

public class sample_2306 {

    static class Automaton {
        int size;
        int[][] state;

        Automaton(int size, int[][] initial_state) {
            this.size = size;
            this.state = initial_state;
        }

        void update() {
            int[][] new_state = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (state[i][j] == 1) {
                        new_state[i][j] = (2 <= neighbors && neighbors <= 3) ? 1 : 0;
                    } else {
                        new_state[i][j] = (neighbors == 3) ? 1 : 0;
                    }
                }
            }
            this.state = new_state;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if ((0 <= i && i < size && 0 <= j && j < size) && (i != x || j != y)) {
                        count += state[i][j];
                    }
                }
            }
            return count;
        }
    }

    static int[][] generate_initial_state(int size) {
        Random random = new Random();
        int[][] initial_state = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                initial_state[i][j] = random.nextInt(2);
            }
        }
        return initial_state;
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] initial_state = generate_initial_state(size);
        Automaton automaton = new Automaton(size, initial_state);
        while (true) {
            automaton.update();
        }
    }
}