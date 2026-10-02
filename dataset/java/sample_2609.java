import java.util.Arrays;

public class sample_2609 {

    static class SequenceGenerator {

        private int length;

        public SequenceGenerator(int length) {
            this.length = length;
        }

        public double[] generate() {
            double[] sequence = new double[length];
            for (int i = 1; i < length; i++) {
                sequence[i] = sequence[i - 1] + 0.5;
            }
            return sequence;
        }
    }

    static class FilterApplier {

        private double[] coefficients;

        public FilterApplier(double[] coefficients) {
            this.coefficients = coefficients;
        }

        public double[] apply(double[] sequence) {
            double[] filtered_sequence = convolve(sequence, coefficients);
            return filtered_sequence;
        }

        private double[] convolve(double[] sequence, double[] coefficients) {
            int n = sequence.length;
            int m = coefficients.length;
            double[] result = new double[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i - j >= 0 && i - j < n) {
                        result[i] += sequence[i - j] * coefficients[j];
                    }
                }
            }
            return result;
        }
    }

    static class SignalProcessor {

        private SequenceGenerator generator;
        private FilterApplier filter;

        public SignalProcessor(SequenceGenerator generator, FilterApplier filter) {
            this.generator = generator;
            this.filter = filter;
        }

        public double[] process() {
            double[] sequence = generator.generate();
            double[] filtered_sequence = filter.apply(sequence);
            return filtered_sequence;
        }
    }

    public static void main(String[] args) {
        int length = 100;
        double[] coefficients = {0.25, 0.5, 0.25};
        SequenceGenerator generator = new SequenceGenerator(length);
        FilterApplier filter_applier = new FilterApplier(coefficients);
        SignalProcessor processor = new SignalProcessor(generator, filter_applier);
        double[] result = processor.process();
        System.out.println(Arrays.toString(result));
    }
}