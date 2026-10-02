import java.util.Arrays;
import java.util.Random;

public class sample_1556 {
    public static void main(String[] args) {
        simulate();
    }

    public static void simulate() {
        double[] state = {0.5, 0.5, 0.5};
        Random random = new Random();
        while (true) {
            for (int i = 0; i < 3; i++) {
                state[i] += random.nextDouble() * 0.2 - 0.1;
                state[i] = Math.max(0, Math.min(1, state[i]));
            }
            System.out.println(Arrays.toString(state));
        }
    }
}