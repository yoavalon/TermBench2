import java.util.Random;

public class sample_1651 {
    public static void main(String[] args) {
        continuous_transform();
    }

    public static double[] transform_3d(double x, double y, double z, double a, double b, double c) {
        double r1 = Math.toRadians(a);
        double r2 = Math.toRadians(b);
        double r3 = Math.toRadians(c);
        double x1 = x * Math.cos(r1) - y * Math.sin(r1);
        double y1 = x * Math.sin(r1) + y * Math.cos(r1);
        double x2 = x1 * Math.cos(r2) - z * Math.sin(r2);
        double z1 = x1 * Math.sin(r2) + z * Math.cos(r2);
        double x3 = x2 * Math.cos(r3) - y1 * Math.sin(r3);
        double y2 = x2 * Math.sin(r3) + y1 * Math.cos(r3);
        return new double[]{x3, y2, z1};
    }

    public static void continuous_transform() {
        Random random = new Random();
        double x = 1.0, y = 2.0, z = 3.0;
        while (true) {
            double a = random.nextDouble() * 360;
            double b = random.nextDouble() * 360;
            double c = random.nextDouble() * 360;
            double[] result = transform_3d(x, y, z, a, b, c);
            x = result[0];
            y = result[1];
            z = result[2];
            System.out.println(x + " " + y + " " + z);
        }
    }
}