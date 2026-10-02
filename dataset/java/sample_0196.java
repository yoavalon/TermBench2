import java.util.ArrayList;
import java.util.List;

public class sample_0196 {

    public static List<Double> apply_filter(List<Double> data, List<Double> filter_coefficients) {
        List<Double> filtered_data = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double sample = 0;
            for (int j = 0; j < filter_coefficients.size(); j++) {
                if (i - j >= 0) {
                    sample += data.get(i - j) * filter_coefficients.get(j);
                }
            }
            filtered_data.add(sample);
        }
        return filtered_data;
    }

    public static List<Double> process_signal(List<Double> data) {
        List<Double> coefficients = List.of(0.25, 0.5, 0.25);
        return apply_filter(data, coefficients);
    }

    public static void main(String[] args) {
        List<Double> signal = List.of(1.0, 2.0, 3.0, 4.0, 5.0);
        List<Double> processed_signal = process_signal(signal);
        for (double value : processed_signal) {
            System.out.println(value);
        }
    }
}