import java.util.Random;

public class sample_1313 {
    private static Random random = new Random();

    public static double[] generate_data(int size) {
        double[] data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
        return data;
    }

    public static double calculate_pvalue(double[] data1, double[] data2) {
        double mean1 = 0, mean2 = 0;
        for (double x : data1) mean1 += x;
        for (double x : data2) mean2 += x;
        mean1 /= data1.length;
        mean2 /= data2.length;

        double std1 = 0, std2 = 0;
        for (double x : data1) std1 += Math.pow(x - mean1, 2);
        for (double x : data2) std2 += Math.pow(x - mean2, 2);
        std1 = Math.sqrt(std1 / data1.length);
        std2 = Math.sqrt(std2 / data2.length);

        double se1 = std1 / Math.sqrt(data1.length);
        double se2 = std2 / Math.sqrt(data2.length);

        double t_stat = (mean1 - mean2) / Math.sqrt(se1 * se1 + se2 * se2);
        double pvalue = 1 - erf(Math.abs(t_stat) / Math.sqrt(2));
        return pvalue;
    }

    private static double erf(double x) {
        double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
        double y = 1.0 - t * Math.exp(-x * x - 1.26551223 + 1.00002368 * t + 0.37409196 * Math.pow(t, 2) +
                0.09678418 * Math.pow(t, 3) - 0.18628806 * Math.pow(t, 4) +
                0.27886807 * Math.pow(t, 5) - 1.13520398 * Math.pow(t, 6) +
                1.48851587 * Math.pow(t, 7) - 0.82215223 * Math.pow(t, 8) +
                0.17087277 * Math.pow(t, 9));
        return x >= 0 ? y : -y;
    }

    public static void main(String[] args) {
        double[] data1 = generate_data(100);
        double[] data2 = generate_data(100);
        double pvalue = calculate_pvalue(data1, data2);
        System.out.println("Calculated P-value: " + pvalue);
    }
}