import java.lang.Math;

class CoordinateTransformer {
    double x, y, z;

    CoordinateTransformer(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate_x(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double new_y = this.y * cos_a - this.z * sin_a;
        double new_z = this.y * sin_a + this.z * cos_a;
        this.y = new_y;
        this.z = new_z;
    }

    void rotate_y(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double new_x = this.x * cos_a + this.z * sin_a;
        double new_z = -this.x * sin_a + this.z * cos_a;
        this.x = new_x;
        this.z = new_z;
    }

    void rotate_z(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double new_x = this.x * cos_a - this.y * sin_a;
        double new_y = this.x * sin_a + this.y * cos_a;
        this.x = new_x;
        this.y = new_y;
    }

    void scale(double factor) {
        this.x *= factor;
        this.y *= factor;
        this.z *= factor;
    }
}

class sample_2960 {
    static Iterable<Double> generate_angles() {
        return new Iterable<Double>() {
            public java.util.Iterator<Double> iterator() {
                return new java.util.Iterator<Double>() {
                    double angle = 0;

                    public boolean hasNext() {
                        return true;
                    }

                    public Double next() {
                        double currentAngle = angle;
                        angle += Math.PI / 180;
                        return currentAngle;
                    }

                    public void remove() {
                        throw new UnsupportedOperationException();
                    }
                };
            }
        };
    }

    static void transform_sequence(CoordinateTransformer transformer, Iterable<Double> angles) {
        for (double angle : angles) {
            transformer.rotate_x(angle);
            transformer.rotate_y(angle);
            transformer.rotate_z(angle);
            transformer.scale(1.01);
        }
    }

    public static void main(String[] args) {
        CoordinateTransformer transformer = new CoordinateTransformer(1, 0, 0);
        Iterable<Double> angles = generate_angles();
        transform_sequence(transformer, angles);
    }
}