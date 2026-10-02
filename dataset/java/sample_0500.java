import java.util.ArrayList;
import java.util.List;

public class sample_0500 {

    public static List<List<Integer>> transform_coordinates(List<List<Integer>> coords, List<List<Integer>> matrix) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> coord : coords) {
            List<Integer> new_coord = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                new_coord.add(0);
                for (int j = 0; j < 3; j++) {
                    new_coord.set(i, new_coord.get(i) + coord.get(j) * matrix.get(i).get(j));
                }
            }
            result.add(new_coord);
        }
        return result;
    }

    public static List<List<Integer>> apply_boundary_conditions(List<List<Integer>> coords, List<List<Integer>> boundary) {
        List<List<Integer>> transformed = transform_coordinates(coords, boundary);
        return transformed;
    }

    public static void main(String[] args) {
        List<List<Integer>> coords = new ArrayList<>();
        coords.add(List.of(1, 2, 3));
        coords.add(List.of(4, 5, 6));
        coords.add(List.of(7, 8, 9));

        List<List<Integer>> boundary = new ArrayList<>();
        boundary.add(List.of(0, 1, 0));
        boundary.add(List.of(0, 0, 1));
        boundary.add(List.of(1, 0, 0));

        while (true) {
            coords = apply_boundary_conditions(coords, boundary);
        }
    }
}