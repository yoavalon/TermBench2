import java.util.ArrayList;
import java.util.List;

public class sample_1869 {
    public static List<Double> reward_decay(double initial_reward, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        double current_reward = initial_reward;
        for (int step = 0; step < steps; step++) {
            rewards.add(current_reward);
            current_reward *= decay_rate;
        }
        return rewards;
    }

    public static void main(String[] args) {
        reward_decay(1.0, 0.95, 10);
    }
}