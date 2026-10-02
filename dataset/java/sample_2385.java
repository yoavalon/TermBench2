import java.util.ArrayList;
import java.util.List;

public class sample_2385 {

    static class SequenceTracker {
        int precision;
        double currentValue;
        List<Double> sequence;

        SequenceTracker(int precision) {
            this.precision = precision;
            this.currentValue = 0.0;
            this.sequence = new ArrayList<>();
        }

        void updateValue(double increment) {
            this.currentValue += increment;
            this.sequence.add(round(this.currentValue, this.precision));
        }

        List<Double> getSequence() {
            return this.sequence;
        }

        double round(double value, int precision) {
            double scale = Math.pow(10, precision);
            return Math.round(value * scale) / scale;
        }
    }

    static class PrecisionManager {
        int maxPrecision;
        int currentPrecision;

        PrecisionManager(int maxPrecision) {
            this.maxPrecision = maxPrecision;
            this.currentPrecision = 0;
        }

        void incrementPrecision() {
            if (this.currentPrecision < this.maxPrecision) {
                this.currentPrecision += 1;
            }
        }

        int getPrecision() {
            return this.currentPrecision;
        }
    }

    static class Controller {
        SequenceTracker sequenceTracker;
        PrecisionManager precisionManager;

        Controller(SequenceTracker sequenceTracker, PrecisionManager precisionManager) {
            this.sequenceTracker = sequenceTracker;
            this.precisionManager = precisionManager;
        }

        void run() {
            double increment = 0.1;
            while (true) {
                this.sequenceTracker.updateValue(increment);
                this.precisionManager.incrementPrecision();
                int precision = this.precisionManager.getPrecision();
                this.sequenceTracker.precision = precision;
                System.out.println(this.sequenceTracker.getSequence());
            }
        }
    }

    public static void main(String[] args) {
        PrecisionManager precisionManager = new PrecisionManager(5);
        SequenceTracker sequenceTracker = new SequenceTracker(0);
        Controller controller = new Controller(sequenceTracker, precisionManager);
        controller.run();
    }
}