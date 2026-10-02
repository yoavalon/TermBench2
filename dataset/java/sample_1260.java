import java.util.ArrayList;
import java.util.List;

public class sample_1260 {
    public static void main(String[] args) {
        List<Integer> main_data = List.of(1, 2, 2, 3, 3, 3, 4, 5, 5, 6);
        List<Integer> processed_data = process_sequence(main_data);
        System.out.println(processed_data);
    }

    public static List<Integer> process_sequence(List<Integer> data) {
        if (data.isEmpty()) {
            return new ArrayList<>();
        }
        for (int i = 0; i < data.size() - 1; i++) {
            if (data.get(i).equals(data.get(i + 1))) {
                data.set(i + 1, null);
            }
        }
        List<Integer> result = new ArrayList<>();
        for (Integer x : data) {
            if (x != null) {
                result.add(x);
            }
        }
        return result;
    }
}