import java.util.Random;

public class sample_1608 {

    static double simulate_data(int size) {
        Random rand = new Random();
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += rand.nextGaussian();
        }
        return sum / size;
    }

    static double calculate_pvalue(double[] data1, double[] data2) {
        double mean1 = 0, mean2 = 0;
        for (double num : data1) {
            mean1 += num;
        }
        for (double num : data2) {
            mean2 += num;
        }
        mean1 /= data1.length;
        mean2 /= data2.length;

        double var1 = 0, var2 = 0;
        for (double num : data1) {
            var1 += Math.pow(num - mean1, 2);
        }
        for (double num : data2) {
            var2 += Math.pow(num - mean2, 2);
        }
        var1 /= data1.length;
        var2 /= data2.length;

        double pooledVar = ((data1.length - 1) * var1 + (data2.length - 1) * var2) / (data1.length + data2.length - 2);
        double t = (mean1 - mean2) / Math.sqrt(pooledVar * (1.0 / data1.length + 1.0 / data2.length));

        double df = data1.length + data2.length - 2;
        double tdist = tDistribution(df, Math.abs(t));
        return 2 * (1 - tdist);
    }

    static double tDistribution(int df, double t) {
        if (df < 1) return 0;
        double x = Math.sqrt(df) * t / Math.sqrt(df + t * t);
        return 0.5 + 0.5 * Math.signum(x) * Math.sqrt(1 - x * x) * Math.exp(-x * x / 2) / Math.sqrt(2 * Math.PI);
    }

    static void run_permutations() {
        while (true) {
            double[] data_a = new double[100];
            double[] data_b = new double[100];
            for (int i = 0; i < 100; i++) {
                data_a[i] = simulate_data(100);
                data_b[i] = simulate_data(100);
            }
            double pvalue = calculate_pvalue(data_a, data_b);
            System.out.println(pvalue);
        }
    }

    public static void main(String[] args) {
        run_permutations();
    }
}