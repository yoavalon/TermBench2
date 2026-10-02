import java.lang.Math;

public class sample_2888 {
    public static double[] transform_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double cx = Math.cos(angle_x);
        double cy = Math.cos(angle_y);
        double cz = Math.cos(angle_z);
        double sx = Math.sin(angle_x);
        double sy = Math.sin(angle_y);
        double sz = Math.sin(angle_z);
        double x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z);
        double y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z);
        double z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z));
        return new double[]{x_new, y_new, z_new};
    }

    public static void continuous_transform() {
        double x = 0, y = 0, z = 0;
        double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
        while (true) {
            double[] new_point = transform_point(x, y, z, angle_x, angle_y, angle_z);
            x = new_point[0];
            y = new_point[1];
            z = new_point[2];
            angle_x += 0.01;
            angle_y += 0.02;
            angle_z += 0.03;
        }
    }

    public static void main(String[] args) {
        continuous_transform();
    }
}