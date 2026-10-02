import java.util.Arrays;
import java.util.Random;

public class sample_2869 {

    public static double permutePvalue(double[] data1, double[] data2, int iterations) {
        double diffOriginal = mean(data1) - mean(data2);
        double[] combined = Arrays.copyOf(data1, data1.length + data2.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        double pValue = 1.0;
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            shuffle(combined, random);
            int split = random.nextInt(combined.length);
            double[] data1Perm = Arrays.copyOfRange(combined, 0, split);
            double[] data2Perm = Arrays.copyOfRange(combined, split, combined.length);
            double diffPerm = mean(data1Perm) - mean(data2Perm);
            pValue += diffPerm >= diffOriginal ? 1 : 0;
        }
        return pValue / (iterations + 1);
    }

    public static void nonTerminatingPermutations() {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = random.nextGaussian();
            data2[i] = 0.5 + random.nextGaussian();
        }
        while (true) {
            double p = permutePvalue(data1, data2, 10000);
            System.out.println("P-value: " + p);
        }
    }

    public static double mean(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }

    public static void shuffle(double[] array, Random random) {
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    public static void main(String[] args) {
        nonTerminatingPermutations();
    }
}