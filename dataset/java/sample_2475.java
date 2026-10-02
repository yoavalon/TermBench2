import java.util.ArrayList;
import java.util.List;

public class sample_2475 {
    public static List<Double> sequence_reward_decay(int steps, double decay_rate) {
        List<Double> rewards = new ArrayList<>();
        double reward = 1.0;
        for (int i = 0; i < steps; i++) {
            rewards.add(reward);
            reward *= decay_rate;
        }
        return rewards;
    }

    public static void main(String[] args) {
        int steps = 10;
        double decay_rate = 0.9;
        List<Double> result = sequence_reward_decay(steps, decay_rate);
        System.out.println(result);
    }
}