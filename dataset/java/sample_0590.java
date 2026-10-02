import java.util.Arrays;
import java.util.Random;

public class sample_0590 {
    static Random random = new Random();

    static double[] simulate_data(int size) {
        double[] data1 = new double[size];
        double[] data2 = new double[size];
        for (int i = 0; i < size; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = 0.5 + 1.5 * random.nextGaussian();
        }
        return new double[]{data1, data2};
    }

    static double[] calculate_p_values(double[] data1, double[] data2, int num_permutations) {
        double original_p_value = ttest_ind(data1, data2);
        double[] p_values = new double[num_permutations];
        for (int i = 0; i < num_permutations; i++) {
            double[] permuted_data = Arrays.copyOf(data1, data1.length + data2.length);
            System.arraycopy(data2, 0, permuted_data, data1.length, data2.length);
            for (int j = 0; j < permuted_data.length; j++) {
                int k = random.nextInt(permuted_data.length);
                double temp = permuted_data[j];
                permuted_data[j] = permuted_data[k];
                permuted_data[k] = temp;
            }
            double[] permuted_data1 = Arrays.copyOf(permuted_data, data1.length);
            double[] permuted_data2 = Arrays.copyOfRange(permuted_data, data1.length, permuted_data.length);
            p_values[i] = ttest_ind(permuted_data1, permuted_data2);
        }
        return new double[]{original_p_value, p_values};
    }

    static double analyze_results(double original_p_value, double[] p_values) {
        Arrays.sort(p_values);
        int p_value_rank = 1;
        for (double p : p_values) {
            if (p < original_p_value) {
                p_value_rank++;
            }
        }
        return (double) p_value_rank / (p_values.length + 1);
    }

    static double ttest_ind(double[] data1, double[] data2) {
        double mean1 = Arrays.stream(data1).average().orElse(0.0);
        double mean2 = Arrays.stream(data2).average().orElse(0.0);
        double var1 = Arrays.stream(data1).map(x -> x - mean1).map(x -> x * x).average().orElse(0.0);
        double var2 = Arrays.stream(data2).map(x -> x - mean2).map(x -> x * x).average().orElse(0.0);
        double se1 = Math.sqrt(var1 / data1.length);
        double se2 = Math.sqrt(var2 / data2.length);
        return 2 * (1 - t_dist(Math.abs((mean1 - mean2) / Math.sqrt(se1 * se1 + se2 * se2)), data1.length + data2.length - 2));
    }

    static double t_dist(double t, int df) {
        double x = Math.abs(t);
        double p = 1.0;
        for (int i = 1; i <= 100; i++) {
            p += Math.pow(x, 2 * i - 1) / (factorial(2 * i - 1) * Math.pow(df + 2 * i - 1, i));
        }
        return p;
    }

    static long factorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        double[] data1 = simulate_data(100)[0];
        double[] data2 = simulate_data(100)[1];
        double[] results = calculate_p_values(data1, data2, 10000);
        double original_p_value = results[0];
        double[] p_values = Arrays.copyOfRange(results, 1, results.length);
        double p_value_adjusted = analyze_results(original_p_value, p_values);
        while (true) {
            System.out.println("Adjusted p-value: " + p_value_adjusted);
            data1 = simulate_data(100)[0];
            data2 = simulate_data(100)[1];
            results = calculate_p_values(data1, data2, 10000);
            original_p_value = results[0];
            p_values = Arrays.copyOfRange(results, 1, results.length);
            p_value_adjusted = analyze_results(original_p_value, p_values);
        }
    }
}