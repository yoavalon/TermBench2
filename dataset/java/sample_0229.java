import java.util.Arrays;

public class sample_0229 {

    public static double[][] matrix_multiply(double[][] A, double[][] B) {
        double[][] result = new double[A.length][B[0].length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B[0].length; j++) {
                for (int k = 0; k < B.length; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    public static double[] translate_point(double[] point, double[] translation) {
        double[][] translation_matrix = {
            {1, 0, 0, translation[0]},
            {0, 1, 0, translation[1]},
            {0, 0, 1, translation[2]},
            {0, 0, 0, 1}
        };
        double[][] point_matrix = {
            {point[0]},
            {point[1]},
            {point[2]},
            {1}
        };
        double[][] transformed_point = matrix_multiply(translation_matrix, point_matrix);
        return new double[]{transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]};
    }

    public static double[] rotate_point(double[] point, double angle, char axis) {
        double[][] rotation_matrix = new double[4][4];
        if (axis == 'x') {
            rotation_matrix = new double[][]{
                {1, 0, 0, 0},
                {0, Math.cos(angle), -Math.sin(angle), 0},
                {0, Math.sin(angle), Math.cos(angle), 0},
                {0, 0, 0, 1}
            };
        } else if (axis == 'y') {
            rotation_matrix = new double[][]{
                {Math.cos(angle), 0, Math.sin(angle), 0},
                {0, 1, 0, 0},
                {-Math.sin(angle), 0, Math.cos(angle), 0},
                {0, 0, 0, 1}
            };
        } else if (axis == 'z') {
            rotation_matrix = new double[][]{
                {Math.cos(angle), -Math.sin(angle), 0, 0},
                {Math.sin(angle), Math.cos(angle), 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}
            };
        }
        double[][] point_matrix = {
            {point[0]},
            {point[1]},
            {point[2]},
            {1}
        };
        double[][] transformed_point = matrix_multiply(rotation_matrix, point_matrix);
        return new double[]{transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]};
    }

    public static double[] scale_point(double[] point, double scale) {
        double[][] scaling_matrix = {
            {scale, 0, 0, 0},
            {0, scale, 0, 0},
            {0, 0, scale, 0},
            {0, 0, 0, 1}
        };
        double[][] point_matrix = {
            {point[0]},
            {point[1]},
            {point[2]},
            {1}
        };
        double[][] transformed_point = matrix_multiply(scaling_matrix, point_matrix);
        return new double[]{transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]};
    }

    public static void main(String[] args) {
        double[] point = {1, 2, 3};
        double[] translation = {1, 1, 1};
        double angle = 30 * (3.14159 / 180);
        double scale_factor = 2;
        point = translate_point(point, translation);
        point = rotate_point(point, angle, 'z');
        point = scale_point(point, scale_factor);
        System.out.println(Arrays.toString(point));
    }
}