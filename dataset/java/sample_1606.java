import java.lang.Math;

public class sample_1606 {
    public static void main(String[] args) {
        continuous_transformation();
    }

    public static double[] transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        angle_x = Math.toRadians(angle_x);
        angle_y = Math.toRadians(angle_y);
        angle_z = Math.toRadians(angle_z);
        double x1 = x * Math.cos(angle_y) * Math.cos(angle_z) - y * Math.sin(angle_z) + z * Math.sin(angle_y) * Math.cos(angle_z);
        double y1 = x * Math.cos(angle_y) * Math.sin(angle_z) + y * Math.cos(angle_z) + z * Math.sin(angle_y) * Math.sin(angle_z);
        double z1 = -x * Math.sin(angle_y) + z * Math.cos(angle_y);
        return new double[]{x1, y1, z1};
    }

    public static void continuous_transformation() {
        double x = 1, y = 0, z = 0;
        double angle_x = 1, angle_y = 0, angle_z = 0;
        while (true) {
            double[] coordinates = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
            x = coordinates[0];
            y = coordinates[1];
            z = coordinates[2];
            angle_x += 1;
            angle_y += 1;
            angle_z += 1;
        }
    }
}