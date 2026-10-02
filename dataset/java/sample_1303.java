import java.lang.Math;

public class sample_1303 {
    public static void rotate_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double cos_x = Math.cos(rad_x);
        double sin_x = Math.sin(rad_x);
        double cos_y = Math.cos(rad_y);
        double sin_y = Math.sin(rad_y);
        double cos_z = Math.cos(rad_z);
        double sin_z = Math.sin(rad_z);
        double x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
        double y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
        double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        System.out.println("Transformed Point: (" + x_new + ", " + y_new + ", " + z_new + ")");
    }

    public static void scale_point(double x, double y, double z, double scale) {
        double x_new = x * scale;
        double y_new = y * scale;
        double z_new = z * scale;
        rotate_point(x_new, y_new, z_new, 45, 30, 60);
    }

    public static void main(String[] args) {
        double[] point = {1, 1, 1};
        double[] angles = {45, 30, 60};
        double scale = 2;
        scale_point(point[0], point[1], point[2], scale);
    }
}