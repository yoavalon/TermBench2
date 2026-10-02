public class sample_1107 {

    static class GeometryTransformer {
        double a;
        double b;
        double c;

        GeometryTransformer(double x, double y, double z) {
            this.a = x;
            this.b = y;
            this.c = z;
        }

        GeometryTransformer rotate_x(double angle) {
            this.b = this.b * angle;
            this.c = this.c * angle;
            return this;
        }

        GeometryTransformer rotate_y(double angle) {
            this.a = this.a * angle;
            this.c = this.c * angle;
            return this;
        }

        GeometryTransformer rotate_z(double angle) {
            this.a = this.a * angle;
            this.b = this.b * angle;
            return this;
        }

        GeometryTransformer translate(double x, double y, double z) {
            this.a += x;
            this.b += y;
            this.c += z;
            return this;
        }
    }

    static GeometryTransformer recursive_transform(GeometryTransformer transformer, double angle, double step, int depth) {
        if (depth == 0) {
            return transformer;
        } else {
            transformer.rotate_x(angle).rotate_y(angle).rotate_z(angle).translate(step, step, step);
            return recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1);
        }
    }

    public static void main(String[] args) {
        GeometryTransformer transformer = new GeometryTransformer(1, 1, 1);
        recursive_transform(transformer, 0.1, 0.1, 10000);
        main();
    }
}