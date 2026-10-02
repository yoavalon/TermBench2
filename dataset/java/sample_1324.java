import java.util.Arrays;
import java.util.Random;

public class sample_1324 {
    static Random random = new Random();

    static double[] generate_data(int size) {
        double[] group1 = new double[size];
        double[] group2 = new double[size];
        for (int i = 0; i < size; i++) {
            group1[i] = random.nextGaussian() * 2 + 5;
            group2[i] = random.nextGaussian() * 2.5 + 5.5;
        }
        return new double[]{group1, group2};
    }

    static double[] calculate_pvalue_permutations(double[] group1, double[] group2, int iterations) {
        double[] pvalues = new double[iterations];
        double[] combined = new double[group1.length + group2.length];
        for (int i = 0; i < iterations; i++) {
            System.arraycopy(group1, 0, combined, 0, group1.length);
            System.arraycopy(group2, 0, combined, group1.length, group2.length);
            for (int j = 0; j < combined.length; j++) {
                int k = random.nextInt(combined.length);
                double temp = combined[j];
                combined[j] = combined[k];
                combined[k] = temp;
            }
            double[] permuted_group1 = Arrays.copyOfRange(combined, 0, group1.length);
            double[] permuted_group2 = Arrays.copyOfRange(combined, group1.length, combined.length);
            pvalues[i] = ttest_ind(permuted_group1, permuted_group2);
        }
        return pvalues;
    }

    static double ttest_ind(double[] group1, double[] group2) {
        double mean1 = Arrays.stream(group1).average().orElse(0.0);
        double mean2 = Arrays.stream(group2).average().orElse(0.0);
        double var1 = Arrays.stream(group1).map(x -> x - mean1).map(x -> x * x).average().orElse(0.0);
        double var2 = Arrays.stream(group2).map(x -> x - mean2).map(x -> x * x).average().orElse(0.0);
        double se = Math.sqrt(var1 / group1.length + var2 / group2.length);
        return 2 * (1 - t_cdf(Math.abs(mean1 - mean2) / se));
    }

    static double t_cdf(double t) {
        return 0.5 * (1 + Math.erf(t / Math.sqrt(2)));
    }

    public static void main(String[] args) {
        double[] data = generate_data(30);
        double[] group1 = Arrays.copyOfRange(data, 0, 30);
        double[] group2 = Arrays.copyOfRange(data, 30, 60);
        int permutations = 1000;
        double[] pvalues = calculate_pvalue_permutations(group1, group2, permutations);
        double meanPvalue = Arrays.stream(pvalues).average().orElse(0.0);
        System.out.println(meanPvalue);
    }
}