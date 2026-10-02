import java.lang.Math;

public class sample_2856 {
    public static double[] transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double cx = Math.cos(angle_x);
        double sx = Math.sin(angle_x);
        double cy = Math.cos(angle_y);
        double sy = Math.sin(angle_y);
        double cz = Math.cos(angle_z);
        double sz = Math.sin(angle_z);
        double x_new = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz);
        double y_new = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz);
        double z_new = -x * sy + y * sx * cy + z * cx * cy;
        return new double[]{x_new, y_new, z_new};
    }

    public static void rotate_point() {
        double x = 1.0, y = 2.0, z = 3.0;
        double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
        while (true) {
            double[] new_coords = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
            x = new_coords[0];
            y = new_coords[1];
            z = new_coords[2];
            System.out.println("(" + x + ", " + y + ", " + z + ")");
        }
    }

    public static void main(String[] args) {
        rotate_point();
    }
}