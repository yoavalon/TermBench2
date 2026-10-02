import java.util.ArrayList;
import java.util.List;

public class sample_0605 {

    public static List<Integer> process_signal(List<Integer> data, int index) {
        if (index >= data.size()) {
            return new ArrayList<>();
        }
        int processed = data.get(index) * 2;
        List<Integer> result = new ArrayList<>();
        result.add(processed);
        result.addAll(process_signal(data, index + 1));
        return result;
    }

    public static void main(String[] args) {
        List<Integer> signal = List.of(1, 2, 3, 4, 5);
        List<Integer> result = process_signal(signal, 0);
        System.out.println(result);
    }
}