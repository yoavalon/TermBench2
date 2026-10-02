import java.util.Arrays;
import java.util.Random;

public class sample_1980 {

    static double calculatePvalue(double[] x, double[] y) {
        double diff = Arrays.stream(x).average().orElse(0) - Arrays.stream(y).average().orElse(0);
        double[] combined = new double[x.length + y.length];
        System.arraycopy(x, 0, combined, 0, x.length);
        System.arraycopy(y, 0, combined, x.length, y.length);
        double meanCombined = Arrays.stream(combined).average().orElse(0);
        double stdCombined = calculateStd(combined, meanCombined, combined.length - 1);
        int n1 = x.length, n2 = y.length;
        double seDiff = stdCombined * Math.sqrt(1.0 / n1 + 1.0 / n2);
        return 2 * (1 - Math.abs(diff) / seDiff);
    }

    static double calculateStd(double[] data, double mean, int ddof) {
        return Math.sqrt(Arrays.stream(data).map(d -> (d - mean) * (d - mean)).sum() / ddof);
    }

    static double permutationTest(double[] x, double[] y, int nPermutations) {
        double[] pvalues = new double[nPermutations];
        Random random = new Random();
        for (int i = 0; i < nPermutations; i++) {
            double[] xy = new double[x.length + y.length];
            System.arraycopy(x, 0, xy, 0, x.length);
            System.arraycopy(y, 0, xy, x.length, y.length);
            random.shuffle(xy);
            double[] xPerm = Arrays.copyOfRange(xy, 0, x.length);
            double[] yPerm = Arrays.copyOfRange(xy, x.length, xy.length);
            pvalues[i] = calculatePvalue(xPerm, yPerm);
        }
        return Arrays.stream(pvalues).average().orElse(0);
    }

    public static void main(String[] args) {
        double[] x = new double[50];
        double[] y = new double[50];
        Random random = new Random();
        for (int i = 0; i < 50; i++) {
            x[i] = random.nextGaussian() * 2 + 5;
            y[i] = random.nextGaussian() * 2 + 5.5;
        }
        double result = permutationTest(x, y, 1000);
        System.out.println(result);
    }
}