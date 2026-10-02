import java.util.Arrays;
import java.util.Random;

class SequenceGenerator {
    int size;
    double[] data;

    SequenceGenerator(int size) {
        this.size = size;
        this.data = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            data[i] = rand.nextDouble();
        }
    }

    double[] generate_sequence() {
        return data;
    }
}

class PValueCalculator {
    double[] sequence1;
    double[] sequence2;

    PValueCalculator(double[] sequence1, double[] sequence2) {
        this.sequence1 = sequence1;
        this.sequence2 = sequence2;
    }

    double calculate_p_value() {
        double diff = Arrays.stream(sequence1).average().orElse(0.0) - Arrays.stream(sequence2).average().orElse(0.0);
        double[] bootstrap_samples = new double[1000];
        Random rand = new Random();
        for (int i = 0; i < 1000; i++) {
            double[] combined = Arrays.copyOf(sequence1, sequence1.length + sequence2.length);
            System.arraycopy(sequence2, 0, combined, sequence1.length, sequence2.length);
            for (int j = 0; j < combined.length; j++) {
                int index = rand.nextInt(combined.length);
                double temp = combined[j];
                combined[j] = combined[index];
                combined[index] = temp;
            }
            double new_mean_diff = Arrays.stream(combined, 0, sequence1.length).average().orElse(0.0) - Arrays.stream(combined, sequence1.length, combined.length).average().orElse(0.0);
            bootstrap_samples[i] = new_mean_diff;
        }
        int count = 0;
        for (double sample : bootstrap_samples) {
            if (Math.abs(sample) >= Math.abs(diff)) {
                count++;
            }
        }
        double p_value = (count + 1) / (bootstrap_samples.length + 1.0);
        return p_value;
    }
}

class AnalysisRunner {
    SequenceGenerator sequence_generator1;
    SequenceGenerator sequence_generator2;

    AnalysisRunner(SequenceGenerator sequence_generator1, SequenceGenerator sequence_generator2) {
        this.sequence_generator1 = sequence_generator1;
        this.sequence_generator2 = sequence_generator2;
    }

    double run_analysis() {
        double[] seq1 = sequence_generator1.generate_sequence();
        double[] seq2 = sequence_generator2.generate_sequence();
        PValueCalculator p_value_calculator = new PValueCalculator(seq1, seq2);
        double p_value = p_value_calculator.calculate_p_value();
        return p_value;
    }
}

public class sample_2686 {
    public static void main(String[] args) {
        int size1 = 100, size2 = 100;
        SequenceGenerator seq_gen1 = new SequenceGenerator(size1);
        SequenceGenerator seq_gen2 = new SequenceGenerator(size2);
        AnalysisRunner analysis_runner = new AnalysisRunner(seq_gen1, seq_gen2);
        double result = analysis_runner.run_analysis();
        System.out.println(result);
    }
}