import java.util.Arrays;

class Point {
    double x, y, z;

    Point(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public String toString() {
        return "Point(" + x + ", " + y + ", " + z + ")";
    }
}

class Transformation {
    Point rotate(Point point, double angle_x, double angle_y, double angle_z) {
        double cos_x = Math.cos(angle_x);
        double sin_x = Math.sin(angle_x);
        double cos_y = Math.cos(angle_y);
        double sin_y = Math.sin(angle_y);
        double cos_z = Math.cos(angle_z);
        double sin_z = Math.sin(angle_z);
        double x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z);
        double y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z);
        double z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x;
        return new Point(x, y, z);
    }

    Point translate(Point point, double dx, double dy, double dz) {
        return new Point(point.x + dx, point.y + dy, point.z + dz);
    }

    Point scale(Point point, double sx, double sy, double sz) {
        return new Point(point.x * sx, point.y * sy, point.z * sz);
    }
}

class CoordinateSystem {
    Point origin;
    Transformation transformation;

    CoordinateSystem(Point origin, Transformation transformation) {
        this.origin = origin;
        this.transformation = transformation;
    }

    Point apply_transformations(Point point, double angle_x, double angle_y, double angle_z, double dx, double dy, double dz, double sx, double sy, double sz) {
        point = transformation.rotate(point, angle_x, angle_y, angle_z);
        point = transformation.translate(point, dx, dy, dz);
        point = transformation.scale(point, sx, sy, sz);
        return point;
    }
}

public class sample_2016 {
    public static void main(String[] args) {
        Point origin = new Point(0, 0, 0);
        Transformation transformation = new Transformation();
        CoordinateSystem coordinate_system = new CoordinateSystem(origin, transformation);
        Point initial_point = new Point(1, 2, 3);
        double angle_x = 0.5, angle_y = 0.5, angle_z = 0.5;
        double dx = 1, dy = 1, dz = 1;
        double sx = 2, sy = 2, sz = 2;
        Point transformed_point = coordinate_system.apply_transformations(initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz);
        System.out.println(transformed_point);
    }
}