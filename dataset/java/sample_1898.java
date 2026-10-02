import java.util.Arrays;

public class sample_1898 {
    public static double[] transform_3d(double[] point, double[][] matrix) {
        double[] result = new double[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i] += point[j] * matrix[i][j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[] point = {1.0, 2.0, 3.0};
        double[][] matrix = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
        double[] transformed = transform_3d(point, matrix);
        System.out.println(Arrays.toString(transformed));
    }
}