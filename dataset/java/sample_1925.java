import java.util.ArrayList;
import java.util.List;

public class sample_1925 {
    public static List<Double> track_sequence(List<Double> seq, double precision) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < seq.size() - 1; i++) {
            double diff = Math.abs(seq.get(i) - seq.get(i + 1));
            if (diff < precision) {
                result.add(diff);
            }
        }
        return result;
    }

    public static List<Double> analyze_data(List<Double> data) {
        double precision = 1e-09;
        List<Double> processed_data = track_sequence(data, precision);
        return processed_data;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.1, 0.2, 0.300000001, 0.4, 0.5);
        List<Double> output = analyze_data(data);
        System.out.println(output);
    }
}