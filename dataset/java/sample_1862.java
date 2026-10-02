import java.util.ArrayList;
import java.util.List;

public class sample_1862 {
    public static List<Double> process_signal(List<Double> data, double factor) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double value = data.get(i) * factor;
            result.add(Math.round(value * 100000.0) / 100000.0);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> signal = List.of(0.123456, 0.789012, 0.345678);
        double factor = 1.2345;
        List<Double> processed = process_signal(signal, factor);
        System.out.println(processed);
    }
}