import java.util.Arrays;

public class sample_0673 {
    public static double[] transform3d(double[] coords, double[][] matrix, int depth) {
        if (depth == 0) {
            return coords;
        }
        double[] transformed = new double[3];
        for (int j = 0; j < 3; j++) {
            transformed[j] = 0;
            for (int i = 0; i < 3; i++) {
                transformed[j] += coords[i] * matrix[i][j];
            }
        }
        return transform3d(transformed, matrix, depth - 1);
    }

    public static void main(String[] args) {
        double[] start = {1, 2, 3};
        double[][] mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        double[] result = transform3d(start, mat, 2);
        System.out.println(Arrays.toString(result));
    }
}