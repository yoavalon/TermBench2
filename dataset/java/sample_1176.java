import java.lang.Math;

class Point3D {
    double x, y, z;

    Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void translate(double dx, double dy, double dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    void rotate_x(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double y = this.y * cos_a - this.z * sin_a;
        double z = this.y * sin_a + this.z * cos_a;
        this.y = y;
        this.z = z;
    }

    void rotate_y(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x = this.x * cos_a + this.z * sin_a;
        double z = -this.x * sin_a + this.z * cos_a;
        this.x = x;
        this.z = z;
    }

    void rotate_z(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x = this.x * cos_a - this.y * sin_a;
        double y = this.x * sin_a + this.y * cos_a;
        this.x = x;
        this.y = y;
    }
}

public class sample_1176 {
    static void transform_point(Point3D point, double[] angles, double[] translations) {
        point.rotate_x(angles[0]);
        point.rotate_y(angles[1]);
        point.rotate_z(angles[2]);
        point.translate(translations[0], translations[1], translations[2]);
    }

    static void recursive_transform(Point3D point, double[] angles, double[] translations) {
        transform_point(point, angles, translations);
        recursive_transform(point, angles, translations);
    }

    public static void main(String[] args) {
        Point3D p = new Point3D(1, 0, 0);
        double[] a = {0.1, 0.2, 0.3};
        double[] t = {0.1, 0.1, 0.1};
        recursive_transform(p, a, t);
    }
}