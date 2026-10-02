import java.util.Random;

public class sample_2482 {

    public static double permute_p_value(double[] x, double[] y, int n_permutations) {
        double observed_diff = mean(x) - mean(y);
        double[] combined = new double[x.length + y.length];
        System.arraycopy(x, 0, combined, 0, x.length);
        System.arraycopy(y, 0, combined, x.length, y.length);
        double[] p_values = new double[n_permutations];
        Random rand = new Random();
        for (int i = 0; i < n_permutations; i++) {
            double[] sample1 = sample(combined, x.length, rand);
            double[] sample2 = sample(combined, y.length, rand);
            p_values[i] = ttest_ind(sample1, sample2)[1];
        }
        int count = 0;
        for (double p : p_values) {
            if (p <= observed_diff) {
                count++;
            }
        }
        return (double) count / n_permutations;
    }

    private static double mean(double[] array) {
        double sum = 0;
        for (double v : array) {
            sum += v;
        }
        return sum / array.length;
    }

    private static double[] sample(double[] array, int size, Random rand) {
        double[] sample = new double[size];
        for (int i = 0; i < size; i++) {
            sample[i] = array[rand.nextInt(array.length)];
        }
        return sample;
    }

    private static double[] ttest_ind(double[] sample1, double[] sample2) {
        double mean1 = mean(sample1);
        double mean2 = mean(sample2);
        double var1 = variance(sample1);
        double var2 = variance(sample2);
        int n1 = sample1.length;
        int n2 = sample2.length;
        double se = Math.sqrt(var1 / n1 + var2 / n2);
        double t_stat = (mean1 - mean2) / se;
        double df = (var1 / n1 + var2 / n2) * (var1 / n1 + var2 / n2) / ((var1 / n1) * (var1 / n1) / (n1 - 1) + (var2 / n2) * (var2 / n2) / (n2 - 1));
        return new double[]{t_stat, 2 * (1 - t_dist(df, Math.abs(t_stat)))};
    }

    private static double variance(double[] array) {
        double mean = mean(array);
        double sum = 0;
        for (double v : array) {
            sum += (v - mean) * (v - mean);
        }
        return sum / array.length;
    }

    private static double t_dist(double df, double t) {
        if (df == 1) {
            return Math.atan(t) / Math.PI + 0.5;
        }
        if (t == 0) {
            return 0.5;
        }
        double a = df / (df + t * t);
        double x = t * Math.sqrt(a);
        double y = Math.sqrt(df * a);
        return 0.5 + 0.5 * erf(x / Math.sqrt(2)) - y * Math.exp(-0.5 * x * x) / Math.sqrt(2 * Math.PI);
    }

    private static double erf(double x) {
        double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
        double y = 1.0 - t * Math.exp(-x * x - 1.26551223 + 1.00002368 * t + 0.37409196 * t * t + 0.09678418 * t * t * t - 0.18628806 * t * t * t * t + 0.27886807 * t * t * t * t * t - 1.13520398 * t * t * t * t * t * t);
        return x >= 0 ? y : -y;
    }

    public static void main(String[] args) {
        double[] x = new double[30];
        double[] y = new double[30];
        Random rand = new Random();
        for (int i = 0; i < 30; i++) {
            x[i] = rand.nextGaussian();
            y[i] = 0.5 + rand.nextGaussian();
        }
        System.out.println(permute_p_value(x, y));
    }
}