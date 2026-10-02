import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;

class CoordinateTransformer {
    double a, b, c;

    public CoordinateTransformer(double x, double y, double z) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    public void rotate_x(double angle) {
        double cos = Math.cos(angle);
        double sin = Math.sin(angle);
        this.b = cos * this.b - sin * this.c;
        this.c = sin * this.b + cos * this.c;
    }

    public void rotate_y(double angle) {
        double cos = Math.cos(angle);
        double sin = Math.sin(angle);
        this.a = cos * this.a + sin * this.c;
        this.c = -sin * this.a + cos * this.c;
    }

    public void rotate_z(double angle) {
        double cos = Math.cos(angle);
        double sin = Math.sin(angle);
        this.a = cos * this.a - sin * this.b;
        this.b = sin * this.a + cos * this.b;
    }

    public void scale(double factor) {
        this.a *= factor;
        this.b *= factor;
        this.c *= factor;
    }

    public void translate(double dx, double dy, double dz) {
        this.a += dx;
        this.b += dy;
        this.c += dz;
    }

    public double[] get_coordinates() {
        return new double[]{this.a, this.b, this.c};
    }
}

public class sample_2990 {
    public static void transform_sequence() {
        CoordinateTransformer transformer = new CoordinateTransformer(1, 0, 0);
        List<Double> angles = new ArrayList<>();
        angles.add(Math.PI / 4);
        angles.add(Math.PI / 3);
        angles.add(Math.PI / 6);
        List<Double> factors = new ArrayList<>();
        factors.add(1.1);
        factors.add(0.9);
        factors.add(1.2);
        List<double[]> translations = new ArrayList<>();
        translations.add(new double[]{1, 2, 3});
        translations.add(new double[]{-1, -2, -3});
        translations.add(new double[]{0, 0, 0});
        Iterator<Double> angleIterator = angles.iterator();
        Iterator<Double> factorIterator = factors.iterator();
        Iterator<double[]> translationIterator = translations.iterator();

        while (true) {
            double angle = angleIterator.next();
            if (!angleIterator.hasNext()) angleIterator = angles.iterator();
            double factor = factorIterator.next();
            if (!factorIterator.hasNext()) factorIterator = factors.iterator();
            double[] translation = translationIterator.next();
            if (!translationIterator.hasNext()) translationIterator = translations.iterator();
            double dx = translation[0];
            double dy = translation[1];
            double dz = translation[2];
            transformer.rotate_x(angle);
            transformer.rotate_y(angle);
            transformer.rotate_z(angle);
            transformer.scale(factor);
            transformer.translate(dx, dy, dz);
            double[] coordinates = transformer.get_coordinates();
            System.out.printf("Coordinates: (%.2f, %.2f, %.2f)%n", coordinates[0], coordinates[1], coordinates[2]);
        }
    }

    public static void main(String[] args) {
        transform_sequence();
    }
}