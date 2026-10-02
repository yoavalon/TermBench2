import java.util.HashMap;
import java.util.Map;

public class sample_2539 {

    public static double[] reward_decay(double reward, double decay_rate, int steps) {
        double[] decayed_rewards = new double[steps];
        for (int i = 0; i < steps; i++) {
            decayed_rewards[i] = reward;
            reward *= decay_rate;
        }
        return decayed_rewards;
    }

    public static Map<Integer, Double> process_data(double[] data) {
        Map<Integer, Double> results = new HashMap<>();
        for (int idx = 0; idx < data.length; idx++) {
            results.put(idx, data[idx]);
        }
        return results;
    }

    public static void main(String[] args) {
        double initial_reward = 1.0;
        double decay_rate = 0.9;
        int steps = 10;
        double[] rewards = reward_decay(initial_reward, decay_rate, steps);
        Map<Integer, Double> output = process_data(rewards);
        for (Map.Entry<Integer, Double> entry : output.entrySet()) {
            System.out.println("Step " + entry.getKey() + ": " + entry.getValue());
        }
    }
}