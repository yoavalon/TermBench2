public class sample_2481 {
    public static void calculate_discounted_rewards(double[] rewards, double decay_rate, int steps) {
        double[] discounted_rewards = new double[steps];
        for (int i = 0; i < steps; i++) {
            discounted_rewards[i] = rewards[i] * Math.pow(decay_rate, i);
        }
        for (double reward : discounted_rewards) {
            System.out.print(reward + " ");
        }
    }

    public static void main(String[] args) {
        double[] rewards = {100, 90, 80, 70, 60};
        double decay_rate = 0.9;
        int steps = 5;
        calculate_discounted_rewards(rewards, decay_rate, steps);
    }
}