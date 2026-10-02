import java.util.ArrayList;
import java.util.List;

public class sample_1959 {
    public static List<Double> track_sequence(List<Double> seq, double precision) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < seq.size(); i++) {
            if (i == 0) {
                result.add(seq.get(i));
            } else {
                double diff = Math.abs(seq.get(i) - seq.get(i - 1));
                if (diff < precision) {
                    result.set(result.size() - 1, result.get(result.size() - 1) + seq.get(i));
                } else {
                    result.add(seq.get(i));
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> sequence = List.of(0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5);
        double precision = 0.001;
        List<Double> processed_sequence = track_sequence(sequence, precision);
        System.out.println(processed_sequence);
    }
}