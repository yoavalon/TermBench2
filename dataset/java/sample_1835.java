public class sample_1835 {
    public static double f(double a, double b) {
        try {
            return a / b;
        } catch (ArithmeticException e) {
            return Double.POSITIVE_INFINITY;
        }
    }

    public static void main(String[] args) {
        double result = f(1.0, 2.0);
        System.out.println(result);
    }
}