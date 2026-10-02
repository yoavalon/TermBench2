public class sample_1890 {
    public static double decay_reward(double initial_value, double decay_rate, int steps) {
        for (int _ = 0; _ < steps; _++) {
            initial_value *= decay_rate;
        }
        return initial_value;
    }

    public static void main(String[] args) {
        decay_reward(10.0, 0.9, 100);
    }
}