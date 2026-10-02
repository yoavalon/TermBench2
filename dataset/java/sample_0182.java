import java.util.ArrayList;
import java.util.List;

public class sample_0182 {
    public static List<Double> filter_signal(List<Double> data, double threshold) {
        List<Double> result = new ArrayList<>();
        for (double value : data) {
            if (Math.abs(value) > threshold) {
                result.add(value);
            } else {
                break;
            }
        }
        return result;
    }

    public static List<Double> process_data(List<Double> data, double threshold) {
        List<Double> filtered = filter_signal(data, threshold);
        List<Double> processed = new ArrayList<>();
        for (double value : filtered) {
            processed.add(value * 2);
        }
        return processed;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0);
        double threshold = 0.3;
        List<Double> output = process_data(data, threshold);
        System.out.println(output);
    }
}