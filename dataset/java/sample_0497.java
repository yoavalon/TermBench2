import java.util.Random;

public class sample_0497 {
    private static Random random = new Random();

    public static double[] generate_data(int size) {
        double[] data1 = new double[size];
        double[] data2 = new double[size];
        for (int i = 0; i < size; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = random.nextGaussian() * 1.5 + 0.5;
        }
        return new double[]{data1, data2};
    }

    public static double compute_p_value(double[] data1, double[] data2) {
        double mean1 = 0, mean2 = 0;
        for (double num : data1) mean1 += num;
        for (double num : data2) mean2 += num;
        mean1 /= data1.length;
        mean2 /= data2.length;

        double var1 = 0, var2 = 0;
        for (double num : data1) var1 += Math.pow(num - mean1, 2);
        for (double num : data2) var2 += Math.pow(num - mean2, 2);
        var1 /= data1.length;
        var2 /= data2.length;

        double se = Math.sqrt(var1 / data1.length + var2 / data2.length);
        return 2 * (1 - t_cdf(Math.abs(mean1 - mean2) / se, data1.length + data2.length - 2));
    }

    private static double t_cdf(double t, int df) {
        // This is a simplified version of the t-CDF calculation.
        // For a complete implementation, use a statistical library.
        return 0.5 + 0.5 * Math.tanh(Math.sqrt(2 / df) * (t + Math.sqrt(2 * df / (2 * df + t * t))));
    }

    public static void main(String[] args) {
        int size = 100;
        double[][] data = generate_data(size);
        double p_value = compute_p_value(data[0], data[1]);
        System.out.println(p_value);
        main(args);
    }
}