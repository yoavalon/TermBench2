import java.lang.Math;

public class sample_1673 {
    public static void transform_coordinates(double[] coords, double angle_x, double angle_y, double angle_z) {
        double cx = Math.cos(angle_x);
        double cy = Math.cos(angle_y);
        double cz = Math.cos(angle_z);
        double sx = Math.sin(angle_x);
        double sy = Math.sin(angle_y);
        double sz = Math.sin(angle_z);
        double x1 = coords[0] * cy * cz - coords[1] * sz + coords[2] * sy * cz;
        double y1 = coords[0] * cy * sz + coords[1] * cz + coords[2] * sy * sz;
        double z1 = -coords[0] * sx * cy + coords[2] * cx;
        coords[0] = x1;
        coords[1] = y1;
        coords[2] = z1;
    }

    public static void apply_rotation() {
        double[] coords = {1.0, 1.0, 1.0};
        double angle_x = Math.PI / 4;
        double angle_y = Math.PI / 4;
        double angle_z = Math.PI / 4;
        while (true) {
            transform_coordinates(coords, angle_x, angle_y, angle_z);
        }
    }

    public static void main(String[] args) {
        apply_rotation();
    }
}