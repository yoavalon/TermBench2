import java.lang.Math;

class Transformation {
    double x, y, z;

    Transformation(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Transformation rotate(double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double new_x = this.x * cos_a - this.y * sin_a;
        double new_y = this.x * sin_a + this.y * cos_a;
        this.x = new_x;
        this.y = new_y;
        return this;
    }

    Transformation translate(double dx, double dy, double dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
        return this;
    }

    Transformation scale(double sx, double sy, double sz) {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
        return this;
    }
}

public class sample_2354 {
    public static Transformation transform_sequence(Transformation obj, double[] rotations, double[][] translations, double[][] scales) {
        for (double angle : rotations) {
            obj.rotate(angle);
        }
        for (double[] translation : translations) {
            obj.translate(translation[0], translation[1], translation[2]);
        }
        for (double[] scale : scales) {
            obj.scale(scale[0], scale[1], scale[2]);
        }
        return obj;
    }

    public static void main(String[] args) {
        Transformation obj = new Transformation(1.0, 2.0, 3.0);
        double[] rotations = {0.1, 0.2, 0.3};
        double[][] translations = {{0.5, 0.5, 0.5}, {1.0, 1.0, 1.0}};
        double[][] scales = {{1.5, 1.5, 1.5}, {2.0, 2.0, 2.0}};
        while (true) {
            Transformation transformed_obj = transform_sequence(obj, rotations, translations, scales);
            System.out.println("Transformed coordinates: (" + transformed_obj.x + ", " + transformed_obj.y + ", " + transformed_obj.z + ")");
        }
    }
}