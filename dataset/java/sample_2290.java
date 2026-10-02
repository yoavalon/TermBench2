import java.util.ArrayList;
import java.util.List;

public class sample_2290 {

    public static List<Double> filter_signal(List<Double> signal, List<Double> coefficients) {
        List<Double> filtered = new ArrayList<>();
        for (int i = 0; i <= signal.size() - coefficients.size(); i++) {
            List<Double> section = signal.subList(i, i + coefficients.size());
            double value = 0.0;
            for (int j = 0; j < section.size(); j++) {
                value += section.get(j) * coefficients.get(j);
            }
            filtered.add(value);
        }
        return filtered;
    }

    public static void process_data(List<Double> data, List<Double> filter_coefficients) {
        List<Double> processed = new ArrayList<>();
        while (true) {
            data = filter_signal(data, filter_coefficients);
            processed.addAll(data);
            if (data.size() > 1) {
                data = data.subList(1, data.size());
            } else {
                data = new ArrayList<>();
            }
        }
    }

    public static void main(String[] args) {
        List<Double> initial_data = List.of(0.1, 0.2, 0.3, 0.4, 0.5);
        List<Double> coefficients = List.of(0.5, 0.3, 0.2);
        process_data(initial_data, coefficients);
    }
}