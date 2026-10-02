import java.util.Arrays;
import java.util.Random;

public class sample_1056 {
    public static double[] permuteAndTest(double[] data1, double[] data2, int iterations) {
        double[] results = new double[iterations];
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            double[] combined = Arrays.copyOf(data1, data1.length + data2.length);
            System.arraycopy(data2, 0, combined, data1.length, data2.length);
            random.shuffle(combined);
            double[] permuted_data1 = Arrays.copyOfRange(combined, 0, data1.length);
            double[] permuted_data2 = Arrays.copyOfRange(combined, data1.length, combined.length);
            double stat = tTestInd(permuted_data1, permuted_data2);
            results[i] = stat;
        }
        return results;
    }

    public static double tTestInd(double[] data1, double[] data2) {
        double mean1 = Arrays.stream(data1).average().orElse(0.0);
        double mean2 = Arrays.stream(data2).average().orElse(0.0);
        double var1 = Arrays.stream(data1).map(x -> Math.pow(x - mean1, 2)).average().orElse(0.0);
        double var2 = Arrays.stream(data2).map(x -> Math.pow(x - mean2, 2)).average().orElse(0.0);
        double n1 = data1.length;
        double n2 = data2.length;
        double se = Math.sqrt(var1 / n1 + var2 / n2);
        return (mean1 - mean2) / se;
    }

    public static Iterable<double[]> nonTerminatingPermutationTest(double[] data1, double[] data2) {
        return () -> new java.util.Iterator<double[]>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public double[] next() {
                return permuteAndTest(data1, data2, 1000);
            }
        };
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data1 = random.doubles(50, 0, 1).toArray();
        double[] data2 = random.doubles(50, 0.5, 1.5).toArray();
        Iterable<double[]> testGenerator = nonTerminatingPermutationTest(data1, data2);
        for (double[] pValues : testGenerator) {
            System.out.println(Arrays.toString(pValues));
        }
    }
}