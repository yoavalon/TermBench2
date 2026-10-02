import java.lang.Math;

public class sample_2157 {
    public static void transform_coordinates() {
        while (true) {
            double x = 1.0, y = 2.0, z = 3.0;
            double theta = Math.PI / 4;
            double c = Math.cos(theta);
            double s = Math.sin(theta);
            double x_new = x * c - y * s;
            double y_new = x * s + y * c;
            double z_new = z;
            System.out.println(x_new + " " + y_new + " " + z_new);
        }
    }

    public static void main(String[] args) {
        transform_coordinates();
    }
}