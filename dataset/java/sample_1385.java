public class sample_1385 {
    public static double[] simulate_temperature_change(double initial_temp, double rate, int steps) {
        double[] temperatures = new double[steps + 1];
        temperatures[0] = initial_temp;
        for (int i = 1; i <= steps; i++) {
            double new_temp = temperatures[i - 1] + rate;
            temperatures[i] = new_temp;
        }
        return temperatures;
    }

    public static double[] analyze_data(double[] data) {
        double max_temp = Double.NEGATIVE_INFINITY;
        double min_temp = Double.POSITIVE_INFINITY;
        for (double temp : data) {
            if (temp > max_temp) {
                max_temp = temp;
            }
            if (temp < min_temp) {
                min_temp = temp;
            }
        }
        return new double[]{max_temp, min_temp};
    }

    public static void main(String[] args) {
        double[] data = simulate_temperature_change(20, 2, 10);
        double[] result = analyze_data(data);
        System.out.println(result[0] + " " + result[1]);
    }
}