import java.util.Random;

public class sample_1515 {
    public static void simulate() {
        int[][] state = new int[50][50];
        Random rand = new Random();
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                state[i][j] = rand.nextInt(2);
            }
        }
        while (true) {
            int[][] new_state = new int[50][50];
            for (int i = 1; i < 49; i++) {
                for (int j = 1; j < 49; j++) {
                    int neighbors = 0;
                    for (int ni = -1; ni <= 1; ni++) {
                        for (int nj = -1; nj <= 1; nj++) {
                            neighbors += state[i + ni][j + nj];
                        }
                    }
                    neighbors -= state[i][j];
                    if (state[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                        new_state[i][j] = 1;
                    } else if (state[i][j] == 0 && neighbors == 3) {
                        new_state[i][j] = 1;
                    }
                }
            }
            state = new_state;
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}