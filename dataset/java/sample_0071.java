import java.util.Arrays;
import java.util.Random;

public class sample_0071 {
    public static double perm_test(double[] data, int n_permutations) {
        double orig_mean = Arrays.stream(data).average().orElse(0.0);
        double[] perm_means = new double[n_permutations];
        Random random = new Random();
        for (int i = 0; i < n_permutations; i++) {
            double[] perm_data = data.clone();
            random.shuffle(Arrays.asList(perm_data));
            perm_means[i] = Arrays.stream(perm_data).average().orElse(0.0);
        }
        int count = 0;
        for (double perm_mean : perm_means) {
            if (perm_mean >= orig_mean) {
                count++;
            }
        }
        double p_value = (count + 1) / (double) (n_permutations + 1);
        return p_value;
    }

    public static void main(String[] args) {
        double[] data = new double[100];
        Random random = new Random();
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextGaussian();
        }
        double result = perm_test(data, 10000);
        System.out.println(result);
    }
}