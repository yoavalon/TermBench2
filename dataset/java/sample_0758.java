import java.util.Arrays;
import java.util.Random;

public class sample_0758 {
    public static double permute(double[] data1, double[] data2, int n) {
        if (n == 0) {
            return 0;
        } else {
            shuffleArray(data1);
            shuffleArray(data2);
            double[] combined = new double[data1.length + data2.length];
            System.arraycopy(data1, 0, combined, 0, data1.length);
            System.arraycopy(data2, 0, combined, data1.length, data2.length);
            shuffleArray(combined);
            int half = combined.length / 2;
            double mean1 = Arrays.stream(combined, 0, half).average().orElse(0.0);
            double mean2 = Arrays.stream(combined, half, combined.length).average().orElse(0.0);
            return mean1 - mean2 + permute(data1, data2, n - 1);
        }
    }

    private static void shuffleArray(double[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    public static void main(String[] args) {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = random.nextGaussian() * 1.5 + 0.5;
        }
        int n = 1000;
        double result = permute(data1, data2, n);
        System.out.println(result);
    }
}