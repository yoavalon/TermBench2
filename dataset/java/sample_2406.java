import java.util.ArrayList;
import java.util.List;

public class sample_2406 {
    public static List<Integer> process_signal(List<Integer> data, int threshold) {
        List<Integer> filtered = new ArrayList<>();
        for (int val : data) {
            if (val > threshold) {
                filtered.add(val);
            }
        }
        return filtered;
    }

    public static void main(String[] args) {
        List<Integer> signal = List.of(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
        int threshold = 50;
        List<Integer> result = process_signal(signal, threshold);
        System.out.println(result);
    }
}