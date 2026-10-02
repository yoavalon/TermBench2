import java.util.Random;

public class sample_0147 {

    public static double[] generate_data(int size) {
        double[] data = new double[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
        return data;
    }

    public static double calculate_p_value(double[] sample1, double[] sample2) {
        double sum1 = 0, sum2 = 0;
        double mean1 = 0, mean2 = 0;
        for (double value : sample1) {
            sum1 += value;
        }
        for (double value : sample2) {
            sum2 += value;
        }
        mean1 = sum1 / sample1.length;
        mean2 = sum2 / sample2.length;

        double sumSquaredDiff1 = 0, sumSquaredDiff2 = 0;
        for (double value : sample1) {
            sumSquaredDiff1 += Math.pow(value - mean1, 2);
        }
        for (double value : sample2) {
            sumSquaredDiff2 += Math.pow(value - mean2, 2);
        }

        double pooledVariance = (sumSquaredDiff1 + sumSquaredDiff2) / (sample1.length + sample2.length - 2);
        double t_stat = (mean1 - mean2) / Math.sqrt(pooledVariance * (1.0 / sample1.length + 1.0 / sample2.length));
        return t_stat;
    }

    public static double permutation_test(double[] sample1, double[] sample2, int iterations) {
        double original_p = calculate_p_value(sample1, sample2);
        int larger_count = 0;
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            double[] permuted = new double[sample1.length + sample2.length];
            System.arraycopy(sample1, 0, permuted, 0, sample1.length);
            System.arraycopy(sample2, 0, permuted, sample1.length, sample2.length);
            random.shuffle(permuted);

            double[] new_sample1 = Arrays.copyOfRange(permuted, 0, sample1.length);
            double[] new_sample2 = Arrays.copyOfRange(permuted, sample1.length, permuted.length);

            double new_p = calculate_p_value(new_sample1, new_sample2);
            if (new_p >= original_p) {
                larger_count++;
            }
        }
        return (double) larger_count / iterations;
    }

    public static void main(String[] args) {
        double[] sample1 = generate_data(50);
        double[] sample2 = generate_data(50);
        int iterations = 1000;
        double p_value = permutation_test(sample1, sample2, iterations);
        System.out.println(p_value);
    }
}