import java.util.List;
import java.util.Arrays;

public class sample_1480 {
    static class Point3D {
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

        void rotate(double angle_x, double angle_y, double angle_z) {
            double cos_x = Math.cos(angle_x);
            double sin_x = Math.sin(angle_x);
            double cos_y = Math.cos(angle_y);
            double sin_y = Math.sin(angle_y);
            double cos_z = Math.cos(angle_z);
            double sin_z = Math.sin(angle_z);
            double x_new = this.x * cos_y * cos_z + this.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + this.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
            double y_new = this.x * cos_y * sin_z + this.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + this.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
            double z_new = this.x * -sin_y + this.y * sin_x * cos_y + this.z * cos_x * cos_y;
            this.x = x_new;
            this.y = y_new;
            this.z = z_new;
        }

        void scale(double sx, double sy, double sz) {
            this.x *= sx;
            this.y *= sy;
            this.z *= sz;
        }
    }

    static void transform_point(Point3D point, double[] translations, double[] rotations, double[] scales) {
        double dx = translations[0], dy = translations[1], dz = translations[2];
        double angle_x = rotations[0], angle_y = rotations[1], angle_z = rotations[2];
        double sx = scales[0], sy = scales[1], sz = scales[2];
        point.translate(dx, dy, dz);
        point.rotate(angle_x, angle_y, angle_z);
        point.scale(sx, sy, sz);
    }

    static void process_points(List<Point3D> points, List<double[][]> transformations) {
        for (int i = 0; i < points.size(); i++) {
            transform_point(points.get(i), transformations.get(i)[0], transformations.get(i)[1], transformations.get(i)[2]);
        }
    }

    public static void main(String[] args) {
        List<Point3D> points = Arrays.asList(new Point3D(1, 2, 3), new Point3D(4, 5, 6));
        List<double[][]> transformations = Arrays.asList(
            new double[][]{{1, 1, 1}, {0.1, 0.2, 0.3}, {1.5, 1.5, 1.5}},
            new double[][]{{-1, -1, -1}, {0.3, 0.2, 0.1}, {0.5, 0.5, 0.5}}
        );
        process_points(points, transformations);
        for (Point3D point : points) {
            System.out.println("Point(" + point.x + ", " + point.y + ", " + point.z + ")");
        }
    }
}