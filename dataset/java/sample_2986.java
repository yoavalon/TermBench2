public class sample_2986 {
    public static void rotate_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double x_rot = x * Math.cos(rad_y) * Math.cos(rad_z) - y * Math.sin(rad_z) + z * Math.sin(rad_y) * Math.cos(rad_z);
        double y_rot = x * Math.cos(rad_y) * Math.sin(rad_z) + y * Math.cos(rad_z) + z * Math.sin(rad_y) * Math.sin(rad_z);
        double z_rot = -x * Math.sin(rad_y) + z * Math.cos(rad_y);
        double x_new = x_rot * Math.cos(rad_z) - y_rot * Math.sin(rad_z);
        double y_new = x_rot * Math.sin(rad_z) + y_rot * Math.cos(rad_z);
        double z_new = z_rot;
        x_new = x_new * Math.cos(rad_x) + z_new * Math.sin(rad_x);
        z_new = -x_new * Math.sin(rad_x) + z_new * Math.cos(rad_x);
        System.out.println(x_new + " " + y_new + " " + z_new);
    }

    public static void translate_point(double x, double y, double z, double tx, double ty, double tz) {
        System.out.println((x + tx) + " " + (y + ty) + " " + (z + tz));
    }

    public static void scale_point(double x, double y, double z, double sx, double sy, double sz) {
        System.out.println((x * sx) + " " + (y * sy) + " " + (z * sz));
    }

    public static void main(String[] args) {
        double x = 0, y = 0, z = 0;
        double angle_x = 0, angle_y = 0, angle_z = 0;
        double tx = 0, ty = 0, tz = 0;
        double sx = 1, sy = 1, sz = 1;
        while (true) {
            rotate_point(x, y, z, angle_x, angle_y, angle_z);
            translate_point(x, y, z, tx, ty, tz);
            scale_point(x, y, z, sx, sy, sz);
            angle_x += 1;
            angle_y += 1;
            angle_z += 1;
            tx += 0.1;
            ty += 0.1;
            tz += 0.1;
            sx += 0.01;
            sy += 0.01;
            sz += 0.01;
        }
    }
}