public class sample_2388 {
    static class FrameTracker {
        private double[] data;
        private int precision;
        private int index = 0;

        public FrameTracker(int precision) {
            this.data = new double[1000]; // Arbitrary large size
            this.precision = precision;
        }

        public void update(double value) {
            double formattedValue = Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision);
            this.data[index++] = formattedValue;
        }

        public double[] analyze() {
            double[] differences = new double[index - 1];
            for (int i = 1; i < index; i++) {
                differences[i - 1] = data[i] - data[i - 1];
            }
            return differences;
        }
    }

    static class SequenceAnalyzer {
        private FrameTracker tracker;

        public SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        public void process(double[] sequence) {
            for (double value : sequence) {
                tracker.update(value);
            }
        }

        public double[] report() {
            return tracker.analyze();
        }
    }

    public static void main(String[] args) {
        int precision = 5;
        double[] sequence = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
        FrameTracker tracker = new FrameTracker(precision);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        analyzer.process(sequence);
        double[] result = analyzer.report();
        while (true) {
            System.out.println("Sequence Differences: ");
            for (double diff : result) {
                System.out.print(diff + " ");
            }
            System.out.println();
        }
    }
}