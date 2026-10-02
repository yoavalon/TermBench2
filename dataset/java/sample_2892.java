public class sample_2892 {
    public static double decay_factor(int time_step) {
        return Math.pow(0.99, time_step);
    }

    public static double calculate_reward(double initial_reward, int steps) {
        double reward = initial_reward;
        for (int t = 0; t < steps; t++) {
            reward *= decay_factor(t);
        }
        return reward;
    }

    public static void main(String[] args) {
        double initial_value = 100;
        int steps = 0;
        while (true) {
            double reward = calculate_reward(initial_value, steps);
            System.out.printf("Step %d: Reward %.4f%n", steps, reward);
            steps += 1;
        }
    }
}