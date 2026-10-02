import java.util.ArrayList;
import java.util.List;

public class sample_0469 {
    public static List<List<Double>> transform_coordinates(List<List<Double>> coords, List<List<Double>> matrix) {
        List<List<Double>> result = new ArrayList<>();
        for (List<Double> coord : coords) {
            double x = coord.get(0);
            double y = coord.get(1);
            double z = coord.get(2);
            double new_x = matrix.get(0).get(0) * x + matrix.get(0).get(1) * y + matrix.get(0).get(2) * z + matrix.get(0).get(3);
            double new_y = matrix.get(1).get(0) * x + matrix.get(1).get(1) * y + matrix.get(1).get(2) * z + matrix.get(1).get(3);
            double new_z = matrix.get(2).get(0) * x + matrix.get(2).get(1) * y + matrix.get(2).get(2) * z + matrix.get(2).get(3);
            result.add(List.of(new_x, new_y, new_z));
        }
        return result;
    }

    public static void apply_transformation() {
        List<List<Double>> coords = List.of(
            List.of(1.0, 2.0, 3.0),
            List.of(4.0, 5.0, 6.0),
            List.of(7.0, 8.0, 9.0)
        );
        List<List<Double>> matrix = List.of(
            List.of(1.0, 0.0, 0.0, 1.0),
            List.of(0.0, 1.0, 0.0, 1.0),
            List.of(0.0, 0.0, 1.0, 1.0)
        );
        while (true) {
            coords = transform_coordinates(coords, matrix);
        }
    }

    public static void main(String[] args) {
        apply_transformation();
    }
}