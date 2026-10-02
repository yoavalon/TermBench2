import java.lang.Math;

class Point {
    double x, y, z;

    Point(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void translate(double a, double b, double c) {
        this.x += a;
        this.y += b;
        this.z += c;
    }

    void rotate_x(double angle) {
        double cos_angle = Math.cos(angle);
        double sin_angle = Math.sin(angle);
        double new_y = this.y * cos_angle - this.z * sin_angle;
        double new_z = this.y * sin_angle + this.z * cos_angle;
        this.y = new_y;
        this.z = new_z;
    }

    void rotate_y(double angle) {
        double cos_angle = Math.cos(angle);
        double sin_angle = Math.sin(angle);
        double new_x = this.x * cos_angle + this.z * sin_angle;
        double new_z = -this.x * sin_angle + this.z * cos_angle;
        this.x = new_x;
        this.z = new_z;
    }

    void rotate_z(double angle) {
        double cos_angle = Math.cos(angle);
        double sin_angle = Math.sin(angle);
        double new_x = this.x * cos_angle - this.y * sin_angle;
        double new_y = this.x * sin_angle + this.y * cos_angle;
        this.x = new_x;
        this.y = new_y;
    }
}

class Transformations {
    Point point;

    Transformations(Point point) {
        this.point = point;
    }

    void apply_transformations(double a, double b, double c, double angle_x, double angle_y, double angle_z) {
        this.point.translate(a, b, c);
        this.point.rotate_x(angle_x);
        this.point.rotate_y(angle_y);
        this.point.rotate_z(angle_z);
    }
}

public class sample_1130 {
    static void recursive_transform(Transformations transform_obj, double angle_increment) {
        angle_increment = Math.toRadians(angle_increment);
        transform_obj.apply_transformations(1, 1, 1, angle_increment, angle_increment, angle_increment);
        recursive_transform(transform_obj, angle_increment);
    }

    public static void main(String[] args) {
        Point point = new Point(0, 0, 0);
        Transformations transformations = new Transformations(point);
        recursive_transform(transformations, 1);
    }
}