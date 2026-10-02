import java.util.Arrays;

public class sample_2635 {

    public static double[][] transform_matrix(double[][] rotation, double[] translation) {
        double[][] R = Arrays.copyOf(rotation, rotation.length);
        double[][] T = new double[3][1];
        for (int i = 0; i < translation.length; i++) {
            T[i][0] = translation[i];
        }
        double[][] result = new double[4][4];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = R[i][j];
            }
            result[i][3] = T[i][0];
        }
        result[3][3] = 1;
        return result;
    }

    public static double[][] apply_transformation(double[][] points, double[][] matrix) {
        double[][] homogeneous_points = new double[points.length][4];
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < 3; j++) {
                homogeneous_points[i][j] = points[i][j];
            }
            homogeneous_points[i][3] = 1;
        }
        double[][] transformed_points = new double[points.length][4];
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < 4; j++) {
                transformed_points[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    transformed_points[i][j] += homogeneous_points[i][k] * matrix[k][j];
                }
            }
        }
        double[][] result = new double[points.length][3];
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = transformed_points[i][j] / transformed_points[i][3];
            }
        }
        return result;
    }

    public static double[][] generate_sequence(int n, double[] initial_point, double angle, double[] axis) {
        double[][] sequence = new double[n + 1][3];
        sequence[0] = Arrays.copyOf(initial_point, initial_point.length);
        double[][] rotation_matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        for (int i = 0; i < n; i++) {
            rotation_matrix = rotate_around_axis(rotation_matrix, angle, axis);
            double[][] transformed_point = apply_transformation(new double[][]{Arrays.copyOf(sequence[i], sequence[i].length)}, rotation_matrix);
            sequence[i + 1] = Arrays.copyOf(transformed_point[0], transformed_point[0].length);
        }
        return sequence;
    }

    public static double[][] rotate_around_axis(double[][] matrix, double angle, double[] axis) {
        double cos = Math.cos(angle);
        double sin = Math.sin(angle);
        double norm = Math.sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
        double ux = axis[0] / norm;
        double uy = axis[1] / norm;
        double uz = axis[2] / norm;
        double[][] rotation = {
                {cos + ux * ux * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin},
                {uy * ux * (1 - cos) + uz * sin, cos + uy * uy * (1 - cos), uy * uz * (1 - cos) - ux * sin},
                {uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz * uz * (1 - cos)}
        };
        double[][] result = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result[i][j] += rotation[i][k] * matrix[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[] initial_point = {1, 0, 0};
        double angle = Math.PI / 4;
        double[] axis = {0, 0, 1};
        int n = 10;
        double[][] sequence = generate_sequence(n, initial_point, angle, axis);
        for (double[] point : sequence) {
            System.out.println(Arrays.toString(point));
        }
    }
}