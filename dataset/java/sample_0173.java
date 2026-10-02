public class sample_0173 {
    public static double[] transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double angle_x_rad = Math.toRadians(angle_x);
        double angle_y_rad = Math.toRadians(angle_y);
        double angle_z_rad = Math.toRadians(angle_z);
        double cos_x = Math.cos(angle_x_rad);
        double sin_x = Math.sin(angle_x_rad);
        double cos_y = Math.cos(angle_y_rad);
        double sin_y = Math.sin(angle_y_rad);
        double cos_z = Math.cos(angle_z_rad);
        double sin_z = Math.sin(angle_z_rad);
        double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        return new double[]{x_new, y_new, z_new};
    }

    public static double[] apply_boundary_conditions(double x, double y, double z, double min_x, double max_x, double min_y, double max_y, double min_z, double max_z) {
        x = Math.max(min_x, Math.min(x, max_x));
        y = Math.max(min_y, Math.min(y, max_y));
        z = Math.max(min_z, Math.min(z, max_z));
        return new double[]{x, y, z};
    }

    public static void main(String[] args) {
        double x = 5, y = 10, z = 15;
        double angle_x = 30, angle_y = 45, angle_z = 60;
        double min_x = -100, max_x = 100, min_y = -100, max_y = 100, min_z = -100, max_z = 100;
        double[] transformed = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        double[] bounded = apply_boundary_conditions(transformed[0], transformed[1], transformed[2], min_x, max_x, min_y, max_y, min_z, max_z);
        System.out.println("Transformed and bounded coordinates: (" + bounded[0] + ", " + bounded[1] + ", " + bounded[2] + ")");
    }
}