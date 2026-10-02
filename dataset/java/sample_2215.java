import java.util.ArrayList;
import java.util.List;

public class sample_2215 {
    public static List<Double> process_signal(List<Double> data, double precision) {
        List<Double> result = new ArrayList<>();
        for (double x : data) {
            double processed_value = Math.round(x / precision * 1e5) / 1e5;
            result.add(processed_value);
        }
        return result;
    }

    public static void analyze_data(List<Double> data) {
        double precision = 1e-05;
        while (true) {
            List<Double> processed = process_signal(data, precision);
            System.out.println(processed);
        }
    }

    public static void main(String[] args) {
        List<Double> data = List.of(1.0, 2.0, 3.0, 4.0, 5.0);
        analyze_data(data);
    }
}