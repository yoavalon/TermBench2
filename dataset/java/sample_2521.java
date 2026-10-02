import java.util.Random;

public class sample_2521 {
    public static double[] generate_data(int size) {
        double[] data1 = new double[size];
        double[] data2 = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            data1[i] = rand.nextGaussian();
            data2[i] = 0.5 + 1.5 * rand.nextGaussian();
        }
        return new double[]{data1, data2};
    }

    public static double[] calculate_p_values(double[] data1, double[] data2, int iterations) {
        double[] p_values = new double[iterations];
        Random rand = new Random();
        for (int i = 0; i < iterations; i++) {
            for (int j = 0; j < data1.length; j++) {
                int shuffleIndex1 = rand.nextInt(data1.length);
                int shuffleIndex2 = rand.nextInt(data2.length);
                double temp1 = data1[j];
                data1[j] = data1[shuffleIndex1];
                data1[shuffleIndex1] = temp1;
                double temp2 = data2[j];
                data2[j] = data2[shuffleIndex2];
                data2[shuffleIndex2] = temp2;
            }
            double p_value = ttest_ind(data1, data2);
            p_values[i] = p_value;
        }
        return p_values;
    }

    public static double ttest_ind(double[] data1, double[] data2) {
        double sum1 = 0, sum2 = 0, sum1sq = 0, sum2sq = 0;
        for (double v : data1) sum1 += v;
        for (double v : data2) sum2 += v;
        double mean1 = sum1 / data1.length;
        double mean2 = sum2 / data2.length;
        for (double v : data1) sum1sq += Math.pow(v - mean1, 2);
        for (double v : data2) sum2sq += Math.pow(v - mean2, 2);
        double var1 = sum1sq / data1.length;
        double var2 = sum2sq / data2.length;
        double t = (mean1 - mean2) / Math.sqrt(var1 / data1.length + var2 / data2.length);
        return 1 - tdist(t, Math.sqrt((var1 / data1.length) + (var2 / data2.length)));
    }

    public static double tdist(double t, double df) {
        // Approximate t-distribution using a simple method
        return 0.5 * (1 + Math.signum(t) * Math.exp(-0.5 * t * t / df));
    }

    public static void main(String[] args) {
        double[] data = generate_data(100);
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        System.arraycopy(data[0], 0, data1, 0, 100);
        System.arraycopy(data[1], 0, data2, 0, 100);
        double[] p_values = calculate_p_values(data1, data2, 1000);
        double mean = 0;
        for (double p : p_values) mean += p;
        mean /= p_values.length;
        System.out.println(mean);
    }
}