public class sample_2500 {
    public static double[] simulate_decay(int steps, double decay_rate) {
        double reward = 1.0;
        double[] rewards = new double[steps];
        for (int i = 0; i < steps; i++) {
            rewards[i] = reward;
            reward *= decay_rate;
        }
        return rewards;
    }

    public static void main(String[] args) {
        double[] result = simulate_decay(10, 0.9);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}