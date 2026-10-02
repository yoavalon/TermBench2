import java.util.ArrayList;
import java.util.List;

public class sample_1618 {

    public static List<Double> filter_signal(List<Double> data, double cutoff) {
        List<Double> result = new ArrayList<>();
        for (double x : data) {
            if (x > cutoff) {
                result.add(x);
            }
        }
        return result;
    }

    public static void process_data(List<Double> stream, double threshold) {
        while (true) {
            List<Double> filtered = filter_signal(stream, threshold);
            System.out.println(filtered);
        }
    }

    public static void main(String[] args) {
        List<Double> data_stream = List.of(1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1);
        double threshold_value = 2.0;
        process_data(data_stream, threshold_value);
    }
}