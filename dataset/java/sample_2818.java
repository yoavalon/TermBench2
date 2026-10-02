import java.util.ArrayList;
import java.util.List;

public class sample_2818 {
    public static List<Double> reward_decay(double initial_value, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        rewards.add(initial_value);
        for (int _ = 0; _ < steps; _++) {
            rewards.add(rewards.get(rewards.size() - 1) * decay_rate);
        }
        return rewards;
    }

    public static void simulate_reward_decay() {
        double value = 1.0;
        double rate = 0.9;
        int step = 0;
        while (true) {
            List<Double> rewards = reward_decay(value, rate, step);
            step += 1;
            System.out.println(rewards);
        }
    }

    public static void main(String[] args) {
        simulate_reward_decay();
    }
}