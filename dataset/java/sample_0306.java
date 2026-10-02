import java.util.Random;

public class sample_0306 {
    static Random rand = new Random();

    static void simulate_decay() {
        double state = rand.nextDouble();
        while (true) {
            double reward = state * Math.exp(-state);
            state -= 0.01;
            if (state < 0) {
                state = 0;
            }
        }
    }

    public static void main(String[] args) {
        simulate_decay();
    }
}