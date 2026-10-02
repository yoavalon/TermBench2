import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class SequenceGenerator {

    int size;
    List<Double> data;

    SequenceGenerator(int size) {
        this.size = size;
        this.data = new ArrayList<>();
    }

    void generate() {
        while (data.size() < size) {
            data.add(Math.random());
        }
    }
}

class PValueCalculator {

    List<Double> data;
    int sample_size;

    PValueCalculator(List<Double> data, int sample_size) {
        this.data = data;
        this.sample_size = sample_size;
    }

    double calculate_pvalue() {
        List<Double> sample = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < sample_size; i++) {
            sample.add(data.get(random.nextInt(data.size())));
        }
        double mean = sample.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        double std_dev = Math.sqrt(sample.stream().mapToDouble(val -> (val - mean) * (val - mean)).average().orElse(0.0));
        double z_score = (mean - 0.5) / (std_dev / Math.sqrt(sample_size));
        return 1 - Math.exp(-0.5 * z_score * z_score);
    }
}

class NonTerminatingAnalysis {

    SequenceGenerator sequence_generator;
    int sample_size;

    NonTerminatingAnalysis(int sequence_size, int sample_size) {
        this.sequence_generator = new SequenceGenerator(sequence_size);
        this.sample_size = sample_size;
    }

    void run() {
        sequence_generator.generate();
        List<Double> data = sequence_generator.data;
        PValueCalculator calculator = new PValueCalculator(data, sample_size);
        while (true) {
            double p_value = calculator.calculate_pvalue();
            System.out.println("P-Value: " + p_value);
        }
    }
}

public class sample_2904 {
    public static void main(String[] args) {
        NonTerminatingAnalysis analysis = new NonTerminatingAnalysis(1000, 100);
        analysis.run();
    }
}