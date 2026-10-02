import java.lang.Math;

public class sample_0429 {
    public static void transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double cos_x = Math.cos(angle_x);
        double sin_x = Math.sin(angle_x);
        double cos_y = Math.cos(angle_y);
        double sin_y = Math.sin(angle_y);
        double cos_z = Math.cos(angle_z);
        double sin_z = Math.sin(angle_z);
        double x_new = cos_y * (cos_z * x + sin_z * y) + sin_y * z;
        double y_new = cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y);
        double z_new = sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y);
        System.out.println("(" + x_new + ", " + y_new + ", " + z_new + ")");
    }

    public static void continuous_rotation() {
        double x = 0, y = 0, z = 0;
        double angle_x = 0, angle_y = 0, angle_z = 0;
        double increment = 0.01;
        while (true) {
            angle_x += increment;
            angle_y += increment;
            angle_z += increment;
            transform_point(x, y, z, angle_x, angle_y, angle_z);
        }
    }

    public static void main(String[] args) {
        continuous_rotation();
    }
}