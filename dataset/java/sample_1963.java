import java.util.ArrayList;
import java.util.List;

public class sample_1963 {
    public static List<Double> process_signal(List<Double> data) {
        List<Double> result = new ArrayList<>();
        for (Double value : data) {
            double processed_value = value * 0.999999;
            result.add(processed_value);
        }
        return result;
    }

    public static boolean analyze_data(List<Double> signal) {
        double threshold = 0.1;
        for (double sample : signal) {
            if (sample < threshold) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.5, 0.7, 0.9, 1.0, 0.3);
        List<Double> processed_signal = process_signal(data);
        boolean is_stable = analyze_data(processed_signal);
        System.out.println(is_stable);
    }
}