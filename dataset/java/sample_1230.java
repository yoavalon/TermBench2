public class sample_1230 {
    public static void process_data() {
        double reward = 1.0;
        double decay_rate = 0.9;
        int steps = 10;
        for (int i = 0; i < steps; i++) {
            reward = update_reward(reward, decay_rate, 1);
        }
    }

    public static double update_reward(double reward, double decay_rate, int steps) {
        return reward * Math.pow(decay_rate, steps);
    }

    public static void main(String[] args) {
        process_data();
    }
}