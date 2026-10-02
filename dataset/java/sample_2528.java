public class sample_2528 {
    public static void decay_reward(double reward, double decay_rate, int steps, double[] decayed_rewards) {
        for (int step = 0; step < steps; step++) {
            decayed_rewards[step] = reward * Math.pow(decay_rate, step);
        }
    }

    public static double calculate_final_reward(double initial_reward, double decay_rate, int steps) {
        double[] rewards = new double[steps];
        decay_reward(initial_reward, decay_rate, steps, rewards);
        double sum = 0;
        for (double reward : rewards) {
            sum += reward;
        }
        return sum;
    }

    public static void main(String[] args) {
        double initial = 100;
        double rate = 0.9;
        int steps = 10;
        double final_reward = calculate_final_reward(initial, rate, steps);
        System.out.println(final_reward);
    }
}