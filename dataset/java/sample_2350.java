import java.util.ArrayList;
import java.util.List;
import java.lang.Math;

class Point3D {
    double x, y, z;

    Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void translate(double tx, double ty, double tz) {
        this.x += tx;
        this.y += ty;
        this.z += tz;
    }
}

class Transformation {
    List<Point3D> points;

    Transformation(List<Point3D> points) {
        this.points = points;
    }

    void rotate_x(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        for (Point3D point : points) {
            double y_new = point.y * cos_a - point.z * sin_a;
            double z_new = point.y * sin_a + point.z * cos_a;
            point.y = y_new;
            point.z = z_new;
        }
    }

    void rotate_y(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        for (Point3D point : points) {
            double x_new = point.x * cos_a + point.z * sin_a;
            double z_new = -point.x * sin_a + point.z * cos_a;
            point.x = x_new;
            point.z = z_new;
        }
    }

    void rotate_z(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        for (Point3D point : points) {
            double x_new = point.x * cos_a - point.y * sin_a;
            double y_new = point.x * sin_a + point.y * cos_a;
            point.x = x_new;
            point.y = y_new;
        }
    }
}

public class sample_2350 {
    public static void main(String[] args) {
        List<Point3D> points = new ArrayList<>();
        points.add(new Point3D(1.0, 2.0, 3.0));
        points.add(new Point3D(4.0, 5.0, 6.0));
        Transformation transformation = new Transformation(points);
        double angle = 0.1;
        while (true) {
            transformation.rotate_x(angle);
            transformation.rotate_y(angle);
            transformation.rotate_z(angle);
            for (Point3D point : points) {
                System.out.println(point.x + ", " + point.y + ", " + point.z);
            }
        }
    }
}