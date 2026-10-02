import java.lang.Math;

public class sample_2897 {
    public static double[] transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double cos_x = Math.cos(angle_x);
        double sin_x = Math.sin(angle_x);
        double cos_y = Math.cos(angle_y);
        double sin_y = Math.sin(angle_y);
        double cos_z = Math.cos(angle_z);
        double sin_z = Math.sin(angle_z);
        double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        return new double[]{x_new, y_new, z_new};
    }

    public static void main(String[] args) {
        double x = 1, y = 0, z = 0;
        double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
        while (true) {
            double[] new_coordinates = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
            x = new_coordinates[0];
            y = new_coordinates[1];
            z = new_coordinates[2];
            System.out.printf("(%.2f, %.2f, %.2f)\n", x, y, z);
        }
    }
}