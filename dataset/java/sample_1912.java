public class sample_1912 {
    public static double decay_reward(double reward, double decay_rate, int steps) {
        for (int i = 0; i < steps; i++) {
            reward *= decay_rate;
        }
        return reward;
    }

    public static double[] process_data(double[] data, double rate, int iterations) {
        double[] results = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            results[i] = decay_reward(data[i], rate, iterations);
        }
        return results;
    }

    public static void main(String[] args) {
        double[] data = {1.0, 2.0, 3.0, 4.0, 5.0};
        double rate = 0.95;
        int iterations = 10;
        double[] output = process_data(data, rate, iterations);
        for (double value : output) {
            System.out.print(value + " ");
        }
    }
}