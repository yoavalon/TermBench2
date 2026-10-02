import java.util.Arrays;
import java.util.Random;

class DataManipulator {

    double[] data;

    public DataManipulator(double[] data) {
        this.data = data;
    }

    public double[] shuffle_data() {
        Random rand = new Random();
        for (int i = data.length - 1; i > 0; i--) {
            int index = rand.nextInt(i + 1);
            double temp = data[index];
            data[index] = data[i];
            data[i] = temp;
        }
        return data;
    }
}

class PValueCalculator {

    double[] data1;
    double[] data2;

    public PValueCalculator(double[] data1, double[] data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    public double calculate_pvalue() {
        return Arrays.stream(data1).average().orElse(0.0) - Arrays.stream(data2).average().orElse(0.0);
    }
}

class PermutationAnalyzer {

    double[] data1;
    double[] data2;
    int iterations;

    public PermutationAnalyzer(double[] data1, double[] data2, int iterations) {
        this.data1 = data1;
        this.data2 = data2;
        this.iterations = iterations;
    }

    public double[] run_permutations() {
        double[] p_values = new double[iterations];
        double[] combined_data = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined_data, 0, data1.length);
        System.arraycopy(data2, 0, combined_data, data1.length, data2.length);
        Random rand = new Random();
        for (int i = 0; i < iterations; i++) {
            for (int j = combined_data.length - 1; j > 0; j--) {
                int index = rand.nextInt(j + 1);
                double temp = combined_data[index];
                combined_data[index] = combined_data[j];
                combined_data[j] = temp;
            }
            int split_index = data1.length;
            double[] perm_data1 = Arrays.copyOf(combined_data, split_index);
            double[] perm_data2 = Arrays.copyOfRange(combined_data, split_index, combined_data.length);
            p_values[i] = new PValueCalculator(perm_data1, perm_data2).calculate_pvalue();
        }
        return p_values;
    }
}

public class sample_1403 {

    public static void main(String[] args) {
        Random rand = new Random();
        double[] data1 = rand.doubles(100, 0, 1).toArray();
        double[] data2 = rand.doubles(100, 0.5, 1.5).toArray();
        int iterations = 1000;
        DataManipulator manipulator = new DataManipulator(data1);
        double[] shuffled_data1 = manipulator.shuffle_data();
        PermutationAnalyzer analyzer = new PermutationAnalyzer(shuffled_data1, data2, iterations);
        double[] p_values = analyzer.run_permutations();
        double original_pvalue = new PValueCalculator(data1, data2).calculate_pvalue();
        System.out.println("Original p-value: " + original_pvalue);
        System.out.println("Permutation p-values: " + Arrays.toString(p_values));
    }
}