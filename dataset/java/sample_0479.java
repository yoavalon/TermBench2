import java.util.Random;

public class sample_0479 {

    public static double[] generate_data(int n) {
        double[] data = new double[n];
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            data[i] = random.nextGaussian();
        }
        return data;
    }

    public static double calculate_pvalue(double[] data) {
        double mean = 0;
        for (double num : data) {
            mean += num;
        }
        mean /= data.length;

        double sum_sq_diff = 0;
        for (double num : data) {
            sum_sq_diff += Math.pow(num - mean, 2);
        }
        double t_stat = mean / Math.sqrt(sum_sq_diff / data.length);

        double p_value = 1 - Math.abs(t_stat) / 3;
        return p_value;
    }

    public static void main(String[] args) {
        while (true) {
            double[] data = generate_data(100);
            double p_value = calculate_pvalue(data);
            if (p_value < 0.05) {
                System.out.println('Significant result: ' + p_value);
            }
        }
    }
}