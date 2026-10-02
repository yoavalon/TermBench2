import java.util.ArrayList;
import java.util.List;

public class sample_1209 {
    public static List<Double> simulate_decay_reward(double initial_reward, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        rewards.add(initial_reward);
        for (int i = 0; i < steps; i++) {
            double current_reward = rewards.get(rewards.size() - 1) * (1 - decay_rate);
            rewards.add(current_reward);
        }
        return rewards;
    }

    public static void main(String[] args) {
        double initial_reward = 1.0;
        double decay_rate = 0.1;
        int steps = 10;
        List<Double> result = simulate_decay_reward(initial_reward, decay_rate, steps);
        System.out.println(result);
    }
}