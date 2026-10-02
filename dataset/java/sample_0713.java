import java.util.ArrayList;
import java.util.List;

public class sample_0713 {
    static double reward_decay(double current, double rate, double threshold) {
        if (current <= threshold) {
            return current;
        }
        return reward_decay(current * rate, rate, threshold);
    }

    static List<Double> calculate_discounted_rewards(double initial, double rate, double threshold) {
        List<Double> rewards = new ArrayList<>();
        while (initial > threshold) {
            rewards.add(initial);
            initial = initial * rate;
        }
        rewards.add(initial);
        return rewards;
    }

    public static void main(String[] args) {
        double initial = 100;
        double rate = 0.9;
        double threshold = 10;
        List<Double> result = calculate_discounted_rewards(initial, rate, threshold);
        System.out.println(result);
    }
}