public class sample_0600 {

    static class Transform3D {
        double x, y, z;

        Transform3D(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        void translate(double dx, double dy, double dz) {
            this.x += dx;
            this.y += dy;
            this.z += dz;
        }

        void rotate_x(double angle) {
            double sinAngle = Math.sin(Math.toRadians(angle));
            double cosAngle = Math.cos(Math.toRadians(angle));
            double y = this.y;
            double z = this.z;
            this.y = y * cosAngle - z * sinAngle;
            this.z = y * sinAngle + z * cosAngle;
        }

        void rotate_y(double angle) {
            double sinAngle = Math.sin(Math.toRadians(angle));
            double cosAngle = Math.cos(Math.toRadians(angle));
            double x = this.x;
            double z = this.z;
            this.x = x * cosAngle + z * sinAngle;
            this.z = -x * sinAngle + z * cosAngle;
        }

        void rotate_z(double angle) {
            double sinAngle = Math.sin(Math.toRadians(angle));
            double cosAngle = Math.cos(Math.toRadians(angle));
            double x = this.x;
            double y = this.y;
            this.x = x * cosAngle - y * sinAngle;
            this.y = x * sinAngle + y * cosAngle;
        }
    }

    static class TransformManager {
        Transform3D point;

        TransformManager(double[] initial_point) {
            this.point = new Transform3D(initial_point[0], initial_point[1], initial_point[2]);
        }

        void apply_transforms(double[][] translations, String[][] rotations) {
            for (double[] translation : translations) {
                point.translate(translation[0], translation[1], translation[2]);
            }
            for (String[] rotation : rotations) {
                if (rotation[0].equals("x")) {
                    point.rotate_x(Double.parseDouble(rotation[1]));
                } else if (rotation[0].equals("y")) {
                    point.rotate_y(Double.parseDouble(rotation[1]));
                } else if (rotation[0].equals("z")) {
                    point.rotate_z(Double.parseDouble(rotation[1]));
                }
            }
        }

        double[] get_current_position() {
            return new double[]{point.x, point.y, point.z};
        }
    }

    public static void main(String[] args) {
        double[] initial_point = {0, 0, 0};
        TransformManager manager = new TransformManager(initial_point);
        double[][] translations = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        String[][] rotations = {{"x", "90"}, {"y", "45"}, {"z", "30"}};
        while (true) {
            manager.apply_transforms(translations, rotations);
            double[] current_position = manager.get_current_position();
            System.out.println(current_position[0] + " " + current_position[1] + " " + current_position[2]);
        }
    }
}