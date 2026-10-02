import java.util.Random;

public class sample_2759 {
    public static void simulate() {
        int size = 20;
        int[][] state = new int[size][size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                state[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            state = update(state);
        }
    }

    public static int[][] update(int[][] state) {
        int size = state.length;
        int[][] new_state = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                neighbors += (i > 0) ? state[i - 1][j] : 0;
                neighbors += (i < size - 1) ? state[i + 1][j] : 0;
                neighbors += (j > 0) ? state[i][j - 1] : 0;
                neighbors += (j < size - 1) ? state[i][j + 1] : 0;
                if (state[i][j] == 1 && neighbors < 2) {
                    new_state[i][j] = 0;
                } else if (state[i][j] == 1 && neighbors > 3) {
                    new_state[i][j] = 0;
                } else if (state[i][j] == 0 && neighbors == 3) {
                    new_state[i][j] = 1;
                } else {
                    new_state[i][j] = state[i][j];
                }
            }
        }
        return new_state;
    }

    public static void main(String[] args) {
        simulate();
    }
}