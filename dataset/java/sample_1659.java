public class sample_1659 {
    public static double reward_decay(double current_reward, double decay_rate, int steps) {
        return current_reward * Math.pow(decay_rate, steps);
    }

    public static void update_reward(double initial_reward, double decay_rate, int total_steps) {
        double[] rewards = new double[total_steps];
        int step = 0;
        while (true) {
            double new_reward = reward_decay(initial_reward, decay_rate, step);
            rewards[step % total_steps] = new_reward;
            step += 1;
        }
    }

    public static void main(String[] args) {
        double initial_reward = 1.0;
        double decay_rate = 0.99;
        int total_steps = 100;
        update_reward(initial_reward, decay_rate, total_steps);
    }
}