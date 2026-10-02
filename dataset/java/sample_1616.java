import java.util.ArrayList;
import java.util.List;

public class sample_1616 {
    public static List<List<Double>> transform_coordinates(double x, double y, double z, double[][] matrix) {
        List<Double> result = new ArrayList<>();
        result.add(matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]);
        result.add(matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]);
        result.add(matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]);
        return result;
    }

    public static List<List<Double>> apply_transformation(List<List<Double>> data, double[][] transformation_matrix) {
        List<List<Double>> result = new ArrayList<>();
        for (List<Double> point : data) {
            List<Double> transformed_point = transform_coordinates(point.get(0), point.get(1), point.get(2), transformation_matrix);
            result.add(transformed_point);
        }
        return result;
    }

    public static void main(String[] args) {
        List<List<Double>> data = new ArrayList<>();
        data.add(List.of(1.0, 2.0, 3.0));
        data.add(List.of(4.0, 5.0, 6.0));
        data.add(List.of(7.0, 8.0, 9.0));
        double[][] matrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
        while (true) {
            List<List<Double>> transformed_data = apply_transformation(data, matrix);
            data = transformed_data;
        }
    }
}