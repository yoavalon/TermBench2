import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0168 {

    public static List<Integer> apply_boundary_conditions(List<Integer> signal, String boundary_type) {
        int length = signal.size();
        List<Integer> result = new ArrayList<>();
        if (boundary_type.equals("zero")) {
            result.add(0);
            result.addAll(signal);
            result.add(0);
        } else if (boundary_type.equals("repeat")) {
            result.addAll(signal);
            result.addAll(signal);
        } else if (boundary_type.equals("mirror")) {
            result.addAll(signal);
            for (int i = length - 2; i >= 0; i--) {
                result.add(signal.get(i));
            }
        }
        return result;
    }

    public static List<List<Integer>> process_signal(List<List<Integer>> data, String condition) {
        List<List<Integer>> processed = new ArrayList<>();
        for (List<Integer> segment : data) {
            processed.add(apply_boundary_conditions(segment, condition));
        }
        return processed;
    }

    public static void main(String[] args) {
        List<List<Integer>> data = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(4, 5, 6),
            Arrays.asList(7, 8, 9)
        );
        List<List<Integer>> result = process_signal(data, "mirror");
        for (List<Integer> item : result) {
            System.out.println(item);
        }
    }
}