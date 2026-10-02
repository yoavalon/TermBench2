import java.util.List;

public class sample_0287 {
    static class CoordinateTransformer {
        double a, b, c;

        CoordinateTransformer(double x, double y, double z) {
            this.a = x;
            this.b = y;
            this.c = z;
        }

        void rotate(double theta) {
            double cosTheta = Math.cos(theta);
            double sinTheta = Math.sin(theta);
            this.a = this.a * cosTheta - this.b * sinTheta;
            this.b = this.a * sinTheta + this.b * cosTheta;
        }

        void scale(double factor) {
            this.a *= factor;
            this.b *= factor;
            this.c *= factor;
        }

        void translate(double dx, double dy, double dz) {
            this.a += dx;
            this.b += dy;
            this.c += dz;
        }
    }

    static void applyTransformations(CoordinateTransformer obj, List<Double> rotations, List<Double> scales, List<double[]> translations) {
        for (double angle : rotations) {
            obj.rotate(angle);
        }
        for (double factor : scales) {
            obj.scale(factor);
        }
        for (double[] translation : translations) {
            obj.translate(translation[0], translation[1], translation[2]);
        }
    }

    public static void main(String[] args) {
        CoordinateTransformer obj = new CoordinateTransformer(1, 2, 3);
        List<Double> rotations = List.of(0.1, 0.2, 0.3);
        List<Double> scales = List.of(1.5, 2.0, 2.5);
        List<double[]> translations = List.of(new double[]{1, 1, 1}, new double[]{2, 2, 2}, new double[]{3, 3, 3});
        applyTransformations(obj, rotations, scales, translations);
        System.out.println(obj.a + " " + obj.b + " " + obj.c);
    }
}