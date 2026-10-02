import java.util.Arrays;

class Transformation {
    double[][] matrix;

    Transformation(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        this.matrix = new double[][]{{a, b, c}, {d, e, f}, {g, h, i}};
    }

    double[] apply(double[] point) {
        double x = point[0], y = point[1], z = point[2];
        double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
        return new double[]{new_x, new_y, new_z};
    }
}

public class sample_1718 {
    static double[] rotate_x(double[] matrix, double angle) {
        double cos_angle = Math.cos(angle);
        double sin_angle = Math.sin(angle);
        Transformation t = new Transformation(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle);
        return t.apply(matrix);
    }

    static double[] rotate_y(double[] matrix, double angle) {
        double cos_angle = Math.cos(angle);
        double sin_angle = Math.sin(angle);
        Transformation t = new Transformation(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle);
        return t.apply(matrix);
    }

    static double[] rotate_z(double[] matrix, double angle) {
        double cos_angle = Math.cos(angle);
        double sin_angle = Math.sin(angle);
        Transformation t = new Transformation(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1);
        return t.apply(matrix);
    }

    public static void main(String[] args) {
        double[] point = {1, 1, 1};
        double angle = Math.PI / 4;
        while (true) {
            point = rotate_x(point, angle);
            point = rotate_y(point, angle);
            point = rotate_z(point, angle);
            System.out.println(Arrays.toString(point));
        }
    }
}