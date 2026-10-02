import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0057 {
    public static List<List<Integer>> transform_coordinates(List<List<Integer>> coords, List<List<Integer>> matrix) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> row : coords) {
            List<Integer> newRow = new ArrayList<>();
            for (List<Integer> col : matrix) {
                int sum = 0;
                for (int i = 0; i < row.size(); i++) {
                    sum += row.get(i) * col.get(i);
                }
                newRow.add(sum);
            }
            result.add(newRow);
        }
        return result;
    }

    public static void main(String[] args) {
        List<List<Integer>> coords = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(4, 5, 6)
        );
        List<List<Integer>> matrix = Arrays.asList(
            Arrays.asList(0, 1, 0),
            Arrays.asList(-1, 0, 0),
            Arrays.asList(0, 0, 1)
        );
        List<List<Integer>> result = transform_coordinates(coords, matrix);
        System.out.println(result);
    }
}