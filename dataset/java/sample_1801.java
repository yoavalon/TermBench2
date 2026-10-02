public class sample_1801 {
    public static void main(String[] args) {
        double x = 1.0, y = 2.0, z = 3.0, a = 4.0, b = 5.0, c = 6.0;
        double[] result = transform_coordinates(x, y, z, a, b, c);
        System.out.println("Transformed coordinates: (" + result[0] + ", " + result[1] + ", " + result[2] + ")");
    }

    public static double[] transform_coordinates(double x, double y, double z, double a, double b, double c) {
        double x_new = x + a;
        double y_new = y + b;
        double z_new = z + c;
        return new double[]{x_new, y_new, z_new};
    }
}