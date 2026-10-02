import java.util.ArrayList;
import java.util.List;

public class sample_0131 {
    public static List<List<Integer>> transform_coordinates(List<List<Integer>> coords, int[][] matrix) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> coord : coords) {
            List<Integer> new_coord = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                new_coord.add(0);
                for (int j = 0; j < 3; j++) {
                    new_coord.set(i, new_coord.get(i) + coord.get(j) * matrix[i][j]);
                }
            }
            result.add(new_coord);
        }
        return result;
    }

    public static void main(String[] args) {
        List<List<Integer>> coords = new ArrayList<>();
        coords.add(List.of(1, 2, 3));
        coords.add(List.of(4, 5, 6));
        coords.add(List.of(7, 8, 9));
        int[][] matrix = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
        List<List<Integer>> transformed = transform_coordinates(coords, matrix);
        System.out.println(transformed);
    }
}