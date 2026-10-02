import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_2691 {

    static class SequenceSimulator {
        int a;
        int b;
        int n;

        SequenceSimulator(int a, int b, int n) {
            this.a = a;
            this.b = b;
            this.n = n;
        }

        List<Integer> generate_sequence() {
            List<Integer> sequence = new ArrayList<>();
            int current = this.a;
            for (int i = 0; i < this.n; i++) {
                sequence.add(current);
                current = this.b * current;
            }
            return sequence;
        }

        Map<String, Double> analyze_sequence(List<Integer> sequence) {
            Map<String, Double> analysis = new HashMap<>();
            int sum = 0;
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            for (int value : sequence) {
                sum += value;
                if (value > max) {
                    max = value;
                }
                if (value < min) {
                    min = value;
                }
            }
            analysis.put("sum", (double) sum);
            analysis.put("max", (double) max);
            analysis.put("min", (double) min);
            analysis.put("mean", (double) sum / sequence.size());
            return analysis;
        }
    }

    static class ThermodynamicState {
        double temperature;
        double pressure;

        ThermodynamicState(double temperature, double pressure) {
            this.temperature = temperature;
            this.pressure = pressure;
        }

        void update_state(Map<String, Double> sequence_analysis) {
            this.temperature = sequence_analysis.get("max");
            this.pressure = sequence_analysis.get("min");
        }
    }

    public static void main(String[] args) {
        SequenceSimulator sim = new SequenceSimulator(2, 3, 10);
        List<Integer> seq = sim.generate_sequence();
        Map<String, Double> analysis = sim.analyze_sequence(seq);
        ThermodynamicState state = new ThermodynamicState(300, 1);
        state.update_state(analysis);
        System.out.println("Final Temperature: " + state.temperature + ", Final Pressure: " + state.pressure);
    }
}