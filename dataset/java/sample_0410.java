import java.util.Arrays;

public class sample_0410 {
    public static double[] transform_point(double x, double y, double z, double[][] rotation_matrix) {
        double x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
        double y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
        double z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
        return new double[]{x_new, y_new, z_new};
    }

    public static double[][] rotate_around_axis(String axis, double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        if (axis.equals("x")) {
            return new double[][]{{1, 0, 0}, {0, cos_a, -sin_a}, {0, sin_a, cos_a}};
        } else if (axis.equals("y")) {
            return new double[][]{{cos_a, 0, sin_a}, {0, 1, 0}, {-sin_a, 0, cos_a}};
        } else if (axis.equals("z")) {
            return new double[][]{{cos_a, -sin_a, 0}, {sin_a, cos_a, 0}, {0, 0, 1}};
        }
        return new double[0][];
    }

    public static void main(String[] args) {
        double[] point = {1, 0, 0};
        double angle = 0.1;
        while (true) {
            double[][] rotation_matrix = rotate_around_axis("z", angle);
            point = transform_point(point[0], point[1], point[2], rotation_matrix);
            System.out.println(Arrays.toString(point));
        }
    }
}