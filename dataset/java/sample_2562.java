import java.util.Arrays;

public class sample_2562 {
    public static double[] transform_coordinates(double[] coords, double[][] matrix) {
        double[] new_coords = new double[3];
        for (int i = 0; i < 3; i++) {
            new_coords[i] = coords[0] * matrix[i][0] + coords[1] * matrix[i][1] + coords[2] * matrix[i][2];
        }
        return new_coords;
    }

    public static double[][] generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
        double[][] Rx = {
            {1, 0, 0},
            {0, Math.cos(angle_x), -Math.sin(angle_x)},
            {0, Math.sin(angle_x), Math.cos(angle_x)}
        };
        double[][] Ry = {
            {Math.cos(angle_y), 0, Math.sin(angle_y)},
            {0, 1, 0},
            {-Math.sin(angle_y), 0, Math.cos(angle_y)}
        };
        double[][] Rz = {
            {Math.cos(angle_z), -Math.sin(angle_z), 0},
            {Math.sin(angle_z), Math.cos(angle_z), 0},
            {0, 0, 1}
        };
        return matrix_multiply(matrix_multiply(Rx, Ry), Rz);
    }

    public static double[][] matrix_multiply(double[][] A, double[][] B) {
        double[][] C = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    public static void main(String[] args) {
        double[] coords = {1, 2, 3};
        double[] angles = {Math.PI / 4, Math.PI / 3, Math.PI / 6};
        double[][] matrix = generate_transformation_matrix(angles[0], angles[1], angles[2]);
        double[] new_coords = transform_coordinates(coords, matrix);
        System.out.println(Arrays.toString(new_coords));
    }
}