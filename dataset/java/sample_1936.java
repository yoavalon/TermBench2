public class sample_1936 {
    public static double decay_function(double value, double rate, int precision) {
        return Math.round(value * (1 - rate) * Math.pow(10, precision)) / Math.pow(10, precision);
    }

    public static double[] simulate_decay(double initial_value, double decay_rate, int precision, int steps) {
        double[] values = new double[steps + 1];
        values[0] = initial_value;
        for (int i = 0; i < steps; i++) {
            double current_value = values[i];
            double new_value = decay_function(current_value, decay_rate, precision);
            values[i + 1] = new_value;
        }
        return values;
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double decay_rate = 0.1;
        int precision = 4;
        int steps = 10;
        double[] result = simulate_decay(initial_value, decay_rate, precision, steps);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}