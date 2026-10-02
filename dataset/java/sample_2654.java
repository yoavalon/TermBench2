import java.util.ArrayList;
import java.util.List;

public class sample_2654 {

    static class SequenceSimulator {
        double a;
        double b;
        int n;
        List<Double> sequence;

        SequenceSimulator(double a, double b, int n) {
            this.a = a;
            this.b = b;
            this.n = n;
            this.sequence = new ArrayList<>();
        }

        void generate_sequence() {
            for (int i = 0; i < n; i++) {
                double value = a + i * b;
                sequence.add(value);
            }
        }

        List<Double> calculate_thermodynamic_states() {
            List<Double> states = new ArrayList<>();
            for (double value : sequence) {
                double state = Math.exp(-value);
                states.add(state);
            }
            return states;
        }
    }

    static class DataAnalyzer {
        List<Double> data;

        DataAnalyzer(List<Double> data) {
            this.data = data;
        }

        double average() {
            return data.stream().mapToDouble(Double::doubleValue).sum() / data.size();
        }

        double max_value() {
            return data.stream().mapToDouble(Double::doubleValue).max().orElse(Double.NaN);
        }

        double min_value() {
            return data.stream().mapToDouble(Double::doubleValue).min().orElse(Double.NaN);
        }
    }

    public static void main(String[] args) {
        double a = 0;
        double b = 0.1;
        int n = 100;
        SequenceSimulator simulator = new SequenceSimulator(a, b, n);
        simulator.generate_sequence();
        List<Double> states = simulator.calculate_thermodynamic_states();
        DataAnalyzer analyzer = new DataAnalyzer(states);
        System.out.println('Average State: ' + analyzer.average());
        System.out.println('Max State: ' + analyzer.max_value());
        System.out.println('Min State: ' + analyzer.min_value());
    }
}