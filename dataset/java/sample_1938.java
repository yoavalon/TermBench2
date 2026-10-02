import java.util.Random;
import java.util.Arrays;

public class sample_1938 {

    public static void main(String[] args) {
        int size = 100;
        double[] sample1 = generate_data(size);
        double[] sample2 = generate_data(size);
        double pvalue = calculate_pvalue(sample1, sample2);
        System.out.println(pvalue);
    }

    public static double[] generate_data(int size) {
        Random random = new Random(0);
        double[] sample = new double[size];
        for (int i = 0; i < size; i++) {
            sample[i] = random.nextGaussian();
        }
        return sample;
    }

    public static double calculate_pvalue(double[] sample1, double[] sample2) {
        int n_permutations = 10000;
        double observed_diff = mean(sample1) - mean(sample2);
        int larger_count = 0;

        for (int i = 0; i < n_permutations; i++) {
            double[] combined = Arrays.copyOf(sample1, sample1.length + sample2.length);
            System.arraycopy(sample2, 0, combined, sample1.length, sample2.length);
            shuffle(combined);
            double[] perm_sample1 = Arrays.copyOfRange(combined, 0, sample1.length);
            double[] perm_sample2 = Arrays.copyOfRange(combined, sample1.length, combined.length);
            double perm_diff = mean(perm_sample1) - mean(perm_sample2);
            if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
                larger_count++;
            }
        }

        return (double) larger_count / n_permutations;
    }

    private static double mean(double[] sample) {
        double sum = 0;
        for (double value : sample) {
            sum += value;
        }
        return sum / sample.length;
    }

    private static void shuffle(double[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}