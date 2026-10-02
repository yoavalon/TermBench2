import java.lang.Math;

public class sample_2079 {
    static class Point {
        double x;
        double y;
        double z;

        Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        void translate(double dx, double dy, double dz) {
            this.x += dx;
            this.y += dy;
            this.z += dz;
        }

        void rotate(double angle_x, double angle_y, double angle_z) {
            double cos_x = Math.cos(angle_x);
            double sin_x = Math.sin(angle_x);
            double cos_y = Math.cos(angle_y);
            double sin_y = Math.sin(angle_y);
            double cos_z = Math.cos(angle_z);
            double sin_z = Math.sin(angle_z);
            double x = this.x;
            double y = this.y;
            double z = this.z;
            this.x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
            this.y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z);
            this.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        }
    }

    static void transform_point(Point point, double[] translation, double[] rotation) {
        point.translate(translation[0], translation[1], translation[2]);
        point.rotate(rotation[0], rotation[1], rotation[2]);
    }

    public static void main(String[] args) {
        Point p = new Point(1.0, 2.0, 3.0);
        double[] translation = {4.0, 5.0, 6.0};
        double[] rotation = {0.5, 1.0, 1.5};
        transform_point(p, translation, rotation);
        System.out.println(p.x + " " + p.y + " " + p.z);
    }
}