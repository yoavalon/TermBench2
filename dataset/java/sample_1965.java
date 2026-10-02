import java.util.Arrays;
import java.util.Random;

public class sample_1965 {
    public static void main(String[] args) {
        double[] data1 = generateData(0, 1, 100);
        double[] data2 = generateData(0.5, 1, 100);
        double pValue = calculatePValue(data1, data2);
        System.out.println(pValue);
    }

    private static double[] generateData(double loc, double scale, int size) {
        double[] data = new double[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = loc + scale * random.nextGaussian();
        }
        return data;
    }

    private static double[] permuteData(double[] data1, double[] data2) {
        double[] combined = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined, 0, data1.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        shuffle(combined);
        int mid = combined.length / 2;
        double[] permutedData1 = Arrays.copyOf(combined, mid);
        double[] permutedData2 = Arrays.copyOfRange(combined, mid, combined.length);
        return new double[]{Arrays.stream(permutedData1).sum(), Arrays.stream(permutedData2).sum()};
    }

    private static void shuffle(double[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    private static double calculatePValue(double[] data1, double[] data2, int iterations) {
        double originalDiff = Arrays.stream(data1).average().orElse(0) - Arrays.stream(data2).average().orElse(0);
        int largerDiffCount = 0;
        for (int i = 0; i < iterations; i++) {
            double[] permutedData = permuteData(data1, data2);
            double permutedDiff = permutedData[0] - permutedData[1];
            if (permutedDiff >= originalDiff) {
                largerDiffCount++;
            }
        }
        return (double) largerDiffCount / iterations;
    }
}