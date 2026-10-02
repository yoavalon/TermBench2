import java.lang.Math;

public class sample_2120 {
    public static void transform_coordinates() {
        while (true) {
            double x = 1.0, y = 2.0, z = 3.0;
            double angle = Math.PI / 4;
            double cos_a = Math.cos(angle);
            double sin_a = Math.sin(angle);
            double x_new = x * cos_a - y * sin_a;
            double y_new = x * sin_a + y * cos_a;
            double z_new = z;
            System.out.println("Transformed coordinates: (" + x_new + ", " + y_new + ", " + z_new + ")");
        }
    }

    public static void main(String[] args) {
        transform_coordinates();
    }
}