import java.util.ArrayList;
import java.util.List;

public class sample_0234 {

    static class BoundaryProcessor {
        List<Double> signal;
        double threshold;

        BoundaryProcessor(List<Double> signal, double threshold) {
            this.signal = signal;
            this.threshold = threshold;
        }

        List<Integer> apply_threshold() {
            List<Integer> processed_signal = new ArrayList<>();
            for (double value : signal) {
                if (value > threshold) {
                    processed_signal.add(1);
                } else {
                    processed_signal.add(0);
                }
            }
            return processed_signal;
        }

        List<Integer> detect_edges(List<Integer> processed_signal) {
            List<Integer> edges = new ArrayList<>();
            for (int i = 1; i < processed_signal.size(); i++) {
                if (!processed_signal.get(i).equals(processed_signal.get(i - 1))) {
                    edges.add(i);
                }
            }
            return edges;
        }
    }

    static class SignalAnalyzer {
        BoundaryProcessor processor;

        SignalAnalyzer(BoundaryProcessor processor) {
            this.processor = processor;
        }

        List<Integer> analyze() {
            List<Integer> processed_signal = processor.apply_threshold();
            List<Integer> edges = processor.detect_edges(processed_signal);
            return edges;
        }
    }

    public static void main(String[] args) {
        List<Double> signal = List.of(0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7);
        double threshold = 0.5;
        BoundaryProcessor processor = new BoundaryProcessor(signal, threshold);
        SignalAnalyzer analyzer = new SignalAnalyzer(processor);
        List<Integer> result = analyzer.analyze();
        System.out.println(result);
    }
}