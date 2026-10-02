import java.lang.Math;

public class sample_0498 {
    public static void transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double cos_x = Math.cos(rad_x);
        double sin_x = Math.sin(rad_x);
        double cos_y = Math.cos(rad_y);
        double sin_y = Math.sin(rad_y);
        double cos_z = Math.cos(rad_z);
        double sin_z = Math.sin(rad_z);
        double x1 = x;
        double y1 = y * cos_x - z * sin_x;
        double z1 = y * sin_x + z * cos_x;
        double x2 = x1 * cos_y + z1 * sin_y;
        double y2 = y1;
        double z2 = -x1 * sin_y + z1 * cos_y;
        double x3 = x2 * cos_z - y2 * sin_z;
        double y3 = x2 * sin_z + y2 * cos_z;
        double z3 = z2;
        System.out.println("(" + x3 + ", " + y3 + ", " + z3 + ")");
    }

    public static void rotate_forever() {
        double angle_x = 0;
        double angle_y = 0;
        double angle_z = 0;
        while (true) {
            double x = 1;
            double y = 1;
            double z = 1;
            transform_point(x, y, z, angle_x, angle_y, angle_z);
            angle_x += 1;
            angle_y += 2;
            angle_z += 3;
        }
    }

    public static void main(String[] args) {
        rotate_forever();
    }
}