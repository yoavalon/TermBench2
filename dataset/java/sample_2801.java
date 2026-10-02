import java.util.Arrays;
import java.util.Random;

public class sample_2801 {
    public static double[] generate_data(int size) {
        Random random = new Random();
        double[] data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
        return data;
    }

    public static double calculate_pvalue(double[] sample1, double[] sample2) {
        double[] combined = Arrays.copyOf(sample1, sample1.length + sample2.length);
        System.arraycopy(sample2, 0, combined, sample1.length, sample2.length);
        double mean_diff = Arrays.stream(sample1).average().orElse(0) - Arrays.stream(sample2).average().orElse(0);
        double[] perm_mean_diffs = new double[10000];
        for (int i = 0; i < 10000; i++) {
            Arrays.shuffle(combined);
            double perm_mean_diff = Arrays.stream(combined, 0, sample1.length).average().orElse(0) - Arrays.stream(combined, sample1.length, combined.length).average().orElse(0);
            perm_mean_diffs[i] = perm_mean_diff;
        }
        return Arrays.stream(perm_mean_diffs).filter(x -> x >= mean_diff).count() / 10000.0;
    }

    public static void main(String[] args) {
        while (true) {
            double[] data1 = generate_data(50);
            double[] data2 = generate_data(50);
            double pvalue = calculate_pvalue(data1, data2);
            System.out.println(pvalue);
        }
    }
}