import java.util.List;
import java.util.Arrays;

class sample_0885 {

    static class Point3D {
        double x, y, z;

        Point3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        Point3D translate(double dx, double dy, double dz) {
            return new Point3D(this.x + dx, this.y + dy, this.z + dz);
        }

        Point3D rotate_x(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new Point3D(this.x, this.y * cos_a - this.z * sin_a, this.y * sin_a + this.z * cos_a);
        }

        Point3D rotate_y(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new Point3D(this.x * cos_a + this.z * sin_a, this.y, -this.x * sin_a + this.z * cos_a);
        }

        Point3D rotate_z(double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            return new Point3D(this.x * cos_a - this.y * sin_a, this.x * sin_a + this.y * cos_a, this.z);
        }

        @Override
        public String toString() {
            return "Point3D(" + this.x + ", " + this.y + ", " + this.z + ")";
        }
    }

    static Point3D transform_sequence(Point3D point, List<Object[]> operations, int index) {
        if (index == operations.size()) {
            return point;
        }
        String operation = (String) operations.get(index)[0];
        double[] args = (double[]) operations.get(index)[1];
        if (operation.equals("translate")) {
            point = point.translate(args[0], args[1], args[2]);
        } else if (operation.equals("rotate_x")) {
            point = point.rotate_x(args[0]);
        } else if (operation.equals("rotate_y")) {
            point = point.rotate_y(args[0]);
        } else if (operation.equals("rotate_z")) {
            point = point.rotate_z(args[0]);
        }
        return transform_sequence(point, operations, index + 1);
    }

    public static void main(String[] args) {
        Point3D point = new Point3D(1, 2, 3);
        List<Object[]> operations = Arrays.asList(
            new Object[]{"translate", new double[]{1, 1, 1}},
            new Object[]{"rotate_x", new double[]{0.785398}},
            new Object[]{"rotate_y", new double[]{0.785398}},
            new Object[]{"rotate_z", new double[]{0.785398}},
            new Object[]{"translate", new double[]{-1, -1, -1}}
        );
        Point3D final_point = transform_sequence(point, operations, 0);
        System.out.println(final_point);
    }
}