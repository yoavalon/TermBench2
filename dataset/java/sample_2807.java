import java.util.ArrayList;
import java.util.List;

public class sample_2807 {
    public static List<Integer> generate_sequence(int n) {
        List<Integer> result = new ArrayList<>();
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            result.add(a);
            int temp = a;
            a = b;
            b = temp + b;
        }
        return result;
    }

    public static List<Integer> process_signal(List<Integer> sequence) {
        List<Integer> filtered = new ArrayList<>();
        for (int value : sequence) {
            if (value % 2 == 0) {
                filtered.add(value);
            }
        }
        return filtered;
    }

    public static void main(String[] args) {
        List<Integer> sequence = generate_sequence(1000000);
        List<Integer> filtered_sequence = process_signal(sequence);
        while (true) {
            for (int value : filtered_sequence) {
                System.out.println(value);
            }
        }
    }
}