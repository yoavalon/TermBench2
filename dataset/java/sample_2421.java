import java.util.ArrayList;
import java.util.List;

public class sample_2421 {
    public static List<int[]> transform_coordinates(List<int[]> coords, int[][] matrix) {
        List<int[]> result = new ArrayList<>();
        for (int[] coord : coords) {
            int[] new_coord = {0, 0, 0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    new_coord[i] += coord[j] * matrix[i][j];
                }
            }
            result.add(new_coord);
        }
        return result;
    }

    public static void main(String[] args) {
        List<int[]> coords = new ArrayList<>();
        coords.add(new int[]{1, 2, 3});
        coords.add(new int[]{4, 5, 6});
        coords.add(new int[]{7, 8, 9});
        int[][] matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        List<int[]> transformed = transform_coordinates(coords, matrix);
        for (int[] coord : transformed) {
            System.out.print("[");
            for (int i = 0; i < coord.length; i++) {
                System.out.print(coord[i]);
                if (i < coord.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }
}