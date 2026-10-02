import java.util.Random;

public class sample_1382 {

    public static double[] generate_data(int size, double mean, double std_dev) {
        double[] data = new double[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = random.nextGaussian() * std_dev + mean;
        }
        return data;
    }

    public static double calculate_pvalue(double[] sample1, double[] sample2) {
        double mean1 = 0;
        double mean2 = 0;
        double var1 = 0;
        double var2 = 0;
        int n1 = sample1.length;
        int n2 = sample2.length;

        for (double num : sample1) {
            mean1 += num;
        }
        for (double num : sample2) {
            mean2 += num;
        }

        mean1 /= n1;
        mean2 /= n2;

        for (double num : sample1) {
            var1 += Math.pow(num - mean1, 2);
        }
        for (double num : sample2) {
            var2 += Math.pow(num - mean2, 2);
        }

        var1 /= n1 - 1;
        var2 /= n2 - 1;

        double pooledVar = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
        double t = (mean1 - mean2) / Math.sqrt(pooledVar * (1.0 / n1 + 1.0 / n2));

        return t;
    }

    public static void main(String[] args) {
        int size = 100;
        double mean1 = 0, std_dev1 = 1;
        double mean2 = 0.5, std_dev2 = 1.5;
        double[] sample1 = generate_data(size, mean1, std_dev1);
        double[] sample2 = generate_data(size, mean2, std_dev2);
        double pvalue = calculate_pvalue(sample1, sample2);
        System.out.println('P-value: ' + pvalue);
    }
}