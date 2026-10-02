public class sample_2513 {
    public static double[] transform_point(double x, double y, double z, double[][] matrix) {
        return new double[]{
            x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
            x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
            x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]
        };
    }

    public static double[][] apply_sequence_transformations(double[][] points, double[][][] sequence) {
        double[][] result = points;
        for (double[][] matrix : sequence) {
            double[][] new_points = new double[result.length][3];
            for (int i = 0; i < result.length; i++) {
                new_points[i] = transform_point(result[i][0], result[i][1], result[i][2], matrix);
            }
            result = new_points;
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        double[][][] sequence = {
            {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
            {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}},
            {{1, 0, 0}, {0, 1, 0}, {0, 0, -1}}
        };
        double[][] transformed_points = apply_sequence_transformations(points, sequence);
        for (double[] point : transformed_points) {
            System.out.println(java.util.Arrays.toString(point));
        }
    }
}