import java.util.Random;

class SequenceGenerator {

    int size;
    double[] sequence;

    SequenceGenerator(int size) {
        this.size = size;
        this.sequence = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            sequence[i] = rand.nextDouble();
        }
    }

    double[] generate() {
        return sequence;
    }
}

class PValueCalculator {

    double[] sequence;
    double test_statistic;

    PValueCalculator(double[] sequence, double test_statistic) {
        this.sequence = sequence;
        this.test_statistic = test_statistic;
    }

    double calculate_pvalue() {
        int count = 0;
        for (double value : sequence) {
            if (value > test_statistic) {
                count++;
            }
        }
        return (double) count / sequence.length;
    }
}

class PermutationTest {

    double[] sequence;
    double test_statistic;
    int permutations;

    PermutationTest(double[] sequence, double test_statistic, int permutations) {
        this.sequence = sequence;
        this.test_statistic = test_statistic;
        this.permutations = permutations;
    }

    double run() {
        double[] p_values = new double[permutations];
        Random rand = new Random();
        for (int i = 0; i < permutations; i++) {
            rand.shuffle(sequence);
            PValueCalculator pvalue_calc = new PValueCalculator(sequence, test_statistic);
            p_values[i] = pvalue_calc.calculate_pvalue();
        }
        double sum = 0;
        for (double value : p_values) {
            sum += value;
        }
        return sum / permutations;
    }
}

public class sample_2659 {

    public static void main(String[] args) {
        int size = 1000;
        double test_statistic = 0.5;
        int permutations = 100;
        SequenceGenerator sequence_gen = new SequenceGenerator(size);
        double[] sequence = sequence_gen.generate();
        PValueCalculator pvalue_calc = new PValueCalculator(sequence, test_statistic);
        double original_pvalue = pvalue_calc.calculate_pvalue();
        PermutationTest permutation_test = new PermutationTest(sequence, test_statistic, permutations);
        double permuted_pvalue = permutation_test.run();
        System.out.println('Original p-value: ' + original_pvalue);
        System.out.println('Permuted p-value: ' + permuted_pvalue);
    }
}