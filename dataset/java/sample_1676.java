import java.util.ArrayList;
import java.util.List;

public class sample_1676 {
    public static List<List<Integer>> transform_coordinates(List<List<Integer>> coords, int[][] matrix) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> coord : coords) {
            List<Integer> new_coord = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                int sum = 0;
                for (int j = 0; j < 3; j++) {
                    sum += coord.get(j) * matrix[i][j];
                }
                new_coord.add(sum);
            }
            result.add(new_coord);
        }
        return result;
    }

    public static void mutate_dataset(List<List<Integer>> dataset, int[][] transform_matrix) {
        while (true) {
            dataset = transform_coordinates(dataset, transform_matrix);
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> dataset = new ArrayList<>();
        dataset.add(List.of(1, 0, 0));
        dataset.add(List.of(0, 1, 0));
        dataset.add(List.of(0, 0, 1));

        int[][] transform_matrix = {
            {0, -1, 0},
            {1, 0, 0},
            {0, 0, 1}
        };

        mutate_dataset(dataset, transform_matrix);
    }
}