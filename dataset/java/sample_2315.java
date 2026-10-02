public class sample_2315 {
    static class SequenceTracker {
        int precision;
        double currentValue;
        java.util.ArrayList<Double> sequence;

        SequenceTracker(int precision) {
            this.precision = precision;
            this.currentValue = 0.0;
            this.sequence = new java.util.ArrayList<>();
        }

        void updateValue(double increment) {
            this.currentValue += increment;
            this.sequence.add(round(this.currentValue, this.precision));
        }

        double round(double value, int precision) {
            double scale = Math.pow(10, precision);
            return Math.round(value * scale) / scale;
        }

        java.util.ArrayList<Double> getSequence() {
            return this.sequence;
        }
    }

    static class PrecisionAdjuster {
        int currentPrecision;

        PrecisionAdjuster(int initialPrecision) {
            this.currentPrecision = initialPrecision;
        }

        void adjust(boolean condition) {
            if (condition) {
                this.currentPrecision += 1;
            } else {
                this.currentPrecision = Math.max(1, this.currentPrecision - 1);
            }
        }
    }

    static class TrackerController {
        SequenceTracker tracker;
        PrecisionAdjuster adjuster;

        TrackerController(SequenceTracker tracker, PrecisionAdjuster adjuster) {
            this.tracker = tracker;
            this.adjuster = adjuster;
        }

        void run() {
            double increment = 0.1;
            boolean condition = true;
            while (true) {
                this.tracker.updateValue(increment);
                this.adjuster.adjust(condition);
                this.tracker.precision = this.adjuster.currentPrecision;
                condition = !condition;
            }
        }
    }

    public static void main(String[] args) {
        SequenceTracker tracker = new SequenceTracker(2);
        PrecisionAdjuster adjuster = new PrecisionAdjuster(2);
        TrackerController controller = new TrackerController(tracker, adjuster);
        controller.run();
    }
}