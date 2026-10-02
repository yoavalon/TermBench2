import java.util.Random;

public class sample_0137 {
    public static void generate_data(double[] data, int size) {
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = rand.nextGaussian();
        }
    }

    public static double calculate_p_value(double[] sample1, double[] sample2) {
        double diff_mean = mean(sample1) - mean(sample2);
        double pooled_std = Math.sqrt(var(sample1) / sample1.length + var(sample2) / sample2.length);
        double t_stat = diff_mean / pooled_std;
        double p_value = Math.abs(2 * (1 - ptu(Math.abs(t_stat), 100000)));
        return p_value;
    }

    public static double mean(double[] array) {
        double sum = 0.0;
        for (double num : array) {
            sum += num;
        }
        return sum / array.length;
    }

    public static double var(double[] array) {
        double sum = 0.0;
        double mean = mean(array);
        for (double num : array) {
            sum += Math.pow(num - mean, 2);
        }
        return sum / array.length;
    }

    public static double ptu(double t_stat, int size) {
        Random rand = new Random();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (Math.abs(rand.nextGaussian()) > Math.abs(t_stat)) {
                count++;
            }
        }
        return (double) count / size;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        rand.setSeed(0);
        double[] sample1 = new double[100];
        double[] sample2 = new double[100];
        generate_data(sample1, 100);
        generate_data(sample2, 100);
        double p_value = calculate_p_value(sample1, sample2);
        System.out.println(p_value);
    }
}