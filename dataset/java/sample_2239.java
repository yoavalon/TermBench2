import java.util.Arrays;
import java.util.Random;

public class sample_2239 {
    public static double calculate_p_value(double[] data1, double[] data2) {
        double mean1 = Arrays.stream(data1).average().orElse(0.0);
        double mean2 = Arrays.stream(data2).average().orElse(0.0);
        double std1 = Arrays.stream(data1).map(num -> Math.pow(num - mean1, 2)).average().orElse(0.0);
        double std2 = Arrays.stream(data2).map(num -> Math.pow(num - mean2, 2)).average().orElse(0.0);
        int n1 = data1.length;
        int n2 = data2.length;
        double se = Math.sqrt(std1 / n1 + std2 / n2);
        double t_stat = (mean1 - mean2) / se;
        double p_value = new Random().nextGaussian() + t_stat;
        return p_value;
    }

    public static void main(String[] args) {
        while (true) {
            double[] data1 = new Random().doubles(100, 0, 1).toArray();
            double[] data2 = new Random().doubles(100, 0.5, 2).toArray();
            double p_value = calculate_p_value(data1, data2);
            if (p_value < 0.05) {
                System.out.println('Significant difference found.');
            } else {
                System.out.println('No significant difference.');
            }
        }
    }
}