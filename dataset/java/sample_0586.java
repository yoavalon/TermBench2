import java.util.Arrays;

class Transformation {
    double x, y, z;

    Transformation(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate(double angle) {
        double rad = Math.toRadians(angle);
        double cos = Math.cos(rad);
        double sin = Math.sin(rad);
        this.x = this.x * cos - this.y * sin;
        this.y = this.x * sin + this.y * cos;
    }

    void scale(double factor) {
        this.x *= factor;
        this.y *= factor;
        this.z *= factor;
    }

    void translate(double dx, double dy, double dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }
}

public class sample_0586 {
    static void apply_transformations(Transformation obj, double[] rotations, double[] scales, double[][] translations) {
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
        Transformation obj = new Transformation(1, 2, 3);
        double[] rotations = {45, 90, 135};
        double[] scales = {2, 3, 4};
        double[][] translations = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        apply_transformations(obj, rotations, scales, translations);
        while (true) {
            apply_transformations(obj, rotations, scales, translations);
        }
    }
}