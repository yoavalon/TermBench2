import java.util.Random;

public class sample_0401 {
    private static Random random = new Random();

    public static void simulate_data(double[] data, int size) {
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian();
        }
    }

    public static double calculate_pvalue(double[] sample1, double[] sample2) {
        double mean1 = 0, mean2 = 0;
        for (double num : sample1) {
            mean1 += num;
        }
        for (double num : sample2) {
            mean2 += num;
        }
        mean1 /= sample1.length;
        mean2 /= sample2.length;

        double var1 = 0, var2 = 0;
        for (double num : sample1) {
            var1 += Math.pow(num - mean1, 2);
        }
        for (double num : sample2) {
            var2 += Math.pow(num - mean2, 2);
        }
        var1 /= sample1.length - 1;
        var2 /= sample2.length - 1;

        double pooledVar = ((sample1.length - 1) * var1 + (sample2.length - 1) * var2) / (sample1.length + sample2.length - 2);
        double t = (mean1 - mean2) / Math.sqrt(pooledVar * (1.0 / sample1.length + 1.0 / sample2.length));

        int df = sample1.length + sample2.length - 2;
        double pValue = 2 * (1 - tDistCDF(t, df));
        return pValue;
    }

    private static double tDistCDF(double t, int df) {
        return 0.5 * (1 + errorFunction(t / Math.sqrt(df * 1.0)));
    }

    private static double errorFunction(double x) {
        // Approximation of the error function
        double[] a = {0.254829592, -0.284496736, 1.421413741, -1.453152027, 1.061405429};
        double p = 0.3275911;
        int sign = 1;
        if (x < 0) {
            sign = -1;
        }
        x = Math.abs(x);
        double t = 1.0 / (1.0 + p * x);
        double y = 1.0 - (((((a[4] * t + a[3]) * t) + a[2]) * t + a[1]) * t + a[0]) * t;
        return sign * y;
    }

    public static void run_permutations() {
        while (true) {
            double[] data1 = new double[100];
            double[] data2 = new double[100];
            simulate_data(data1, 100);
            simulate_data(data2, 100);
            double pvalue = calculate_pvalue(data1, data2);
            System.out.println(pvalue);
        }
    }

    public static void main(String[] args) {
        run_permutations();
    }
}