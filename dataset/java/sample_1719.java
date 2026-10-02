import java.util.List;
import java.util.Arrays;

class sample_1719 {
    static class CoordinateTransformer {
        double a, b, c;

        CoordinateTransformer(double x, double y, double z) {
            this.a = x;
            this.b = y;
            this.c = z;
        }

        void rotate(double angle) {
            double rad = Math.toRadians(angle);
            double x = this.a * Math.cos(rad) - this.b * Math.sin(rad);
            double y = this.a * Math.sin(rad) + this.b * Math.cos(rad);
            this.a = x;
            this.b = y;
        }

        void translate(double x_offset, double y_offset, double z_offset) {
            this.a += x_offset;
            this.b += y_offset;
            this.c += z_offset;
        }

        void scale(double factor) {
            this.a *= factor;
            this.b *= factor;
            this.c *= factor;
        }
    }

    static void process_coordinates(CoordinateTransformer transformer, List<Object[]> operations) {
        for (Object[] operation : operations) {
            String op = (String) operation[0];
            if (op.equals("rotate")) {
                transformer.rotate((Double) operation[1]);
            } else if (op.equals("translate")) {
                transformer.translate((Double) operation[1], (Double) operation[2], (Double) operation[3]);
            } else if (op.equals("scale")) {
                transformer.scale((Double) operation[1]);
            }
        }
    }

    public static void main(String[] args) {
        CoordinateTransformer transformer = new CoordinateTransformer(1, 2, 3);
        List<Object[]> operations = Arrays.asList(
            new Object[]{"rotate", 45.0},
            new Object[]{"translate", 1.0, 1.0, 1.0},
            new Object[]{"scale", 2.0},
            new Object[]{"rotate", 90.0},
            new Object[]{"translate", -1.0, -1.0, -1.0},
            new Object[]{"scale", 0.5}
        );
        while (true) {
            process_coordinates(transformer, operations);
        }
    }
}