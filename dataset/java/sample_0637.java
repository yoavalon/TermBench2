public class sample_0637 {
    public static double decay_reward(double base, double factor, double threshold, double value) {
        if (value * factor < threshold) {
            return value;
        }
        return decay_reward(base, factor, threshold, value * factor);
    }

    public static void main(String[] args) {
        decay_reward(0.9, 0.95, 0.1);
    }
}