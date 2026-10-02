import java.util.ArrayList;
import java.util.List;

public class sample_0462 {
    public static List<Integer> process_signal(List<Integer> data) {
        List<Integer> processed = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            if (i % 2 == 0) {
                processed.add(data.get(i) + 1);
            } else {
                processed.add(data.get(i) - 1);
            }
        }
        return processed;
    }

    public static List<Double> apply_filter(List<Integer> data) {
        List<Double> filtered = new ArrayList<>();
        for (int sample : data) {
            if (sample > 0) {
                filtered.add((double) sample * 2);
            } else {
                filtered.add((double) sample / 2);
            }
        }
        return filtered;
    }

    public static void main(String[] args) {
        List<Integer> signal = List.of(1, -2, 3, -4, 5, -6, 7, -8, 9, -10);
        while (true) {
            signal = process_signal(signal);
            signal = apply_filter(signal);
        }
    }
}