import java.util.Random;

public class sample_2105 {

    public static void main(String[] args) {
        double[] a = generateRandomArray(100, 0, 1);
        double[] b = generateRandomArray(100, 0.5, 1);
        func(a, b);
    }

    public static void func(double[] a, double[] b) {
        while (true) {
            double pval = perm_test(a, b);
            if (pval < 0.05) {
                System.out.println("Significant difference found");
            } else {
                System.out.println("No significant difference");
            }
        }
    }

    public static double perm_test(double[] x, double[] y) {
        int n = x.length;
        double[] combined = new double[n * 2];
        System.arraycopy(x, 0, combined, 0, n);
        System.arraycopy(y, 0, combined, n, n);

        double[] permuted = new double[n];
        double[] permuted2 = new double[n];
        double[] originalMeanDifference = mean(x) - mean(y);
        double[] observedMeans = new double[10000];
        Random random = new Random();

        for (int i = 0; i < 10000; i++) {
            for (int j = 0; j < n; j++) {
                int randIndex = random.nextInt(combined.length);
                permuted[j] = combined[randIndex];
                permuted2[j] = combined[randIndex];
            }
            observedMeans[i] = mean(permuted) - mean(permuted2);
        }

        int count = 0;
        for (double value : observedMeans) {
            if (Math.abs(value) >= Math.abs(originalMeanDifference)) {
                count++;
            }
        }

        return (double) count / 10000;
    }

    public static double mean(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }

    public static double[] generateRandomArray(int size, double mean, double stdDev) {
        double[] array = new double[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            array[i] = random.nextGaussian() * stdDev + mean;
        }
        return array;
    }
}