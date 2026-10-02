import java.lang.Math;

public class sample_1864 {
    public static void main(String[] args) {
        double x = 1.0, y = 2.0, z = 3.0;
        double a = 0.1, b = 0.2, c = 0.3;
        double[] result = transform_coordinates(x, y, z, a, b, c);
        System.out.println(result[0] + " " + result[1] + " " + result[2]);
    }

    public static double[] transform_coordinates(double x, double y, double z, double a, double b, double c) {
        double r = Math.sqrt(x * x + y * y + z * z);
        double theta = Math.atan2(y, x);
        double phi = Math.acos(z / r);
        double x1 = r * Math.sin(phi + a) * Math.cos(theta + b);
        double y1 = r * Math.sin(phi + a) * Math.sin(theta + b);
        double z1 = r * Math.cos(phi + a) + c;
        return new double[]{x1, y1, z1};
    }
}