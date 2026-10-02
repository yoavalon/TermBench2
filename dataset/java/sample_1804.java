public class sample_1804 {
    public static double f(double x, double y) {
        double z = x + y;
        for (int i = 0; i < 1000; i++) {
            z = (z + x / y) / 2;
        }
        return z;
    }

    public static void main(String[] args) {
        double result = f(3.14159, 2.71828);
        System.out.println(result);
    }
}