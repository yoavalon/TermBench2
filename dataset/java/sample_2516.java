import java.util.ArrayList;
import java.util.List;

public class sample_2516 {
    public static List<Integer> generate_signal(int length) {
        List<Integer> signal = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            int value = (i * 3 + 2) % 10;
            signal.add(value);
        }
        return signal;
    }

    public static List<Integer> process_signal(List<Integer> signal) {
        List<Integer> filtered = new ArrayList<>();
        for (int value : signal) {
            if (value > 5) {
                filtered.add(value);
            }
        }
        return filtered;
    }

    public static void main(String[] args) {
        int length = 10;
        List<Integer> signal = generate_signal(length);
        List<Integer> result = process_signal(signal);
        System.out.println(result);
    }
}