import java.util.ArrayList;
import java.util.List;

public class sample_2538 {

    public static double compute_reward_decay(double reward, double decay_rate, int steps) {
        return reward * Math.pow(decay_rate, steps);
    }

    public static List<Double> simulate_sequence(double initial_reward, double decay_rate, int max_steps) {
        List<Double> sequence = new ArrayList<>();
        double current_reward = initial_reward;
        for (int step = 0; step < max_steps; step++) {
            current_reward = compute_reward_decay(current_reward, decay_rate, 1);
            sequence.add(current_reward);
        }
        return sequence;
    }

    public static void main(String[] args) {
        double initial_value = 100;
        double decay_factor = 0.95;
        int total_iterations = 10;
        List<Double> result = simulate_sequence(initial_value, decay_factor, total_iterations);
        System.out.println(result);
    }
}