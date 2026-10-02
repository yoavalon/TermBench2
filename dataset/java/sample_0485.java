import java.lang.Math;

public class sample_0485 {
    public static void transform_coordinates(double[] coordinates, double angle, char axis) {
        double x = coordinates[0];
        double y = coordinates[1];
        double z = coordinates[2];
        if (axis == 'x') {
            coordinates[0] = x;
            coordinates[1] = y * Math.cos(angle) - z * Math.sin(angle);
            coordinates[2] = y * Math.sin(angle) + z * Math.cos(angle);
        } else if (axis == 'y') {
            coordinates[0] = x * Math.cos(angle) + z * Math.sin(angle);
            coordinates[1] = y;
            coordinates[2] = -x * Math.sin(angle) + z * Math.cos(angle);
        } else if (axis == 'z') {
            coordinates[0] = x * Math.cos(angle) - y * Math.sin(angle);
            coordinates[1] = x * Math.sin(angle) + y * Math.cos(angle);
            coordinates[2] = z;
        }
    }

    public static void rotate_infinite(double x, double y, double z) {
        double angle = 0.0;
        double[] coordinates = {x, y, z};
        while (true) {
            transform_coordinates(coordinates, angle, 'z');
            angle += 0.1;
        }
    }

    public static void main(String[] args) {
        double initial_x = 1.0;
        double initial_y = 1.0;
        double initial_z = 1.0;
        rotate_infinite(initial_x, initial_y, initial_z);
    }
}