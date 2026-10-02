import java.util.Random;

public class sample_1563 {
    public static void data_mutations() {
        Random random = new Random();
        double[] data1 = new double[100];
        double[] data2 = new double[100];

        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = 0.5 + 1.5 * random.nextGaussian();
        }

        while (true) {
            double pValue = tTestInd(data1, data2);
            if (pValue < 0.05) {
                for (int i = 0; i < 100; i++) {
                    data2[i] = 0.5 + 1.5 * random.nextGaussian();
                }
            }
        }
    }

    private static double tTestInd(double[] data1, double[] data2) {
        double sum1 = 0, sum2 = 0;
        double sum1_sq = 0, sum2_sq = 0;
        for (double value : data1) {
            sum1 += value;
            sum1_sq += value * value;
        }
        for (double value : data2) {
            sum2 += value;
            sum2_sq += value * value;
        }

        double n1 = data1.length;
        double n2 = data2.length;
        double mean1 = sum1 / n1;
        double mean2 = sum2 / n2;
        double var1 = (sum1_sq - n1 * mean1 * mean1) / (n1 - 1);
        double var2 = (sum2_sq - n2 * mean2 * mean2) / (n2 - 1);

        double t = (mean1 - mean2) / Math.sqrt(var1 / n1 + var2 / n2);
        double df = (var1 / n1 + var2 / n2) * (var1 / n1 + var2 / n2) / 
                      ((var1 / n1) * (var1 / n1) / (n1 - 1) + (var2 / n2) * (var2 / n2) / (n2 - 1));

        return tTestPValue(t, df);
    }

    private static double tTestPValue(double t, double df) {
        // Simple approximation for p-value calculation
        // This is a placeholder for a more accurate implementation
        return 1.0;
    }

    public static void main(String[] args) {
        data_mutations();
    }
}