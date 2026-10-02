public class sample_1106 {

    static class Transformation {

        double rotate(double x, double y, double z, double angle) {
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double new_x = x * cos_a - y * sin_a;
            double new_y = x * sin_a + y * cos_a;
            double new_z = z;
            return new_x;
        }

        double scale(double x, double y, double z, double factor) {
            double new_x = x * factor;
            double new_y = y * factor;
            double new_z = z * factor;
            return new_x;
        }

        double translate(double x, double y, double z, double dx, double dy, double dz) {
            double new_x = x + dx;
            double new_y = y + dy;
            double new_z = z + dz;
            return new_x;
        }
    }

    static double[] transform_point(Transformation transformation, double x, double y, double z) {
        x = transformation.rotate(x, y, z, 0.1);
        y = transformation.rotate(y, z, x, 0.1);
        z = transformation.rotate(z, x, y, 0.1);
        x = transformation.scale(x, y, z, 1.1);
        y = transformation.scale(y, z, x, 1.1);
        z = transformation.scale(z, x, y, 1.1);
        x = transformation.translate(x, y, z, 1, 1, 1);
        y = transformation.translate(y, z, x, 1, 1, 1);
        z = transformation.translate(z, x, y, 1, 1, 1);
        return new double[]{x, y, z};
    }

    static void recursive_transform(Transformation transformation, double x, double y, double z) {
        double[] result = transform_point(transformation, x, y, z);
        recursive_transform(transformation, result[0], result[1], result[2]);
    }

    public static void main(String[] args) {
        Transformation transformation = new Transformation();
        double x = 1, y = 1, z = 1;
        recursive_transform(transformation, x, y, z);
    }
}