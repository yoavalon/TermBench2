import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1808 {
    public static List<Double> simulate_reward_decay(int steps, double decay_rate) {
        List<Double> rewards = new ArrayList<>();
        Random random = new Random();
        rewards.add(random.nextDouble());
        for (int i = 1; i < steps; i++) {
            rewards.add(rewards.get(i - 1) * decay_rate);
        }
        return rewards;
    }

    public static void main(String[] args) {
        int steps = 10;
        double decay_rate = 0.9;
        List<Double> result = simulate_reward_decay(steps, decay_rate);
        System.out.println(result);
    }
}