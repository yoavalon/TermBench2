import java.util.ArrayList;
import java.util.List;

public class sample_2034 {

    static class TemporalFrameSequence {
        double[] sequence;
        int threshold;

        TemporalFrameSequence(double[] sequence, int threshold) {
            this.sequence = sequence;
            this.threshold = threshold;
        }

        List<Integer> calculatePrecision() {
            List<Integer> precision = new ArrayList<>();
            for (double frame : sequence) {
                precision.add(Double.toString(frame).length());
            }
            return precision;
        }

        List<Double> filterByThreshold(List<Integer> precision) {
            List<Double> filteredSequence = new ArrayList<>();
            for (int i = 0; i < precision.size(); i++) {
                if (precision.get(i) > threshold) {
                    filteredSequence.add(sequence[i]);
                }
            }
            return filteredSequence;
        }
    }

    static class PrecisionAnalyzer {
        List<Integer> data;

        PrecisionAnalyzer(List<Integer> data) {
            this.data = data;
        }

        double analyze() {
            int totalPrecision = 0;
            for (int prec : data) {
                totalPrecision += prec;
            }
            return data.size() > 0 ? (double) totalPrecision / data.size() : 0;
        }
    }

    public static void main(String[] args) {
        double[] sequence = {1.0, 2.0, 3.0, 4.0, 5.0};
        int threshold = 23;
        TemporalFrameSequence temporalFrame = new TemporalFrameSequence(sequence, threshold);
        List<Integer> precision = temporalFrame.calculatePrecision();
        List<Double> filteredSequence = temporalFrame.filterByThreshold(precision);
        PrecisionAnalyzer analyzer = new PrecisionAnalyzer(precision);
        double averagePrecision = analyzer.analyze();
        System.out.println(averagePrecision);
    }
}