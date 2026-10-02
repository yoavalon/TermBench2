import java.lang.Math;

public class sample_0441 {
    public static double[] transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double cos_x = Math.cos(rad_x);
        double sin_x = Math.sin(rad_x);
        double cos_y = Math.cos(rad_y);
        double sin_y = Math.sin(rad_y);
        double cos_z = Math.cos(rad_z);
        double sin_z = Math.sin(rad_z);
        double x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z);
        double y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z);
        double z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y);
        return new double[]{x2, y2, z2};
    }

    public static void rotate_forever() {
        double x = 1;
        double y = 0;
        double z = 0;
        double angle_x = 0;
        double angle_y = 0;
        double angle_z = 1;
        while (true) {
            double[] new_coords = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
            x = new_coords[0];
            y = new_coords[1];
            z = new_coords[2];
            angle_x += 1;
            angle_y += 1;
            angle_z += 1;
        }
    }

    public static void main(String[] args) {
        rotate_forever();
    }
}