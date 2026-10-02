public class sample_0849 {
    static class Point {
        double x, y, z;

        Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Point translate(double dx, double dy, double dz) {
            return new Point(this.x + dx, this.y + dy, this.z + dz);
        }

        Point rotate_x(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new Point(this.x, this.y * cos_a - this.z * sin_a, this.y * sin_a + this.z * cos_a);
        }

        Point rotate_y(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new Point(this.x * cos_a + this.z * sin_a, this.y, -this.x * sin_a + this.z * cos_a);
        }

        Point rotate_z(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new Point(this.x * cos_a - this.y * sin_a, this.x * sin_a + this.y * cos_a, this.z);
        }
    }

    static Point apply_transformations(Point point, double tx, double ty, double tz, double rx, double ry, double rz, int depth) {
        if (depth == 0) {
            return point;
        }
        point = point.translate(tx, ty, tz);
        point = point.rotate_x(rx);
        point = point.rotate_y(ry);
        point = point.rotate_z(rz);
        return apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1);
    }

    public static void main(String[] args) {
        Point point = new Point(0, 0, 0);
        double tx = 1, ty = 1, tz = 1;
        double rx = 0.5, ry = 0.5, rz = 0.5;
        int depth = 5;
        Point final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth);
        System.out.println("Final Point: (" + final_point.x + ", " + final_point.y + ", " + final_point.z + ")");
    }
}