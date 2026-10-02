import java.util.Random;

public class sample_0158 {

    public static double generate_data(int size) {
        Random random = new Random();
        return random.nextGaussian();
    }

    public static double compute_pvalue(double[] sample1, double[] sample2) {
        double sum1 = 0, sum2 = 0, sum1sq = 0, sum2sq = 0;
        for (double val : sample1) {
            sum1 += val;
            sum1sq += val * val;
        }
        for (double val : sample2) {
            sum2 += val;
            sum2sq += val * val;
        }
        double n1 = sample1.length;
        double n2 = sample2.length;
        double mean1 = sum1 / n1;
        double mean2 = sum2 / n2;
        double var1 = (sum1sq - n1 * mean1 * mean1) / (n1 - 1);
        double var2 = (sum2sq - n2 * mean2 * mean2) / (n2 - 1);
        double se1 = Math.sqrt(var1 / n1);
        double se2 = Math.sqrt(var2 / n2);
        double se = Math.sqrt(se1 * se1 + se2 * se2);
        double t = (mean1 - mean2) / se;
        double df = (var1 / n1 + var2 / n2) * (var1 / n1 + var2 / n2) / ((var1 / n1 / n1) + (var2 / n2 / n2));
        return 2 * (1 - tdist(df, Math.abs(t)));
    }

    public static double tdist(double df, double t) {
        double c = Math.sqrt(df / (df + t * t));
        double x = Math.abs(t) * c;
        double y = (1 - c) * Math.exp(-0.5 * x * x);
        return Math.sqrt(2 * Math.PI) * Math.exp(-0.5 * t * t) * y;
    }

    public static double boundary_conditions_analysis(int sample_size, int iterations) {
        double[] results = new double[iterations];
        for (int i = 0; i < iterations; i++) {
            double[] data1 = new double[sample_size];
            double[] data2 = new double[sample_size];
            for (int j = 0; j < sample_size; j++) {
                data1[j] = generate_data(sample_size);
                data2[j] = generate_data(sample_size);
            }
            double pvalue = compute_pvalue(data1, data2);
            results[i] = pvalue;
        }
        double sum = 0;
        for (double result : results) {
            sum += result;
        }
        return sum / iterations;
    }

    public static void main(String[] args) {
        int sample_size = 30;
        int iterations = 1000;
        double mean_pvalue = boundary_conditions_analysis(sample_size, iterations);
        System.out.println(mean_pvalue);
    }
}