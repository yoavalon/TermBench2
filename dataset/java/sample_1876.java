import java.util.ArrayList;
import java.util.List;

public class sample_1876 {
    public static List<Double> process_signal(List<Double> data, double threshold) {
        List<Double> result = new ArrayList<>();
        for (double x : data) {
            if (Math.abs(x) > threshold) {
                result.add(Math.round(x * 1000.0) / 1000.0);
            } else {
                result.add(0.0);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.123456, -0.789012, 0.000123, 0.999999);
        double threshold = 0.5;
        List<Double> processed_data = process_signal(data, threshold);
        System.out.println(processed_data);
    }
}