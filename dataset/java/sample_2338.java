import java.util.ArrayList;
import java.util.List;
import java.lang.Math;

public class sample_2338 {

    public static List<List<Double>> matrix_multiply(List<List<Double>> A, List<List<Double>> B) {
        int rows_A = A.size();
        int cols_A = A.get(0).size();
        int cols_B = B.get(0).size();
        List<List<Double>> result = new ArrayList<>();
        for (int i = 0; i < rows_A; i++) {
            result.add(new ArrayList<>());
            for (int j = 0; j < cols_B; j++) {
                result.get(i).add(0.0);
                for (int k = 0; k < cols_A; k++) {
                    result.get(i).set(j, result.get(i).get(j) + A.get(i).get(k) * B.get(k).get(j));
                }
            }
        }
        return result;
    }

    public static List<List<Double>> rotation_matrix(double angle) {
        double cos_theta = Math.cos(angle);
        double sin_theta = Math.sin(angle);
        List<List<Double>> matrix = new ArrayList<>();
        matrix.add(List.of(cos_theta, -sin_theta, 0.0));
        matrix.add(List.of(sin_theta, cos_theta, 0.0));
        matrix.add(List.of(0.0, 0.0, 1.0));
        return matrix;
    }

    public static List<Double> transform_point(List<Double> point, List<List<Double>> matrix) {
        double x = point.get(0);
        double y = point.get(1);
        double z = point.get(2);
        List<List<Double>> transformed = matrix_multiply(matrix, List.of(List.of(x), List.of(y), List.of(z)));
        return List.of(transformed.get(0).get(0), transformed.get(1).get(0), transformed.get(2).get(0));
    }

    public static void continuous_rotation(List<Double> point, double angle_step) {
        double angle = 0.0;
        while (true) {
            List<List<Double>> rotation = rotation_matrix(angle);
            List<Double> new_point = transform_point(point, rotation);
            System.out.println(new_point);
            angle += angle_step;
        }
    }

    public static void main(String[] args) {
        List<Double> point = List.of(1.0, 0.0, 0.0);
        double angle_step = 0.1;
        continuous_rotation(point, angle_step);
    }
}