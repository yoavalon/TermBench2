public class sample_1570 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        double reward = 1.0;
        double decay_rate = 0.99;
        int step = 0;
        while (true) {
            reward = update_reward(reward, decay_rate, step);
            step += 1;
        }
    }

    public static double update_reward(double reward, double decay_rate, int step) {
        return reward * Math.pow(decay_rate, step);
    }
}