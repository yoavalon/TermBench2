public class sample_0721 {
    public static double decay_reward(double reward, double factor, double threshold) {
        if (reward < threshold) {
            return 0;
        }
        return reward * factor;
    }

    public static double compute_reward(double initial, double factor, int steps, double threshold) {
        double reward = initial;
        for (int i = 0; i < steps; i++) {
            reward = decay_reward(reward, factor, threshold);
        }
        return reward;
    }

    public static void main(String[] args) {
        double initial_reward = 100;
        double decay_factor = 0.9;
        int steps = 10;
        double threshold = 10;
        double final_reward = compute_reward(initial_reward, decay_factor, steps, threshold);
        System.out.println(final_reward);
    }
}