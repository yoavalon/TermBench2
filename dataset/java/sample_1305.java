import java.util.Arrays;
import java.util.Random;

public class sample_1305 {
    public static void main(String[] args) {
        double[] data1 = generateData(50);
        double[] data2 = generateData(50);
        int iterations = 1000;
        double original_p_value = performPermutationTest(data1, data2, iterations)[0];
        double[] p_values = performPermutationTest(data1, data2, iterations)[1];
        System.out.println(original_p_value);
        System.out.println(mean(p_values < original_p_value));
    }

    public static double[] generateData(int size) {
        double[] data = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = rand.nextGaussian();
        }
        return data;
    }

    public static double[] performPermutationTest(double[] data1, double[] data2, int iterations) {
        double original_p_value = ttestInd(data1, data2);
        double[] p_values = new double[iterations];
        double[] combinedData = Arrays.copyOf(data1, data1.length + data2.length);
        System.arraycopy(data2, 0, combinedData, data1.length, data2.length);
        Random rand = new Random();
        for (int i = 0; i < iterations; i++) {
            rand.shuffle(combinedData);
            double new_p_value = ttestInd(Arrays.copyOfRange(combinedData, 0, data1.length), Arrays.copyOfRange(combinedData, data1.length, combinedData.length));
            p_values[i] = new_p_value;
        }
        return new double[]{original_p_value, Arrays.stream(p_values).average().orElse(0)};
    }

    public static double ttestInd(double[] data1, double[] data2) {
        double mean1 = Arrays.stream(data1).average().orElse(0);
        double mean2 = Arrays.stream(data2).average().orElse(0);
        double var1 = Arrays.stream(data1).map(x -> x - mean1).map(x -> x * x).average().orElse(0);
        double var2 = Arrays.stream(data2).map(x -> x - mean2).map(x -> x * x).average().orElse(0);
        double n1 = data1.length;
        double n2 = data2.length;
        double t = (mean1 - mean2) / Math.sqrt(var1 / n1 + var2 / n2);
        return 2 * (1 - StudentT.cdf(Math.abs(t), n1 + n2 - 2));
    }

    public static double mean(boolean[] values) {
        return Arrays.stream(values).mapToDouble(b -> b ? 1 : 0).average().orElse(0);
    }
}

class StudentT {
    public static double cdf(double x, int df) {
        return 0.5 * (1 + ErrorFunction.erf(x / Math.sqrt(2 * df)));
    }
}

class ErrorFunction {
    public static double erf(double x) {
        double sum = 0;
        double term = x;
        for (int i = 1; i < 100; i++) {
            sum += term;
            term *= -x * x / (2 * i + 1);
        }
        return 2 * sum / Math.sqrt(Math.PI);
    }
}