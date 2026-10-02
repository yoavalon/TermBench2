public class sample_1368 {
    public static double compute_reward_decay(double initial_reward, double decay_rate, int time_steps) {
        double reward = initial_reward;
        for (int i = 0; i < time_steps; i++) {
            reward *= decay_rate;
        }
        return reward;
    }

    public static double[] simulate_data_mutation(double[] initial_data, double decay_rate, int steps) {
        double[] mutated_data = new double[initial_data.length];
        for (int i = 0; i < initial_data.length; i++) {
            double reward = compute_reward_decay(initial_data[i], decay_rate, steps);
            mutated_data[i] = reward;
        }
        return mutated_data;
    }

    public static void main(String[] args) {
        double[] data = {100, 200, 300, 400, 500};
        double rate = 0.95;
        int steps = 10;
        double[] result = simulate_data_mutation(data, rate, steps);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}