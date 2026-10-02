import java.util.ArrayList;
import java.util.List;

class Coordinate {
    double x, y, z;

    Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    double distance_to(Coordinate other) {
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        double dz = this.z - other.z;
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }
}

class Transformation {
    double angle;
    Coordinate axis;

    Transformation(double angle, Coordinate axis) {
        this.angle = angle;
        this.axis = axis;
    }

    Coordinate rotate(Coordinate point) {
        double x = point.x, y = point.y, z = point.z;
        double u = axis.x, v = axis.y, w = axis.z;
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double norm = Math.sqrt(u * u + v * v + w * w);
        u /= norm;
        v /= norm;
        w /= norm;
        double x_new = (u * u + (1 - u * u) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z;
        double y_new = (u * v * (1 - cos_a) + w * sin_a) * x + (v * v + (1 - v * v) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z;
        double z_new = (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w * w + (1 - w * w) * cos_a) * z;
        return new Coordinate(x_new, y_new, z_new);
    }
}

public class sample_2309 {
    static List<Coordinate> transform_sequence(List<Coordinate> points, List<Transformation> transformations) {
        List<Coordinate> transformed_points = new ArrayList<>();
        for (Coordinate point : points) {
            for (Transformation transform : transformations) {
                point = transform.rotate(point);
            }
            transformed_points.add(point);
        }
        return transformed_points;
    }

    public static void main(String[] args) {
        List<Coordinate> points = List.of(new Coordinate(1.0, 2.0, 3.0), new Coordinate(4.0, 5.0, 6.0));
        List<Transformation> transformations = List.of(
            new Transformation(Math.PI / 4, new Coordinate(1, 0, 0)),
            new Transformation(Math.PI / 4, new Coordinate(0, 1, 0)),
            new Transformation(Math.PI / 4, new Coordinate(0, 0, 1))
        );
        while (true) {
            List<Coordinate> transformed_points = transform_sequence(points, transformations);
            for (Coordinate point : transformed_points) {
                System.out.printf("(%f, %f, %f)%n", point.x, point.y, point.z);
            }
            points = transformed_points;
        }
    }
}