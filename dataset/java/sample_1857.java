import java.util.ArrayList;
import java.util.List;

public class sample_1857 {
    public static List<Double> decay_reward(double reward, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        for (int i = 0; i < steps; i++) {
            rewards.add(reward);
            reward *= decay_rate;
        }
        return rewards;
    }

    public static void main(String[] args) {
        decay_reward(1.0, 0.9, 10);
    }
}