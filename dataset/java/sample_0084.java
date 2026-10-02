import java.util.Arrays;
import java.util.Random;

public class sample_0084 {

    public static double analyze_data(double[] a, double[] b, int n_permutations) {
        double pvalue = permutation_test(a, b, n_permutations);
        return pvalue;
    }

    public static double permutation_test(double[] a, double[] b, int n_permutations) {
        double observed_diff = mean(a) - mean(b);
        double[] combined = Arrays.copyOf(a, a.length + b.length);
        System.arraycopy(b, 0, combined, a.length, b.length);
        Random rand = new Random();
        int count = 0;
        for (int i = 0; i < n_permutations; i++) {
            double[] permuted = combined.clone();
            for (int j = 0; j < permuted.length; j++) {
                int swapIndex = rand.nextInt(permuted.length);
                double temp = permuted[j];
                permuted[j] = permuted[swapIndex];
                permuted[swapIndex] = temp;
            }
            double[] permuted_a = Arrays.copyOfRange(permuted, 0, a.length);
            double[] permuted_b = Arrays.copyOfRange(permuted, a.length, permuted.length);
            double permuted_diff = mean(permuted_a) - mean(permuted_b);
            if (Math.abs(permuted_diff) >= Math.abs(observed_diff)) {
                count++;
            }
        }
        return (double) count / n_permutations;
    }

    public static double mean(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }

    public static void main(String[] args) {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random rand = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = rand.nextGaussian();
            data2[i] = rand.nextGaussian() + 0.5;
        }
        double p_value = analyze_data(data1, data2, 1000);
        System.out.println(p_value);
    }
}