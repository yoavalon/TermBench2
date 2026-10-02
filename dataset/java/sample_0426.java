import java.lang.Math;

public class sample_0426 {

    public static double[] transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double cos_x = Math.cos(rad_x);
        double cos_y = Math.cos(rad_y);
        double cos_z = Math.cos(rad_z);
        double sin_x = Math.sin(rad_x);
        double sin_y = Math.sin(rad_y);
        double sin_z = Math.sin(rad_z);
        double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        return new double[]{x_new, y_new, z_new};
    }

    public static void apply_transformation() {
        double x = 1.0, y = 2.0, z = 3.0;
        double angle_x = 30, angle_y = 45, angle_z = 60;
        while (true) {
            double[] new_coords = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
            x = new_coords[0];
            y = new_coords[1];
            z = new_coords[2];
            System.out.println(x + " " + y + " " + z);
        }
    }

    public static void main(String[] args) {
        apply_transformation();
    }
}