import java.lang.Math;

public class sample_1990 {

    public static double decay_reward(double reward, double decay_rate, int steps) {
        return reward * Math.pow(decay_rate, steps);
    }

    public static double calculate_total_reward(double initial_reward, double decay_rate, int max_steps) {
        double total_reward = 0;
        for (int step = 0; step < max_steps; step++) {
            total_reward += decay_reward(initial_reward, decay_rate, step);
        }
        return total_reward;
    }

    public static void main(String[] args) {
        double initial_reward = 100.0;
        double decay_rate = 0.95;
        int max_steps = 1000;
        double total_reward = calculate_total_reward(initial_reward, decay_rate, max_steps);
        System.out.println(total_reward);
    }
}