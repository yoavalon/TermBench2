import java.util.Random;
import java.util.Arrays;

class SequenceGenerator {

    private int size;

    public SequenceGenerator(int size) {
        this.size = size;
    }

    public double[] generate() {
        double[] sequence = new double[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            sequence[i] = random.nextDouble();
        }
        return sequence;
    }
}

class PermutationCalculator {

    public double calculate_p_values(double[] sequence1, double[] sequence2) {
        int n = sequence1.length;
        double observed_diff = mean(sequence1) - mean(sequence2);
        double[] combined = new double[n * 2];
        System.arraycopy(sequence1, 0, combined, 0, n);
        System.arraycopy(sequence2, 0, combined, n, n);
        int p_value = 0;
        for (int i = 0; i < 1000; i++) {
            shuffle(combined);
            double perm_diff = mean(combined, 0, n) - mean(combined, n, n);
            if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
                p_value++;
            }
        }
        return (double) p_value / 1000;
    }

    private double mean(double[] array, int start, int end) {
        double sum = 0;
        for (int i = start; i < end; i++) {
            sum += array[i];
        }
        return sum / (end - start);
    }

    private void shuffle(double[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}

class AnalysisRunner {

    private SequenceGenerator generator;
    private PermutationCalculator calculator;

    public AnalysisRunner(SequenceGenerator generator, PermutationCalculator calculator) {
        this.generator = generator;
        this.calculator = calculator;
    }

    public double run_analysis() {
        double[] seq1 = generator.generate();
        double[] seq2 = generator.generate();
        double p_value = calculator.calculate_p_values(seq1, seq2);
        return p_value;
    }
}

public class sample_2639 {
    public static void main(String[] args) {
        int size = 30;
        SequenceGenerator generator = new SequenceGenerator(size);
        PermutationCalculator calculator = new PermutationCalculator();
        AnalysisRunner runner = new AnalysisRunner(generator, calculator);
        double result = runner.run_analysis();
        System.out.println(result);
    }
}