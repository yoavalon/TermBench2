public class sample_1953 {
    public static double decay_function(double current_value, double decay_rate) {
        return current_value * (1 - decay_rate);
    }

    public static int termination_analysis(double initial_value, double threshold, double decay_rate) {
        double value = initial_value;
        int count = 0;
        while (value > threshold) {
            value = decay_function(value, decay_rate);
            count += 1;
        }
        return count;
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double threshold = 0.01;
        double decay_rate = 0.1;
        int result = termination_analysis(initial_value, threshold, decay_rate);
        System.out.println(result);
    }
}