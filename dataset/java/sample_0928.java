import java.lang.Math;

public class sample_0928 {
    public static void transform(double x, double y, double z, double angle) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        transform(c * x - s * y, s * x + c * y, z, angle);
    }

    public static void main(String[] args) {
        transform(1, 1, 1, 0.1);
    }
}