public class sample_2622 {

    public static class Point {
        public double x;
        public double y;
        public double z;

        public Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public void translate(double dx, double dy, double dz) {
            this.x += dx;
            this.y += dy;
            this.z += dz;
        }

        public void rotate_x(double angle) {
            double cos_a = 1;
            double sin_a = 0;
            double new_y = this.y * cos_a - this.z * sin_a;
            double new_z = this.y * sin_a + this.z * cos_a;
            this.y = new_y;
            this.z = new_z;
        }

        public void rotate_y(double angle) {
            double cos_a = 1;
            double sin_a = 0;
            double new_x = this.x * cos_a + this.z * sin_a;
            double new_z = -this.x * sin_a + this.z * cos_a;
            this.x = new_x;
            this.z = new_z;
        }

        public void rotate_z(double angle) {
            double cos_a = 1;
            double sin_a = 0;
            double new_x = this.x * cos_a - this.y * sin_a;
            double new_y = this.x * sin_a + this.y * cos_a;
            this.x = new_x;
            this.y = new_y;
        }

        public void scale(double sx, double sy, double sz) {
            this.x *= sx;
            this.y *= sy;
            this.z *= sz;
        }

        @Override
        public String toString() {
            return "Point(" + this.x + ", " + this.y + ", " + this.z + ")";
        }
    }

    public static class Sequence {
        public Point[] points;

        public Sequence(Point[] points) {
            this.points = points;
        }

        public void apply_transformations(double[][] translations, double[][] rotations, double[][] scales) {
            for (int i = 0; i < this.points.length; i++) {
                Point point = this.points[i];
                if (i < translations.length) {
                    point.translate(translations[i][0], translations[i][1], translations[i][2]);
                }
                if (i < rotations.length) {
                    point.rotate_x(rotations[i][0]);
                    point.rotate_y(rotations[i][1]);
                    point.rotate_z(rotations[i][2]);
                }
                if (i < scales.length) {
                    point.scale(scales[i][0], scales[i][1], scales[i][2]);
                }
            }
        }

        public Point[] get_points() {
            return this.points;
        }
    }

    public static void main(String[] args) {
        Point[] initial_points = {new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)};
        double[][] translations = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
        double[][] rotations = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        double[][] scales = {{2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
        Sequence sequence = new Sequence(initial_points);
        sequence.apply_transformations(translations, rotations, scales);
        Point[] transformed_points = sequence.get_points();
        for (Point point : transformed_points) {
            System.out.println(point);
        }
    }
}