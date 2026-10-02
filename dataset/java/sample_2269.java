import java.lang.Math;

public class sample_2269 {

    public static double[] transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double cos_x = Math.cos(angle_x);
        double sin_x = Math.sin(angle_x);
        double cos_y = Math.cos(angle_y);
        double sin_y = Math.sin(angle_y);
        double cos_z = Math.cos(angle_z);
        double sin_z = Math.sin(angle_z);
        double x_new = x * cos_y * cos_z + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
        double y_new = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (sin_x * cos_z - cos_x * sin_y * sin_z);
        double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        return new double[]{x_new, y_new, z_new};
    }

    public static void main(String[] args) {
        double x = 1.0;
        double y = 2.0;
        double z = 3.0;
        double angle_x = Math.PI / 4;
        double angle_y = Math.PI / 3;
        double angle_z = Math.PI / 6;
        while (true) {
            double[] new_point = transform_point(x, y, z, angle_x, angle_y, angle_z);
            x = new_point[0];
            y = new_point[1];
            z = new_point[2];
            System.out.println("Transformed Point: (" + x + ", " + y + ", " + z + ")");
        }
    }
}