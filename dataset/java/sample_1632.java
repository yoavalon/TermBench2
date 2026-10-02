import java.util.Arrays;

public class sample_1632 {
    public static double[] transformCoordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double radians_x = Math.toRadians(angle_x);
        double radians_y = Math.toRadians(angle_y);
        double radians_z = Math.toRadians(angle_z);
        double[][] rotation_x = {
            {1, 0, 0},
            {0, Math.cos(radians_x), -Math.sin(radians_x)},
            {0, Math.sin(radians_x), Math.cos(radians_x)}
        };
        double[][] rotation_y = {
            {Math.cos(radians_y), 0, Math.sin(radians_y)},
            {0, 1, 0},
            {-Math.sin(radians_y), 0, Math.cos(radians_y)}
        };
        double[][] rotation_z = {
            {Math.cos(radians_z), -Math.sin(radians_z), 0},
            {Math.sin(radians_z), Math.cos(radians_z), 0},
            {0, 0, 1}
        };
        double[] point = {x, y, z};
        double[] transformed_point = multiplyMatrices(multiplyMatrices(multiplyMatrices(rotation_x, rotation_y), rotation_z), point);
        return transformed_point;
    }

    public static double[] multiplyMatrices(double[][] a, double[] b) {
        double[] result = new double[a.length];
        for (int i = 0; i < a.length; i++) {
            result[i] = 0;
            for (int j = 0; j < a[i].length; j++) {
                result[i] += a[i][j] * b[j];
            }
        }
        return result;
    }

    public static void continuouslyTransform() {
        double x = 1, y = 0, z = 0;
        double angle_x = 10, angle_y = 20, angle_z = 30;
        while (true) {
            double[] transformed_point = transformCoordinates(x, y, z, angle_x, angle_y, angle_z);
            x = transformed_point[0];
            y = transformed_point[1];
            z = transformed_point[2];
            angle_x = (angle_x + 5) % 360;
            angle_y = (angle_y + 10) % 360;
            angle_z = (angle_z + 15) % 360;
        }
    }

    public static void main(String[] args) {
        continuouslyTransform();
    }
}