public class sample_2370 {

    static class Transformation {
        double a, b, c, d, e, f, g, h, i;

        Transformation(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
            this.e = e;
            this.f = f;
            this.g = g;
            this.h = h;
            this.i = i;
        }

        double[] apply(double x, double y, double z) {
            double[] result = new double[3];
            result[0] = a * x + b * y + c * z + d;
            result[1] = e * x + f * y + g * z + h;
            result[2] = i * x + g * y + e * z + f;
            return result;
        }
    }

    static class Coordinate {
        double x, y, z;

        Coordinate(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        void update(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    static void transform_coordinate(Coordinate coord, Transformation trans) {
        double[] result = trans.apply(coord.x, coord.y, coord.z);
        coord.update(result[0], result[1], result[2]);
    }

    public static void main(String[] args) {
        Coordinate coord = new Coordinate(1.0, 2.0, 3.0);
        Transformation trans = new Transformation(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
        while (true) {
            transform_coordinate(coord, trans);
            System.out.println(coord.x + " " + coord.y + " " + coord.z);
        }
    }
}