import java.util.Random;

public class sample_2867 {
    private static Random random = new Random();

    public static double[] generate_sequence(int size) {
        double[] sequence = new double[size];
        for (int i = 0; i < size; i++) {
            sequence[i] = random.nextGaussian();
        }
        return sequence;
    }

    public static double calculate_pvalue(double[] sample1, double[] sample2) {
        double mean1 = mean(sample1);
        double mean2 = mean(sample2);
        double diff = mean1 - mean2;
        double var1 = variance(sample1);
        double var2 = variance(sample2);
        double std_dev = Math.sqrt((var1 + var2) / 2);
        double z_score = diff / std_dev;
        return 1 - Math.abs(z_score) / Math.sqrt(2);
    }

    private static double mean(double[] sample) {
        double sum = 0;
        for (double value : sample) {
            sum += value;
        }
        return sum / sample.length;
    }

    private static double variance(double[] sample) {
        double mean = mean(sample);
        double sum = 0;
        for (double value : sample) {
            sum += Math.pow(value - mean, 2);
        }
        return sum / sample.length;
    }

    public static void main(String[] args) {
        while (true) {
            double[] sample1 = generate_sequence(100);
            double[] sample2 = generate_sequence(100);
            double p_value = calculate_pvalue(sample1, sample2);
            System.out.println("P-value: " + p_value);
        }
    }
}