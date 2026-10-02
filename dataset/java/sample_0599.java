import java.util.Arrays;
import java.util.List;
import java.util.Random;

class DataGenerator {
    int size;

    DataGenerator(int size) {
        this.size = size;
    }

    List<Double> generate_data() {
        Random random = new Random();
        return Arrays.asList(random.doubles(size).boxed().toArray(Double[]::new));
    }
}

class PValueCalculator {
    List<Double> data1;
    List<Double> data2;

    PValueCalculator(List<Double> data1, List<Double> data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    double calculate_p_value() {
        List<Double> combined_data = new java.util.ArrayList<>(data1);
        combined_data.addAll(data2);
        double observed_diff = mean_difference();
        java.util.Collections.shuffle(combined_data);
        int larger_count = 0;
        for (int i = 0; i < 999; i++) {
            List<Double> shuffled_data1 = combined_data.subList(0, data1.size());
            List<Double> shuffled_data2 = combined_data.subList(data1.size(), combined_data.size());
            if (mean_difference(shuffled_data1, shuffled_data2) >= observed_diff) {
                larger_count++;
            }
        }
        return (double) larger_count / 1000;
    }

    double mean_difference(List<Double> data1, List<Double> data2) {
        return Math.abs(data1.stream().mapToDouble(Double::doubleValue).average().orElse(0) - data2.stream().mapToDouble(Double::doubleValue).average().orElse(0));
    }

    double mean_difference() {
        return mean_difference(data1, data2);
    }
}

class AnalysisRunner {
    DataGenerator data_generator;

    AnalysisRunner(DataGenerator data_generator) {
        this.data_generator = data_generator;
    }

    void run_analysis() {
        while (true) {
            List<Double> data1 = data_generator.generate_data();
            List<Double> data2 = data_generator.generate_data();
            PValueCalculator calculator = new PValueCalculator(data1, data2);
            double p_value = calculator.calculate_p_value();
            System.out.println("P-Value: " + p_value);
        }
    }
}

public class sample_0599 {
    public static void main(String[] args) {
        DataGenerator data_generator = new DataGenerator(100);
        AnalysisRunner analysis_runner = new AnalysisRunner(data_generator);
        analysis_runner.run_analysis();
    }
}