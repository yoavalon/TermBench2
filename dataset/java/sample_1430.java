import java.util.ArrayList;
import java.util.List;

public class sample_1430 {

    static class Point {
        double x, y, z;

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

        void scale(double sx, double sy, double sz) {
            this.x *= sx;
            this.y *= sy;
            this.z *= sz;
        }

        void rotate_x(double angle) {
            double cos_angle = Math.cos(angle);
            double sin_angle = Math.sin(angle);
            this.y = this.y * cos_angle - this.z * sin_angle;
            this.z = this.y * sin_angle + this.z * cos_angle;
        }

        void rotate_y(double angle) {
            double cos_angle = Math.cos(angle);
            double sin_angle = Math.sin(angle);
            this.x = this.x * cos_angle + this.z * sin_angle;
            this.z = -this.x * sin_angle + this.z * cos_angle;
        }

        void rotate_z(double angle) {
            double cos_angle = Math.cos(angle);
            double sin_angle = Math.sin(angle);
            this.x = this.x * cos_angle - this.y * sin_angle;
            this.y = this.x * sin_angle + this.y * cos_angle;
        }
    }

    static class Transformation {
        List<Point> points;

        Transformation(List<Point> points) {
            this.points = points;
        }

        void apply_translation(double dx, double dy, double dz) {
            for (Point point : points) {
                point.translate(dx, dy, dz);
            }
        }

        void apply_scale(double sx, double sy, double sz) {
            for (Point point : points) {
                point.scale(sx, sy, sz);
            }
        }

        void apply_rotation_x(double angle) {
            for (Point point : points) {
                point.rotate_x(angle);
            }
        }

        void apply_rotation_y(double angle) {
            for (Point point : points) {
                point.rotate_y(angle);
            }
        }

        void apply_rotation_z(double angle) {
            for (Point point : points) {
                point.rotate_z(angle);
            }
        }
    }

    public static void main(String[] args) {
        List<Point> points = new ArrayList<>();
        points.add(new Point(1, 2, 3));
        points.add(new Point(4, 5, 6));
        points.add(new Point(7, 8, 9));
        Transformation transformation = new Transformation(points);
        transformation.apply_translation(1, 1, 1);
        transformation.apply_scale(2, 2, 2);
        transformation.apply_rotation_x(3.14159 / 4);
        transformation.apply_rotation_y(3.14159 / 4);
        transformation.apply_rotation_z(3.14159 / 4);
        for (Point point : points) {
            System.out.println("(" + point.x + ", " + point.y + ", " + point.z + ")");
        }
    }
}