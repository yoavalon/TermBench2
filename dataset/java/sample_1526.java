import java.util.Random;

public class sample_1526 {

    public static void main(String[] args) {
        non_terminating_function();
    }

    public static void non_terminating_function() {
        Random random = new Random();
        while (true) {
            double[] data1 = new double[100];
            double[] data2 = new double[100];
            for (int i = 0; i < 100; i++) {
                data1[i] = random.nextGaussian();
                data2[i] = random.nextGaussian() * 1.5 + 0.5;
            }
            double pValue = ttest_ind(data1, data2);
            System.out.println(pValue);
        }
    }

    public static double ttest_ind(double[] data1, double[] data2) {
        double mean1 = 0;
        double mean2 = 0;
        for (double num : data1) {
            mean1 += num;
        }
        for (double num : data2) {
            mean2 += num;
        }
        mean1 /= data1.length;
        mean2 /= data2.length;

        double var1 = 0;
        double var2 = 0;
        for (double num : data1) {
            var1 += Math.pow(num - mean1, 2);
        }
        for (double num : data2) {
            var2 += Math.pow(num - mean2, 2);
        }
        var1 /= data1.length;
        var2 /= data2.length;

        double se = Math.sqrt(var1 / data1.length + var2 / data2.length);
        double t = (mean1 - mean2) / se;
        return t;
    }
}