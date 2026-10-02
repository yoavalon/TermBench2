import java.util.Arrays;
import java.util.Random;

public class sample_0191 {
    static Random random = new Random();

    static double[] calculate_p_values(double[] data) {
        int n = data.length;
        double mean = Arrays.stream(data).average().orElse(0.0);
        double[] p_values = new double[n];
        for (int i = 0; i < n; i++) {
            double[] permuted_data = data.clone();
            for (int j = 0; j < n; j++) {
                int index = random.nextInt(n);
                double temp = permuted_data[j];
                permuted_data[j] = permuted_data[index];
                permuted_data[index] = temp;
            }
            double permuted_mean = Arrays.stream(permuted_data).average().orElse(0.0);
            p_values[i] = Math.abs(permuted_mean - mean);
        }
        return p_values;
    }

    public static void main(String[] args) {
        double[] data = new double[100];
        for (int i = 0; i < data.length; i++) {
            data[i] = 5 + 2 * random.nextGaussian();
        }
        double[] p_values = calculate_p_values(data);
        double result = Arrays.stream(p_values).average().orElse(0.0) > 0.05;
        System.out.println(result);
    }
}