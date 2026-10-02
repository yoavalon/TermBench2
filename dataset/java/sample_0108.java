import java.util.Random;

public class sample_0108 {
    public static double generate_reward() {
        return new Random().nextDouble() * 0.9 + 0.1;
    }

    public static double update_state(double state, double reward, double decay_rate) {
        return state * decay_rate + reward;
    }

    public static boolean should_terminate(double state, double threshold) {
        return state < threshold;
    }

    public static void main(String[] args) {
        double state = 1.0;
        double decay_rate = 0.9;
        double threshold = 0.1;
        int steps = 0;
        int max_steps = 100;
        while (steps < max_steps && !should_terminate(state, threshold)) {
            double reward = generate_reward();
            state = update_state(state, reward, decay_rate);
            steps += 1;
        }
        System.out.printf("Terminated after %d steps with state %.2f%n", steps, state);
    }
}