import java.util.Arrays;

public class sample_1307 {
    public static double[] transform_coordinates(double[][] matrix, double[] points) {
        double[] result = new double[points.length];
        for (int i = 0; i < points.length; i++) {
            result[i] = 0;
            for (int j = 0; j < points.length; j++) {
                result[i] += points[j] * matrix[j][i];
            }
        }
        return result;
    }

    public static double[] rotate_3d(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double c = Math.cos(rad);
        double s = Math.sin(rad);
        double[][] rot_matrix = {
            {c, -s, 0},
            {s, c, 0},
            {0, 0, 1}
        };
        double[] points = {x, y, z};
        return transform_coordinates(rot_matrix, points);
    }

    public static void main(String[] args) {
        double x = 1, y = 2, z = 3;
        double angle = 45;
        double[] result = rotate_3d(x, y, z, angle);
        System.out.println(result[0] + " " + result[1] + " " + result[2]);
    }
}