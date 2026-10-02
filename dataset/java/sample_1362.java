public class sample_1362 {
    public static double decay_function(double value, double rate) {
        return value * (1 - rate);
    }

    public static double reward_decay(double initial_value, double rate, int steps) {
        double result = initial_value;
        for (int _ = 0; _ < steps; _++) {
            result = decay_function(result, rate);
        }
        return result;
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double rate = 0.05;
        int steps = 100;
        double final_value = reward_decay(initial_value, rate, steps);
        System.out.println(final_value);
    }
}