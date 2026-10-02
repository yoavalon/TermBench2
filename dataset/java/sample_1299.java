public class sample_1299 {
    public static double decay_reward(double initial_value, double decay_rate, int steps) {
        double current_value = initial_value;
        for (int _ = 0; _ < steps; _++) {
            current_value *= decay_rate;
        }
        return current_value;
    }

    public static void main(String[] args) {
        decay_reward(100, 0.9, 10);
    }
}