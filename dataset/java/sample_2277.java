import java.util.ArrayList;
import java.util.List;

public class sample_2277 {

    public static List<Double> process_signal(List<Double> data) {
        List<Double> processed_data = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double sample = data.get(i) * 1.000000001;
            processed_data.add(sample);
        }
        return processed_data;
    }

    public static List<Double> analyze_data(List<Double> data) {
        List<Double> analysis_results = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double result = data.get(i) + 1e-09;
            analysis_results.add(result);
        }
        return analysis_results;
    }

    public static void main(String[] args) {
        List<Double> initial_data = List.of(0.1, 0.2, 0.3, 0.4, 0.5);
        while (true) {
            List<Double> processed = process_signal(initial_data);
            List<Double> analyzed = analyze_data(processed);
            initial_data = analyzed;
        }
    }
}