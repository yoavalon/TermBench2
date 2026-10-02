import java.util.ArrayList;
import java.util.List;

public class sample_2985 {

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

        void rotate(double rx, double ry, double rz) {
            double cos_rx = Math.cos(rx);
            double sin_rx = Math.sin(rx);
            double cos_ry = Math.cos(ry);
            double sin_ry = Math.sin(ry);
            double cos_rz = Math.cos(rz);
            double sin_rz = Math.sin(rz);
            double x = this.x;
            double y = this.y;
            double z = this.z;
            this.x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z;
            this.y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y);
            this.z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y);
        }
    }

    static void transform_sequence(Point point, List<Object[]> transformations) {
        for (Object[] transform : transformations) {
            String transform_type = (String) transform[0];
            double[] params = (double[]) transform[1];
            if (transform_type.equals("translate")) {
                point.translate(params[0], params[1], params[2]);
            } else if (transform_type.equals("scale")) {
                point.scale(params[0], params[1], params[2]);
            } else if (transform_type.equals("rotate")) {
                point.rotate(params[0], params[1], params[2]);
            }
        }
    }

    public static void main(String[] args) {
        Point p = new Point(1, 0, 0);
        List<Object[]> transformations = new ArrayList<>();
        transformations.add(new Object[]{"translate", new double[]{1, 1, 1}});
        transformations.add(new Object[]{"scale", new double[]{2, 2, 2}});
        transformations.add(new Object[]{"rotate", new double[]{0.5, 0.5, 0.5}});
        transformations.add(new Object[]{"translate", new double[]{1, 1, 1}});
        transformations.add(new Object[]{"scale", new double[]{0.5, 0.5, 0.5}});
        transformations.add(new Object[]{"rotate", new double[]{-0.5, -0.5, -0.5}});

        while (true) {
            transform_sequence(p, transformations);
            System.out.println("Current position: (" + p.x + ", " + p.y + ", " + p.z + ")");
        }
    }
}