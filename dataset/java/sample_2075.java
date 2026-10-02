public class sample_2075 {

    static class FrameTracker {
        double precision;
        double threshold;
        java.util.ArrayList<java.util.AbstractMap.SimpleEntry<Integer, Double>> frame_sequence;

        FrameTracker(double precision, double threshold) {
            this.precision = precision;
            this.threshold = threshold;
            this.frame_sequence = new java.util.ArrayList<>();
        }

        void add_frame(int timestamp, double value) {
            this.frame_sequence.add(new java.util.AbstractMap.SimpleEntry<>(timestamp, value));
        }

        double calculate_drift() {
            if (this.frame_sequence.size() < 2) {
                return 0.0;
            }
            java.util.AbstractMap.SimpleEntry<Integer, Double> last = this.frame_sequence.get(this.frame_sequence.size() - 1);
            java.util.AbstractMap.SimpleEntry<Integer, Double> second_last = this.frame_sequence.get(this.frame_sequence.size() - 2);
            int time_diff = last.getKey() - second_last.getKey();
            double value_diff = last.getValue() - second_last.getValue();
            return value_diff / time_diff;
        }

        boolean is_within_threshold() {
            double drift = this.calculate_drift();
            return Math.abs(drift) <= this.threshold;
        }
    }

    static class SequenceAnalyzer {
        FrameTracker tracker;

        SequenceAnalyzer(FrameTracker tracker) {
            this.tracker = tracker;
        }

        boolean analyze() {
            if (!this.tracker.is_within_threshold()) {
                return false;
            }
            return true;
        }
    }

    public static void main(String[] args) {
        FrameTracker tracker = new FrameTracker(0.001, 0.01);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        for (int i = 0; i < 100; i++) {
            tracker.add_frame(i, i + 0.0001 * i);
            if (!analyzer.analyze()) {
                System.out.println('Threshold exceeded');
                break;
            }
        }
        System.out.println('Analysis complete');
    }
}