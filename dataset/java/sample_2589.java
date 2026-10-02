import java.util.Arrays;

public class sample_2589 {

    public static double[] transform_point(double[][] matrix, double[] point) {
        double[] result = new double[point.length];
        for (int i = 0; i < matrix.length; i++) {
            result[i] = 0;
            for (int j = 0; j < point.length; j++) {
                result[i] += matrix[i][j] * point[j];
            }
        }
        return result;
    }

    public static double[][] generate_rotation_matrix(double angle, char axis) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        double[][] matrix = new double[3][3];
        if (axis == 'x') {
            matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;
            matrix[1][0] = 0; matrix[1][1] = c; matrix[1][2] = -s;
            matrix[2][0] = 0; matrix[2][1] = s; matrix[2][2] = c;
        } else if (axis == 'y') {
            matrix[0][0] = c; matrix[0][1] = 0; matrix[0][2] = s;
            matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;
            matrix[2][0] = -s; matrix[2][1] = 0; matrix[2][2] = c;
        } else if (axis == 'z') {
            matrix[0][0] = c; matrix[0][1] = -s; matrix[0][2] = 0;
            matrix[1][0] = s; matrix[1][1] = c; matrix[1][2] = 0;
            matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
        }
        return matrix;
    }

    public static void main(String[] args) {
        double[] point = {1, 2, 3};
        double angle = Math.PI / 4;
        double[][] matrix = generate_rotation_matrix(angle, 'z');
        double[] transformed_point = transform_point(matrix, point);
        System.out.println(Arrays.toString(transformed_point));
    }
}