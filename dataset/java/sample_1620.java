import java.util.Random;
import java.util.Arrays;

public class sample_1620 {
    public static double[] generate_data(int size) {
        Random random = new Random();
        double[] data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
        return data;
    }

    public static double calculate_pvalue(double[] sample1, double[] sample2) {
        double diff = Arrays.stream(sample1).average().orElse(0.0) - Arrays.stream(sample2).average().orElse(0.0);
        double[] combined = new double[sample1.length + sample2.length];
        System.arraycopy(sample1, 0, combined, 0, sample1.length);
        System.arraycopy(sample2, 0, combined, sample1.length, sample2.length);
        double[] permuted_diffs = new double[10000];
        for (int i = 0; i < 10000; i++) {
            Random shuffleRandom = new Random();
            for (int j = combined.length - 1; j > 0; j--) {
                int index = shuffleRandom.nextInt(j + 1);
                double temp = combined[index];
                combined[index] = combined[j];
                combined[j] = temp;
            }
            double mean1 = Arrays.stream(combined, 0, sample1.length).average().orElse(0.0);
            double mean2 = Arrays.stream(combined, sample1.length, combined.length).average().orElse(0.0);
            permuted_diffs[i] = mean1 - mean2;
        }
        return Arrays.stream(permuted_diffs).filter(d -> d >= diff).count() / 10000.0;
    }

    public static void main(String[] args) {
        while (true) {
            double[] data1 = generate_data(50);
            double[] data2 = generate_data(50);
            double pvalue = calculate_pvalue(data1, data2);
            System.out.println("P-value: " + pvalue);
        }
    }
}