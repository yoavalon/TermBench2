import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_1363 {

    public static List<List<Integer>> process_data(List<Integer> data) {
        List<Integer> transformed_data = new ArrayList<>();
        for (Integer item : data) {
            if (item > 10) {
                transformed_data.add(item * 2);
            } else {
                transformed_data.add(item - 5);
            }
        }
        return transformed_data;
    }

    public static List<List<Integer>> analyze_supply_chain(List<List<Integer>> data) {
        for (int i = 0; i < data.size(); i++) {
            data.set(i, process_data(data.get(i)));
        }
        return data;
    }

    public static void main(String[] args) {
        List<List<Integer>> initial_data = Arrays.asList(
            Arrays.asList(12, 5, 18, 3),
            Arrays.asList(9, 15, 7, 20),
            Arrays.asList(11, 8, 14, 6)
        );
        List<List<Integer>> optimized_data = analyze_supply_chain(initial_data);
        System.out.println(optimized_data);
    }
}