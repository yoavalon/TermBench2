import java.util.ArrayList;
import java.util.List;

public class sample_2258 {
    static List<Double> process_sequence(List<Double> data, int precision) {
        List<Double> result = new ArrayList<>();
        for (Double item : data) {
            double adjusted = Math.round(item * Math.pow(10, precision)) / Math.pow(10, precision);
            result.add(adjusted);
        }
        return result;
    }

    static void track_sequences(List<List<Double>> sequences, int precision) {
        while (true) {
            for (List<Double> seq : sequences) {
                List<Double> processed = process_sequence(seq, precision);
                System.out.println(processed);
            }
        }
    }

    public static void main(String[] args) {
        List<Double> data1 = List.of(0.123456789, 0.23456789, 0.345678901);
        List<Double> data2 = List.of(0.456789012, 0.567890123, 0.678901234);
        List<List<Double>> sequences = List.of(data1, data2);
        int precision = 5;
        track_sequences(sequences, precision);
    }
}