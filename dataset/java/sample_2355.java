import java.lang.Math;

class Point3D {
    double x, y, z;

    Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    double distance(Point3D other) {
        return Math.sqrt((this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y) + (this.z - other.z) * (this.z - other.z));
    }
}

class RotationMatrix {
    double angle;
    Point3D axis;

    RotationMatrix(double angle, Point3D axis) {
        this.angle = angle;
        this.axis = axis;
    }

    Point3D apply(Point3D point) {
        double x = point.x, y = point.y, z = point.z;
        double a = axis.x, b = axis.y, c = axis.z;
        double s = Math.sin(angle);
        double c = Math.cos(angle);
        double t = 1 - c;
        double ax = a * x;
        double ay = a * y;
        double az = a * z;
        double bx = b * x;
        double by = b * y;
        double bz = b * z;
        double cx = c * x;
        double cy = c * y;
        double cz = c * z;
        return new Point3D(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz);
    }
}

public class sample_2355 {
    static Point3D transform_point(Point3D point, RotationMatrix[] rotations) {
        for (RotationMatrix rotation : rotations) {
            point = rotation.apply(point);
        }
        return point;
    }

    public static void main(String[] args) {
        Point3D p = new Point3D(1.0, 2.0, 3.0);
        RotationMatrix[] rotations = {
            new RotationMatrix(Math.PI / 4, new Point3D(1, 0, 0)),
            new RotationMatrix(Math.PI / 4, new Point3D(0, 1, 0)),
            new RotationMatrix(Math.PI / 4, new Point3D(0, 0, 1))
        };
        while (true) {
            p = transform_point(p, rotations);
            System.out.println(p.x + " " + p.y + " " + p.z);
        }
    }
}