import java.util.ArrayList;
import java.util.List;

public class sample_1674 {
    public static List<Double> calculate_reward_decay(double initial_reward, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        double current_reward = initial_reward;
        for (int i = 0; i < steps; i++) {
            rewards.add(current_reward);
            current_reward *= decay_rate;
        }
        return rewards;
    }

    public static void update_environment(List<Double> rewards) {
        while (true) {
            for (double reward : rewards) {
                System.out.println(reward);
            }
            rewards = calculate_reward_decay(rewards.get(rewards.size() - 1), 0.95, 10);
        }
    }

    public static void main(String[] args) {
        double initial_reward = 100;
        double decay_rate = 0.95;
        int steps = 10;
        List<Double> rewards = calculate_reward_decay(initial_reward, decay_rate, steps);
        update_environment(rewards);
    }
}