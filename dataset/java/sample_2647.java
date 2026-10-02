import java.util.ArrayList;
import java.util.List;

public class sample_2647 {

    public static void main(String[] args) {
        int n = 10;
        List<Double> sequence = generate_sequence(n);
        SequenceProcessor processor = new SequenceProcessor(sequence);
        List<Double> result = processor.process();
        System.out.println(result);
    }

    static class SequenceProcessor {
        private List<Double> sequence;
        private int length;

        public SequenceProcessor(List<Double> sequence) {
            this.sequence = sequence;
            this.length = sequence.size();
        }

        public List<Double> process() {
            List<Double> transformed = transform_sequence();
            return analyze(transformed);
        }

        private List<Double> transform_sequence() {
            List<Double> transformed = new ArrayList<>();
            for (int i = 0; i < length; i++) {
                double value = sequence.get(i);
                transformed.add(Math.sin(value) * Math.cos(value));
            }
            return transformed;
        }

        private List<Double> analyze(List<Double> sequence) {
            List<Double> analysis = new ArrayList<>();
            for (double value : sequence) {
                analysis.add(Math.round(value * 10000.0) / 10000.0);
            }
            return analysis;
        }
    }

    static List<Double> generate_sequence(int n) {
        List<Double> sequence = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sequence.add(Math.sqrt(i + 1));
        }
        return sequence;
    }
}