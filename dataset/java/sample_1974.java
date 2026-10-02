import java.util.ArrayList;
import java.util.List;

public class sample_1974 {

    public static List<Integer> track_sequence(List<Double> sequence, double precision) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < sequence.size() - 1; i++) {
            double diff = Math.abs(sequence.get(i) - sequence.get(i + 1));
            if (diff < precision) {
                result.add(1);
            } else {
                result.add(0);
            }
        }
        return result;
    }

    public static double analyze_sequence(List<Double> sequence, double precision) {
        List<Integer> tracked = track_sequence(sequence, precision);
        double stability = calculateMean(tracked);
        return stability;
    }

    private static double calculateMean(List<Integer> list) {
        double sum = 0;
        for (int num : list) {
            sum += num;
        }
        return sum / list.size();
    }

    public static void main(String[] args) {
        List<Double> sequence = List.of(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0);
        double precision = 0.05;
        double stability = analyze_sequence(sequence, precision);
        System.out.println(stability);
    }
}