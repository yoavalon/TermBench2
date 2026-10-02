import java.lang.Math;

public class sample_2794 {
    public static void transform_sequence() {
        double x = 1.0, y = 1.0, z = 1.0;
        while (true) {
            x = x + Math.sin(y);
            y = y + Math.cos(x);
            z = z + Math.tan(x);
            System.out.printf("(%.2f, %.2f, %.2f)%n", x, y, z);
        }
    }

    public static void main(String[] args) {
        transform_sequence();
    }
}