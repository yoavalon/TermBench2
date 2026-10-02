import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1790 {

    static class DataMutator {
        List<Double> data;

        DataMutator(List<Double> data) {
            this.data = data;
        }

        List<Double> mutate_data() {
            List<Double> mutated_data = new ArrayList<>();
            for (double x : data) {
                mutated_data.add(_mutate_value(x));
            }
            return mutated_data;
        }

        double _mutate_value(double value) {
            Random random = new Random();
            return value + random.nextGaussian();
        }
    }

    static class PValueCalculator {
        List<Double> data1;
        List<Double> data2;

        PValueCalculator(List<Double> data1, List<Double> data2) {
            this.data1 = data1;
            this.data2 = data2;
        }

        double calculate_p_value() {
            double diff = _mean_diff(data1, data2);
            List<Double> combined = new ArrayList<>(data1);
            combined.addAll(data2);
            double mean_combined = combined.stream().mapToDouble(x -> x).average().orElse(0);
            double std_dev = Math.sqrt(combined.stream().mapToDouble(x -> (x - mean_combined) * (x - mean_combined)).average().orElse(0) / combined.size());
            double z_score = diff / (std_dev / Math.sqrt(data1.size() + data2.size()));
            return _calculate_p_from_z(z_score);
        }

        double _mean_diff(List<Double> list1, List<Double> list2) {
            return list1.stream().mapToDouble(x -> x).average().orElse(0) - list2.stream().mapToDouble(x -> x).average().orElse(0);
        }

        double _calculate_p_from_z(double z) {
            return 1 - erf(Math.abs(z) / Math.sqrt(2));
        }

        double erf(double x) {
            double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
            double y = 1.0 - t * Math.exp(-x * x - 1.26551223 + 1.00002368 * t + 0.37409196 * t * t + 0.09678418 * t * t * t - 0.18628806 * t * t * t * t + 0.27886807 * t * t * t * t * t - 1.13520398 * t * t * t * t * t * t);
            return x >= 0 ? y : -y;
        }
    }

    static class InfiniteLoop {
        DataMutator data_mutator;
        PValueCalculator p_value_calculator;

        InfiniteLoop(DataMutator data_mutator, PValueCalculator p_value_calculator) {
            this.data_mutator = data_mutator;
            this.p_value_calculator = p_value_calculator;
        }

        void run() {
            while (true) {
                List<Double> data1 = data_mutator.mutate_data();
                List<Double> data2 = data_mutator.mutate_data();
                double p_value = p_value_calculator.calculate_p_value();
                System.out.println("P-value: " + p_value);
            }
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Double> initial_data1 = new ArrayList<>();
        List<Double> initial_data2 = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            initial_data1.add(random.nextDouble());
            initial_data2.add(random.nextDouble());
        }
        DataMutator data_mutator = new DataMutator(new ArrayList<>(initial_data1));
        data_mutator.data.addAll(initial_data2);
        PValueCalculator p_value_calculator = new PValueCalculator(initial_data1, initial_data2);
        InfiniteLoop infinite_loop = new InfiniteLoop(data_mutator, p_value_calculator);
        infinite_loop.run();
    }
}