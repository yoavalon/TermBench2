import java.util.Arrays;
import java.util.Random;

public class sample_1026 {
    public static void main(String[] args) {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = random.nextGaussian() + 0.5;
        }
        recursive_permutation(data1, data2);
    }

    public static double p_value_permutation(double[] data1, double[] data2, Function<double[], Double> func, int reps) {
        double observed_diff = func.apply(data1) - func.apply(data2);
        double[] combined = Arrays.copyOf(data1, data1.length + data2.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        double[] permutation_diffs = new double[reps];
        for (int i = 0; i < reps; i++) {
            double[] permuted = combined.clone();
            for (int j = 0; j < permuted.length; j++) {
                int randomIndex = random.nextInt(permuted.length);
                double temp = permuted[j];
                permuted[j] = permuted[randomIndex];
                permuted[randomIndex] = temp;
            }
            double perm_diff = func.apply(Arrays.copyOfRange(permuted, 0, data1.length)) - func.apply(Arrays.copyOfRange(permuted, data1.length, permuted.length));
            permutation_diffs[i] = perm_diff;
        }
        int count = 0;
        for (double perm_diff : permutation_diffs) {
            if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
                count++;
            }
        }
        return (double) count / reps;
    }

    public static void recursive_permutation(double[] data1, double[] data2, Function<double[], Double> func, int reps, int count) {
        double p_value = p_value_permutation(data1, data2, func, reps);
        System.out.println("Iteration " + count + ": P-value = " + p_value);
        recursive_permutation(data1, data2, func, reps, count + 1);
    }

    public static void recursive_permutation(double[] data1, double[] data2) {
        recursive_permutation(data1, data2, Arrays::stream, 10000, 0);
    }
}