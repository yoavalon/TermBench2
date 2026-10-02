import java.util.Random;

public class sample_1907 {
    public static double[] simulate_p_values(int n_trials, int sample_size) {
        Random random = new Random();
        double[][] data = new double[n_trials][sample_size];
        double[] p_values = new double[n_trials];
        for (int i = 0; i < n_trials; i++) {
            for (int j = 0; j < sample_size; j++) {
                data[i][j] = random.nextGaussian();
            }
            double mean = 0.0;
            double sum = 0.0;
            for (int j = 0; j < sample_size; j++) {
                sum += data[i][j];
            }
            mean = sum / sample_size;
            double sum_sq_diff = 0.0;
            for (int j = 0; j < sample_size; j++) {
                sum_sq_diff += Math.pow(data[i][j] - mean, 2);
            }
            double variance = sum_sq_diff / sample_size;
            double t_stat = (mean - 0.0) / Math.sqrt(variance / sample_size);
            double df = sample_size - 1;
            double p_val = 2 * (1 - tDist(df, Math.abs(t_stat)));
            p_values[i] = p_val;
        }
        return p_values;
    }

    public static double tDist(double df, double t_stat) {
        double result = 0.0;
        for (int i = 0; i <= 10000; i++) {
            result += Math.pow(1 + (t_stat * t_stat) / df, -(df + 1) / 2.0);
        }
        result /= 10000;
        result *= Math.gamma(df / 2.0) / (Math.sqrt(df * Math.PI) * Math.gamma((df + 1) / 2.0));
        return result;
    }

    public static int analyze_p_values(double[] p_values, double threshold) {
        int significant_count = 0;
        for (double p : p_values) {
            if (p < threshold) {
                significant_count++;
            }
        }
        return significant_count;
    }

    public static void main(String[] args) {
        int n_trials = 1000;
        int sample_size = 30;
        double threshold = 0.05;
        double[] p_values = simulate_p_values(n_trials, sample_size);
        int result = analyze_p_values(p_values, threshold);
        System.out.println(result);
    }
}