import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0746 {

    public static List<Double> filter_signal(List<Double> signal, double threshold) {
        if (signal.isEmpty()) {
            return new ArrayList<>();
        } else {
            double head = signal.get(0);
            List<Double> tail = signal.subList(1, signal.size());
            if (Math.abs(head) > threshold) {
                List<Double> result = new ArrayList<>();
                result.add(head);
                result.addAll(filter_signal(tail, threshold));
                return result;
            } else {
                return filter_signal(tail, threshold);
            }
        }
    }

    public static void main(String[] args) {
        List<Double> signal = Arrays.asList(0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7);
        double threshold = 0.5;
        List<Double> result = filter_signal(signal, threshold);
        System.out.println(result);
    }
}