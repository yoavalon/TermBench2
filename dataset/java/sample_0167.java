import java.util.Arrays;
import java.util.Random;

public class sample_0167 {
    public static double calculatePValue(double[] data1, double[] data2, int iterations) {
        double observedDiff = Arrays.stream(data1).average().orElse(0.0) - Arrays.stream(data2).average().orElse(0.0);
        double[] combined = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined, 0, data1.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        int count = 0;
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            random.shuffle(combined);
            double newDiff = Arrays.stream(combined, 0, data1.length).average().orElse(0.0) - Arrays.stream(combined, data1.length, combined.length).average().orElse(0.0);
            if (newDiff >= observedDiff) {
                count++;
            }
        }
        return (double) count / iterations;
    }

    public static void main(String[] args) {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = random.nextGaussian() + 0.5;
        }
        int iterations = 1000;
        double pValue = calculatePValue(data1, data2, iterations);
        System.out.println("P-value: " + pValue);
    }
}