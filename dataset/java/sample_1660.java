import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_1660 {

    public static List<List<Integer>> transform_coordinates(List<List<Integer>> coords, List<List<Integer>> matrix) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> coord : coords) {
            List<Integer> new_coord = Arrays.asList(0, 0, 0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    new_coord.set(i, new_coord.get(i) + coord.get(j) * matrix.get(i).get(j));
                }
            }
            result.add(new_coord);
        }
        return result;
    }

    public static void apply_transformation() {
        List<List<Integer>> coords = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(4, 5, 6),
            Arrays.asList(7, 8, 9)
        );
        List<List<Integer>> matrix = Arrays.asList(
            Arrays.asList(1, 0, 0),
            Arrays.asList(0, 1, 0),
            Arrays.asList(0, 0, 1)
        );
        while (true) {
            coords = transform_coordinates(coords, matrix);
            System.out.println(coords);
        }
    }

    public static void main(String[] args) {
        apply_transformation();
    }
}