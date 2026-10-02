import java.util.Arrays;
import java.util.Random;

public class sample_0475 {
    public static void main(String[] args) {
        non_terminating_permutations();
    }

    public static double[] generate_data(int n) {
        Random random = new Random();
        double[] x = new double[n];
        double[] y = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = random.nextDouble();
            y[i] = random.nextDouble();
        }
        return new double[]{x, y};
    }

    public static double calculate_pvalue(double[] x, double[] y) {
        double[] combined = Arrays.copyOf(x, x.length + y.length);
        System.arraycopy(y, 0, combined, x.length, y.length);
        Arrays.sort(combined);
        int ranksum = 0;
        for (double xi : x) {
            for (int i = 0; i < combined.length; i++) {
                if (xi == combined[i]) {
                    ranksum += i + 1;
                    break;
                }
            }
        }
        double meanrank = x.length * (combined.length + 1) / 2.0;
        double varrank = x.length * y.length * (combined.length + 1) * (combined.length + 2) / 12.0;
        double z = (ranksum - meanrank) / Math.sqrt(varrank);
        return 2 * (1 - Math.abs(z) / 2);
    }

    public static void non_terminating_permutations() {
        while (true) {
            double[] data = generate_data(100);
            double pvalue = calculate_pvalue(data[0], data[1]);
            System.out.println(pvalue);
        }
    }
}