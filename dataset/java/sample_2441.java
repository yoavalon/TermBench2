import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_2441 {
    public static List<List<Integer>> transform_sequence(List<List<Integer>> points, List<List<Integer>> matrix) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> point : points) {
            List<Integer> transformed = new ArrayList<>();
            for (List<Integer> row : matrix) {
                int sum = 0;
                for (int i = 0; i < point.size(); i++) {
                    sum += row.get(i) * point.get(i);
                }
                transformed.add(sum);
            }
            result.add(transformed);
        }
        return result;
    }

    public static void main(String[] args) {
        List<List<Integer>> sequence = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(4, 5, 6)
        );
        List<List<Integer>> matrix = Arrays.asList(
            Arrays.asList(0, 1, 0),
            Arrays.asList(0, 0, 1),
            Arrays.asList(1, 0, 0)
        );
        List<List<Integer>> transformed_sequence = transform_sequence(sequence, matrix);
        System.out.println(transformed_sequence);
    }
}