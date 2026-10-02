import java.util.ArrayList;
import java.util.List;

public class sample_0148 {
    public static List<Double> process_signal(List<Double> data, double threshold) {
        List<Double> result = new ArrayList<>();
        for (double value : data) {
            if (value > threshold) {
                result.add(value);
            }
        }
        return result;
    }

    public static double analyze_data(List<Double> signal, double boundary) {
        List<Double> processed = process_signal(signal, boundary);
        double sum = 0;
        for (double value : processed) {
            sum += value;
        }
        return sum;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9);
        double threshold = 0.5;
        double result = analyze_data(data, threshold);
        System.out.println(result);
    }
}