import java.util.ArrayList;
import java.util.List;

public class sample_2585 {
    public static List<Double> reward_decay(double init_val, double decay_rate, int steps) {
        List<Double> rewards = new ArrayList<>();
        double current_val = init_val;
        for (int i = 0; i < steps; i++) {
            rewards.add(current_val);
            current_val *= decay_rate;
        }
        return rewards;
    }

    public static double[] analyze_rewards(List<Double> rewards) {
        double total = 0.0;
        for (double reward : rewards) {
            total += reward;
        }
        double avg = total / rewards.size();
        return new double[]{total, avg};
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double decay_rate = 0.9;
        int number_of_steps = 10;
        List<Double> sequence = reward_decay(initial_value, decay_rate, number_of_steps);
        double[] result = analyze_rewards(sequence);
        System.out.println("Total: " + result[0] + ", Average: " + result[1]);
    }
}