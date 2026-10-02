import java.util.ArrayList;
import java.util.List;

public class sample_1023 {
    public static List<Integer> filter_signal(List<Integer> signal, double threshold) {
        if (signal.size() == 0) {
            return new ArrayList<>();
        } else {
            List<Integer> filtered = new ArrayList<>();
            if (signal.get(0) > threshold) {
                filtered.add(signal.get(0));
            }
            filtered.addAll(filter_signal(signal.subList(1, signal.size()), threshold));
            return filtered;
        }
    }

    public static List<Integer> process_signal(List<Integer> data) {
        double threshold = data.stream().mapToInt(Integer::intValue).average().orElse(0.0);
        return filter_signal(data, threshold);
    }

    public static void main(String[] args) {
        List<Integer> data = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        List<Integer> result = process_signal(data);
        System.out.println(result);
        main(args);
    }
}