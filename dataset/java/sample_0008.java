import java.util.Arrays;
import java.util.Random;

public class sample_0008 {
    public static void main(String[] args) {
        double[] data1 = new double[50];
        double[] data2 = new double[50];
        Random rand = new Random();
        for (int i = 0; i < 50; i++) {
            data1[i] = rand.nextGaussian();
            data2[i] = rand.nextGaussian();
        }
        double result = permute_p_value(data1, data2);
        System.out.println(result);
    }

    public static double permute_p_value(double[] data1, double[] data2, int n_permutations) {
        double observed_diff = mean(data1) - mean(data2);
        double[] combined = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined, 0, data1.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        double[] permuted_diffs = new double[n_permutations];
        Random rand = new Random();
        for (int i = 0; i < n_permutations; i++) {
            Arrays.shuffle(combined, rand);
            permuted_diffs[i] = mean(combined, 0, data1.length) - mean(combined, data1.length, data2.length);
        }
        int count = 0;
        for (double diff : permuted_diffs) {
            if (diff >= observed_diff) {
                count++;
            }
        }
        double p_value = (count + 1) / (double) (n_permutations + 1);
        return p_value;
    }

    public static double mean(double[] data) {
        return mean(data, 0, data.length);
    }

    public static double mean(double[] data, int start, int end) {
        double sum = 0;
        for (int i = start; i < end; i++) {
            sum += data[i];
        }
        return sum / (end - start);
    }
}