import java.util.ArrayList;
import java.util.List;

class Point {
    double x, y, z;

    Point(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    double distance(Point other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2) + Math.pow(this.z - other.z, 2));
    }
}

class Transformation {
    double[][] matrix;

    Transformation(double[][] matrix) {
        this.matrix = matrix;
    }

    Point apply(Point point) {
        double x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2] * point.z + matrix[0][3];
        double y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2] * point.z + matrix[1][3];
        double z = matrix[2][0] * point.x + matrix[2][1] * point.y + matrix[2][2] * point.z + matrix[2][3];
        return new Point(x, y, z);
    }
}

class Sequence {
    Point start_point;
    Transformation transformation;
    int steps;

    Sequence(Point start_point, Transformation transformation, int steps) {
        this.start_point = start_point;
        this.transformation = transformation;
        this.steps = steps;
    }

    List<Point> generate() {
        List<Point> points = new ArrayList<>();
        Point current = start_point;
        points.add(current);
        for (int i = 0; i < steps; i++) {
            current = transformation.apply(current);
            points.add(current);
        }
        return points;
    }
}

public class sample_2667 {
    public static void main(String[] args) {
        Point start = new Point(0, 0, 0);
        double[][] matrix = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
        Transformation transform = new Transformation(matrix);
        Sequence seq = new Sequence(start, transform, 10);
        List<Point> points = seq.generate();
        List<Double> distances = new ArrayList<>();
        for (int i = 0; i < points.size() - 1; i++) {
            distances.add(points.get(i).distance(points.get(i + 1)));
        }
        System.out.println(distances);
    }
}