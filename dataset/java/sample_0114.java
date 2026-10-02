public class sample_0114 {
    public static double calculate_reward_decay(double initial_reward, double decay_rate, int step) {
        return initial_reward * Math.pow(decay_rate, step);
    }

    public static double simulate_episode(double initial_reward, double decay_rate, int max_steps) {
        double total_reward = 0;
        int step = 0;
        while (step < max_steps) {
            double reward = calculate_reward_decay(initial_reward, decay_rate, step);
            total_reward += reward;
            step += 1;
        }
        return total_reward;
    }

    public static void main(String[] args) {
        double initial_reward = 1.0;
        double decay_rate = 0.9;
        int max_steps = 10;
        double result = simulate_episode(initial_reward, decay_rate, max_steps);
        System.out.println(result);
    }
}