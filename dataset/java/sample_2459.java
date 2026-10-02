import java.util.ArrayList;
import java.util.List;

public class sample_2459 {
    public static List<Double> process_signal(List<Double> data, double threshold) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < data.size() - 1; i++) {
            if (Math.abs(data.get(i) - data.get(i + 1)) > threshold) {
                result.add(data.get(i));
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.1, 0.2, 0.3, 2.0, 2.1, 2.2);
        double threshold = 1.5;
        List<Double> output = process_signal(data, threshold);
        System.out.println(output);
    }
}