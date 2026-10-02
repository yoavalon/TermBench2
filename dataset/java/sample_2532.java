import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2532 {

    public static double decay_reward(double reward, double decay_rate) {
        return reward * decay_rate;
    }

    public static List<Double> simulate_reward_decay(double initial_reward, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        double current_reward = initial_reward;
        for (int i = 0; i < steps; i++) {
            rewards.add(current_reward);
            current_reward = decay_reward(current_reward, decay_rate);
        }
        return rewards;
    }

    public static void main(String[] args) {
        double initial_reward = 100.0;
        double decay_rate = 0.95;
        int steps = 10;
        List<Double> rewards = simulate_reward_decay(initial_reward, decay_rate, steps);
        for (int step = 0; step < rewards.size(); step++) {
            System.out.printf("Step %d: Reward %.2f%n", step + 1, rewards.get(step));
        }
    }
}