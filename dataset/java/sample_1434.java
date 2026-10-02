import java.util.Random;
import java.util.Arrays;

public class sample_1434 {

    public static double[] generate_data(int size) {
        Random rand = new Random();
        double[] data1 = new double[size];
        double[] data2 = new double[size];
        for (int i = 0; i < size; i++) {
            data1[i] = rand.nextGaussian();
            data2[i] = rand.nextGaussian() + 0.5;
        }
        return new double[]{data1, data2};
    }

    public static double[] perform_ttest(double[] data1, double[] data2) {
        double mean1 = Arrays.stream(data1).average().orElse(0.0);
        double mean2 = Arrays.stream(data2).average().orElse(0.0);
        double var1 = Arrays.stream(data1).map(x -> x - mean1).map(x -> x * x).average().orElse(0.0);
        double var2 = Arrays.stream(data2).map(x -> x - mean2).map(x -> x * x).average().orElse(0.0);
        double se1 = Math.sqrt(var1 / data1.length);
        double se2 = Math.sqrt(var2 / data2.length);
        double t_stat = (mean1 - mean2) / Math.sqrt(se1 * se1 + se2 * se2);
        double p_value = 2 * (1 - tdist(t_stat, Math.sqrt(se1 * se1 + se2 * se2)));
        return new double[]{t_stat, p_value};
    }

    public static double[] permute_data(double[] data1, double[] data2, int iterations) {
        double[] p_values = new double[iterations];
        double[] combined = new double[data1.length + data2.length];
        Random rand = new Random();
        for (int i = 0; i < iterations; i++) {
            System.arraycopy(data1, 0, combined, 0, data1.length);
            System.arraycopy(data2, 0, combined, data1.length, data2.length);
            for (int j = 0; j < combined.length; j++) {
                int k = rand.nextInt(combined.length);
                double temp = combined[j];
                combined[j] = combined[k];
                combined[k] = temp;
            }
            double[] permuted_data1 = Arrays.copyOfRange(combined, 0, data1.length);
            double[] permuted_data2 = Arrays.copyOfRange(combined, data1.length, combined.length);
            double[] ttest_result = perform_ttest(permuted_data1, permuted_data2);
            p_values[i] = ttest_result[1];
        }
        return p_values;
    }

    public static boolean analyze_p_values(double[] p_values, double original_p_value, double alpha) {
        int count = 0;
        for (double p : p_values) {
            if (p <= original_p_value) {
                count++;
            }
        }
        double p_value_permutation = (double) count / p_values.length;
        return p_value_permutation < alpha;
    }

    public static double tdist(double t, double se) {
        return 0.5 * (1 + Math.erf(t / (se * Math.sqrt(2))));
    }

    public static void main(String[] args) {
        double[] data = generate_data(30);
        double[] ttest_result = perform_ttest(data[0], data[1]);
        double[] p_values = permute_data(data[0], data[1], 1000);
        boolean result = analyze_p_values(p_values, ttest_result[1], 0.05);
        System.out.println(result);
    }
}