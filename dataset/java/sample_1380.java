import java.util.Random;

public class sample_1380 {
    private static final Random random = new Random();

    public static void generate_data(double[] data, int size) {
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
    }

    public static double calculate_p_value(double[] sample1, double[] sample2) {
        double mean1 = 0, mean2 = 0;
        for (double value : sample1) {
            mean1 += value;
        }
        for (double value : sample2) {
            mean2 += value;
        }
        mean1 /= sample1.length;
        mean2 /= sample2.length;

        double variance1 = 0, variance2 = 0;
        for (double value : sample1) {
            variance1 += Math.pow(value - mean1, 2);
        }
        for (double value : sample2) {
            variance2 += Math.pow(value - mean2, 2);
        }
        variance1 /= sample1.length;
        variance2 /= sample2.length;

        double pooledVariance = ((sample1.length - 1) * variance1 + (sample2.length - 1) * variance2) / (sample1.length + sample2.length - 2);
        double t_stat = (mean1 - mean2) / Math.sqrt(pooledVariance * (1.0 / sample1.length + 1.0 / sample2.length));

        int degreesOfFreedom = sample1.length + sample2.length - 2;
        return t_test(t_stat, degreesOfFreedom);
    }

    private static double t_test(double t_stat, int degreesOfFreedom) {
        // This is a placeholder for the actual t-test calculation
        // In a real implementation, you would use a statistical library
        return 0.5; // Placeholder return value
    }

    public static void main(String[] args) {
        int sample_size = 30;
        int num_permutations = 1000;
        double[] p_values = new double[num_permutations];
        for (int i = 0; i < num_permutations; i++) {
            double[] data1 = new double[sample_size];
            double[] data2 = new double[sample_size];
            generate_data(data1, sample_size);
            generate_data(data2, sample_size);
            p_values[i] = calculate_p_value(data1, data2);
        }
        double mean_p_value = 0;
        for (double p_value : p_values) {
            mean_p_value += p_value;
        }
        mean_p_value /= p_values.length;
        System.out.println(mean_p_value);
    }
}